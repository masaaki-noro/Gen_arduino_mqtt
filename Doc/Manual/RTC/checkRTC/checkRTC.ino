/*
 * 起動時にRTCに設定されている時刻が正しいものか否かを確認して，必要なら時刻を設定の上で毎秒現在時刻をシリアルに出力する
 */
#include "config.h"

/*
 * 時刻情報の出力
 */
void printTime(date_t * date){
  Serial.print(date->year);Serial.print("/");Serial.print(date->month);Serial.print("/");Serial.print(date->mday);Serial.print(" ");
  switch(date->wday) {
    case SUN : Serial.print("SUN");break;
    case MON : Serial.print("MON");break;
    case TUE : Serial.print("TUE");break;
    case WED : Serial.print("WED");break;
    case THU : Serial.print("THU");break;
    case FRI : Serial.print("FRI");break;
    case SAT : Serial.print("SAT");break;
  }
  Serial.print(" ");
  Serial.print(date->hour);Serial.print(":");Serial.print(date->minute);Serial.print(":");Serial.print(date->second);
  Serial.println("");
}

/*
 * rtcの時刻レジスタの設定が正しいものになっているか否かを確認
 */
#define TIME_IS_VALID 1
#define TIME_IS_INVALID 0
/*
 * EPSON 4543
 * checkLowPowerの出力(FDTビット)
 *    0: 電圧低下なし 1:電圧低下あり
 */
int timeValidity_4543(void) {
#if 0
  int flag=rtc.checkLowPower();
  if (flag < 0) return flag;
  if (0==flag) return TIME_IS_VALID;
#endif
  return TIME_IS_INVALID;
}
/*
 * EPSON 8564
 * checkLowPowerの出力 : 秒レジスタ(0x02)のVLビット(bit 7)
 *   0: 電圧低下なし 1:電圧低下あり
 */
int timeValidity_8564() {
  int flag=rtc.checkLowPower();
  if (flag < 0) return flag;
  if (0==flag) return TIME_IS_VALID;
  return TIME_IS_INVALID;
}
/*
 * EPSON RX8025
 * checkLowPowerの出力 : ctrl2レジスタの4～6bit目の値
 *   0b010以外の場合は電圧低下などの問題が発生したことを示す
 */
int timeValidity_RX8025() {
  int flag=rtc.checkLowPower();
  if (flag < 0) return flag;
  if (0b010==flag) return TIME_IS_VALID;
  return TIME_IS_INVALID;
}
/*
 * EPSON RX8900
 * checkLowPowerの出力 : flagレジスタの0,1bit目の値
 *  0b00以外は電圧低下などの問題が発生
 */
int timeValidity_RX8900() {
  int flag=rtc.checkLowPower();
  if (flag < 0) return flag;
  if (0b00==flag) return TIME_IS_VALID;
  return TIME_IS_INVALID;
}
/*
 * Micro Crystal RV8803
 * checkLowPowerの出力 : フラグレジスタ(0x0E)の下位2bit分
 *  0b00以外は電圧低下などの問題が発生
 */
int timeValidity_RV8803() {
  int flag=rtc.checkLowPower();
  if (flag < 0) return flag;
  if (0b00==flag) return TIME_IS_VALID;
  return TIME_IS_INVALID;
}
/*
 * NXP PCF8523
 * checkLowPowerの出力 : 情報の取得に成功した場合の返り値の内容は以下の通り．
 * 大まかには，7bit目が1の場合はなんらかの異常があり，その詳しい内容が0から3bit目に出力されている．
 *   | bit    | 名前 | 内容 |
 *   |--------|---|---|
 *   | 7      | OS | 秒レジスタ(0x03)の7bitのデータ |
 *   | 4から6 |    | 未使用 |
 *   | 0から3 |    | Control 3レジスタ(0x02)の0から3bit目のデータ |
 */
int timeValidity_PCF8523() {
  int flag=rtc.checkLowPower();
  if (flag < 0) return flag;
  flag = flag & 0b10000000;
  if (0==flag) return TIME_IS_VALID;
  return TIME_IS_INVALID;
}

/*
 * MAXIM DS3231
 * checkLowPowerの出力
 *    0: 電圧低下なし 1:電圧低下あり
 */
int timeValidity_DS3231() {
  int flag=rtc.checkLowPower();
  if (flag < 0) return flag;
  if (0==flag) return TIME_IS_VALID;
  return TIME_IS_INVALID;
}
/*
 * MAXIM DS3234
 * checkLowPowerの出力
 *    0: 電圧低下なし 1:電圧低下あり
 */
int timeValidity_DS3234() {
  int flag=rtc.checkLowPower();
  if (flag < 0) return flag;
  if (0==flag) return TIME_IS_VALID;
  return TIME_IS_INVALID;
}
/*
 * MAXIM DS1307
 * clockHaltStatusの出力
 *    0: 電圧低下などなく，時計は進んでいる  1: 電圧低下も含めてクロックが止まっている
 */
int timeValidity_DS1307() {
  int flag=rtc.checkLowPower();
  if (flag < 0) return flag;
  if (0==flag) return TIME_IS_INVALID;
  return TIME_IS_VALID;
}

int timeValidity(void) {
  rtc_u_info_t rtcInfo;
  rtc.getRtcInfo(&rtcInfo);
  switch(rtcInfo.type) {
    case EPSON_4543SA:return timeValidity_4543();
    case EPSON8564NB:return timeValidity_8564();
    case EPSON_RX8025:return timeValidity_RX8025();
    case EPSON_RX8900:return timeValidity_RX8900();
    case DS1307:return timeValidity_DS1307();
    case DS3231:return timeValidity_DS3231();
    case DS3234:return timeValidity_DS3234();
    case PCF8523:return timeValidity_PCF8523();
    case RV8803:return timeValidity_RV8803();
  }
  return RTC_U_ILLEGAL_PARAM;
}


void setup() {
  Serial.begin(9600) ;         // シリアル通信の初期化
  while (!Serial) {
    ; // シリアルポートが開くのを待つ
  }
  delay(10000);

  if (rtc.begin(false)) {
    Serial.println("Successful initialization of the RTC"); // 初期化成功
  } else {
    Serial.print("Failed initialization of the RTC");  // 初期化失敗
    while(1) ;                                              // 処理中断
  }
  int flag = timeValidity();
  int clear_flag =rtc.clearPowerFlag();
  if (RTC_U_SUCCESS==clear_flag) {
    Serial.println("Success : clear power flag.");
  } else if (RTC_U_UNSUPPORTED==clear_flag) {
    Serial.println("Skip : rtc does not support power related function.");
    flag=TIME_IS_INVALID;
  } else {
    Serial.print("Error: fail to clear power flag , retval = ");Serial.println(clear_flag);
  }

  if (flag < 0) {
    Serial.print("Error: fail to get power flag , retval = ");Serial.println(flag);
    while(1);
  } else if (flag == TIME_IS_INVALID) {
    Serial.println("Time of RTC setting is invalid.");
  } else {
    Serial.println("Time of RTC setting is valid.");
  }
}

void loop() {
  date_t date;
  if (!rtc.getTime(&date)) Serial.println("Error : can not get time data.");
  else printTime(&date);
  delay(1000) ;            // １秒後に繰り返す
}

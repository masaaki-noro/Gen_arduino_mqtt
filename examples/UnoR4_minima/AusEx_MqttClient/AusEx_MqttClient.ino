
#include "config.h"
#include <Syslog.h>

#include "arduinoHardwareHelper.h"
#include "detectArduinoHardware.h"

HardwareHelper hwHelper;

//#define HARD_SERIAL Serial1
#define HARD_SERIAL Serial


#ifdef USE_WDT
#include <Adafruit_SleepyDog.h>
#endif /* USE_WDT */

#ifdef USE_COLOR_LED
#include <ChainableLED.h>
ChainableLED leds(LED_CLK_PIN, LED_DATA_PIN, 1);  //defines the pin used on arduino.
#endif  /* USE_COLOR_LED */

#ifdef USE_LOG_FILE
#include <SPI.h>
#include <SD.h>
#endif /* USE_LOG_FILE */


bool allSensors=false;

/* sensor.cppの関数 */
extern bool init_sensors(void);
extern void output_sensors_info(void);
extern void process_sensors(void);

#ifdef USE_RTC /* RTC.cppの関数 */
extern void setupRTC(void);
unsigned long rtcDate(void);
#endif /* USE_RTC */

#ifdef UPDATE_RTC_BY_NTP
bool update_RTC_Time(unsigned long);
#endif /* UPDATE_RTC_BY_NTP */

#include "AusExOutputPlugin.h"

/*
 * 機種毎の設定
 */

// Mega
#if CPU_ARCH==AVR_ARCH /* AVR */
#define WIRELESS_STATUS 0
#define MAX_DURATION MAX_SLEEP_DURATION // sleep duration in ms.
void(* resetFunc) (void) = 0;//declare reset function at address 0
#endif /* CPU_ARCH==AVR_ARCH */

// MKR WiFi 1010
#if CPU_ARCH==SAMD_ARCH /* MKR, Zero */
#define MAX_DURATION MAX_SLEEP_DURATION // sleep duration in ms.
#define WIRELESS_STATUS 0
#endif /* CPU_ARCH==SAMD_ARCH */

#if CPU_ARCH==SAMD_ARCH /* MKR wifi 1010 */
#define MAX_DURATION MAX_SLEEP_DURATION // sleep duration in ms.
#endif

// Due
#if CPU_ARCH==SAM_ARCH /* Due */
#define MAX_DURATION MAX_SLEEP_DURATION // sleep duration in ms.
#define WIRELESS_STATUS 0
#endif /* CPU_ARCH==SAM_ARCH */

// ESP32
#if CPU_ARCH==XTENSA_LX6_ARCH /* ESP32 */
//#define PIN_NUMBER GPIO_NUM_14  // EXT0割り込みを使う場合のピン番号 IO14
#ifndef USE_SLEEP
#define MAX_DURATION MAX_SLEEP_DURATION // sleep duration in ms.
#else /* USE_SLEEP */
#define MAX_DURATION MAX_SLEEP_DURATION*1000 // スリープ時間 (マイクロ秒)
#endif /* USE_SLEEP */
#define WIRELESS_STATUS 0
#endif /* CPU_ARCH==XTENSA_LX6_ARCH */

// ESP8266
#if CPU_ARCH==XTENSA_LX106_ARCH /* ESP8266 */
#define MAX_DURATION MAX_SLEEP_DURATION*1000 //  スリープ時間 (マイクロ秒)
#define WIRELESS_STATUS WAKE_RF_DEFAULT
//#define WIRELESS_STATUS WAKE_RFCAL
//#define WIRELESS_STATUS WAKE_NO_RFCAL
//#define WIRELESS_STATUS WAKE_RF_DISABLED
#endif /* CPU_ARCH==XTENSA_LX106_ARCH */

// RA4_ARCH
#if CPU_ARCH==RA4_ARCH /* Uno R4 Minima, WiFi */
#define MAX_DURATION MAX_SLEEP_DURATION // sleep duration in ms.
#endif /* CPU_ARCH==SAM_ARCH */

// STM32_ARCH
#if CPU_ARCH==STM32_ARCH /* Giga R1 WiFi */
#define MAX_DURATION MAX_SLEEP_DURATION // sleep duration in ms.
#endif /* CPU_ARCH==STM32_ARCH */

// RP_ARCH
#if CPU_ARCH==RP_ARCH /* Nano RP2040 WiFi */
#define MAX_DURATION MAX_SLEEP_DURATION // sleep duration in ms.
#endif /* CPU_ARCH==RP_ARCH */

#ifdef USE_SLEEP
#include "UniSleep.h"
#define PIN_MASK 0


#endif /* USE_SLEEP */

#if defined(USE_NTP) && defined(USE_RTC)
#error "do not define USE_NTP and USE_RTC togather."
#endif /* USE_NTP && USE_RTC */

#include <ArduinoMqttClient.h>

#ifdef USE_WIFI
#if defined(ARDUINO_AVR_UNO_WIFI_DEV_ED) || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRWIFI1010) || defined(ARDUINO_SAMD_MKRVIDOR4000)
#include <WiFiNINA.h>
#else
#if HARDWARE_TYPE==ARDUINO_UNO_R4_WIFI
#include <WiFiS3.h>
#else
#include <WiFi.h>
#endif
#endif
#endif /* USE_WIFI */

#ifdef USE_ETHERNET
#include <Ethernet.h>
#endif /* USE_ETHERNET */

#if defined(USE_NTP) || defined(UPDATE_RTC_BY_NTP)
#ifdef USE_ETHERNET
#include <EthernetUdp.h>
#endif /* USE_ETHERNET */
#ifdef USE_WIFI
#include <WiFiUdp.h>
#endif /* USE_WIFI */
#include <NTPClient.h>
#endif /* USE_NTP or UPDATE_RTC_BY_NTP */

/*
 * ネットワーク関係定義
 */

IPAddress ip(SELF_IP_ADDRESS);
IPAddress dnsServer(DNS_SERVER_ADDRESS);
IPAddress gatewayAddress(GATEWAY_ADDRESS);
IPAddress netMask(NETMASK);

#ifdef USE_ETHERNET
byte mac[] = { FIX_MAC_ADDRESS }; //アドレスは手持ちのarduinoのものに変更すること
#endif /* USE_ETHERNET */

/*
   ネットワーク関係の設定
   注意 : DHCPでのアドレス取得失敗時の対策や，長時間経過後のアドレス再割当て等は対応していない
*/
char serverAddress[] = MQTT_SERVER_ADDR;  // server address
int port = MQTT_PORT;
char topic[] = MQTT_TOPIC;

#ifdef USE_DHCP
boolean useDhcp = true;  // DHCPでIPアドレスを設定
#else                    /* USE_DHCP */
boolean useDhcp = false;  // 固定IPアドレス
#endif                   /* USE_DHCP */

#if defined(USE_NTP) || defined(USE_RTC)
unsigned long currentTime;
#endif /* USE_NTP or USE_RTC */

#if defined(USE_NTP) || defined(UPDATE_RTC_BY_NTP)
#ifdef USE_ETHERNET
EthernetUDP ntpUDP;
#endif /* USE_ETHERNET */
#ifdef USE_WIFI
WiFiUDP ntpUDP;
#endif                                      /* USE_WIFI */
NTPClient timeClient(ntpUDP, 9 * 60 * 60);  // JST
#endif   /* USE_NTP or UPDATE_RTC_BY_NTP */

#ifdef USE_ETHERNET
EthernetClient netClient;
#endif /* USE_ETHERNET */
#ifdef USE_WIFI
WiFiClient netClient;
#endif /* USE_WIFI */

MqttClient mqttClient(netClient);

AuxExSensorIO outputDevice = AuxExSensorIO();

OutputChannel channel;

/*
 * スリープ関係
 */

#ifdef USE_SLEEP
UniSleep helper;
int cpuArch=CPU_ARCH;
uint64_t pinMask=PIN_MASK;
#endif /* USE_SLEEP */

/*
 * ログ関係の定義
 */
Syslog syslog(HOSTNAME, APP_NAME, LOG_KERN);

#ifdef USE_LOG_FILE
File logfile;
#endif /* USE_LOG_FILE */

/*
 * Serialに書き出した内容を完全にフラッシュする
 */
void flushAll(void) {
  netClient.flush();
  Serial.flush();
#ifdef USE_LOG_FILE
  if (logfile) {
    logfile.flush();
  }
#endif /* USE_LOG_FILE */

}


/*
 * 再起動
 */
void reboot() {
  flushAll();
#ifdef USE_LOG_FILE
  if (logfile) {
    logfile.close();
  }
#endif /* USE_LOG_FILE */

#ifdef USE_WDT
  while (true) {
    delay(WDT_SHORT_DURATION);
    Serial.print(".");
  }
#else /* USE_WDT */
  hwHelper.SoftwareReset();
// Mega
//#if CPU_ARCH==AVR_ARCH /* AVR */
//  resetFunc();
//#endif /* CPU_ARCH==AVR_ARCH */

// MKR WiFi 1010
//#if CPU_ARCH==SAMD_ARCH /* MKR, Zero */
//  NVIC_SystemReset();
//#endif /* CPU_ARCH==SAMD_ARCH */

//#if CPU_ARCH==XTENSA_LX6_ARCH /* ESP32 */
//  ESP.restart();
//#endif /* ESP32 */

// Uno R4
//#if CPU_ARCH==RA4_ARCH /* Uno R4 */
//  NVIC_SystemReset();
//#endif /* CPU_ARCH==RA4_ARCH */

#endif /* USE_WDT */

}

/*
 * 初期化(syslog有効化前)時のログ出力
 */
void outputBootlog(const __FlashStringHelper *message) {

  Serial.println(message);

#ifdef USE_WDT
    Watchdog.reset();
#endif /* USE_WDT */
#ifdef USE_LOG_FILE
  if (logfile) {

    logfile.println(message);

#ifdef USE_WDT
    Watchdog.reset();
#endif /* USE_WDT */

#if CPU_ARCH!=XTENSA_LX6_ARCH /* ESP32以外 */
    logfile.flush();
#endif /* ESP32以外 */

  }
#endif /* USE_LOG_FILE */
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
}

/*
 * ログローテート
 */
#ifdef LOG_ROTATE
void logRotate(){
  String logFileName = LOGFILE_NAME_HEAD;
  logFileName+="9.txt";
  if (SD.exists(logFileName.c_str())) {
    SD.remove(logFileName.c_str());
  }
  for (int i=8;i>=0;i--){
    int targetNum=i+1;
    String targetFileName=LOGFILE_NAME_HEAD;
    targetFileName+=targetNum;
    targetFileName+=".txt";
    logFileName = LOGFILE_NAME_HEAD;
    logFileName += i;
    logFileName += ".txt";
    if (SD.exists(logFileName.c_str())) {
      SD.rename(logFileName.c_str(),targetFileName.c_str());
    }
  }
  logFileName = LOGFILE_NAME_HEAD;
  logFileName+=".txt";
  String targetFileName=LOGFILE_NAME_HEAD;
  targetFileName += "0.txt";
  if (SD.exists(logFileName.c_str())) {
    SD.rename(logFileName.c_str(),targetFileName.c_str());
  }
}
#endif /* LOG_ROTATE */

/*
 * ログファイルの初期化
 */
#ifdef USE_LOG_FILE
void prepareLogFile() {

  String logFileName = LOGFILE_NAME_HEAD;
  logFileName+=".txt";

  SD.begin(SD_CHIP_SELECT);
  logfile = SD.open(logFileName.c_str(), FILE_WRITE);

  if (LOG_FILE_SIZE_MAX<logfile.size()) {
#ifdef LOG_ROTATE
    logRotate();
#else /* LOG_ROTATE */
    logfile.close();
    SD.remove(logFileName.c_str());
    logfile = SD.open(logFileName.c_str(), FILE_WRITE);
#endif /* LOG_ROTATE */
  }

  if (logfile) {
    syslog.SetFile(&logfile);
  } else {
    Serial.println("open logfile failure.");
  }
}
#endif /* USE_LOG_FILE */

/*
 * 初期化
 */
void setup() {
  Serial.begin(SERIAL_SPEED);  // シリアル通信の初期化

#ifdef USE_SLEEP
  delay(10000);
#endif /* USE_SLEEP */

#ifdef DEBUG
  hwHelper.SerialWait();
#endif /* DEBUG */

#ifdef USE_COLOR_LED
  leds.init();
  leds.setColorRGB(0, 0, 0, 120);  //青
  delay(LED_SHORT_DURATION);
#endif /* USE_COLOR_LED */

#ifdef USE_WDT
  int countdownMS = Watchdog.enable(WDT_DURATION);
#endif /* USE_WDT */

  Serial.println("");
  Serial.println("setup start.");
  channel.serial = &Serial;
  outputDevice.SetIO(AUSEX_OUTPUT_CHANNEL_SERIAL, channel, FORMAT_TYPE_SYSLOG);
  outputDevice.SetLogParam(HOSTNAME, APP_NAME);

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

#ifdef USE_LOG_FILE
  prepareLogFile();
#endif /* USE_LOG_FILE */

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

#ifdef USE_RTC
  setupRTC();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_RTC */


#ifdef USE_COLOR_LED
  leds.setColorRGB(0, 128, 20, 128);  // 紫
  delay(LED_SHORT_DURATION);
#endif /* USE_COLOR_LED */

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

  outputBootlog(F("network setup start."));

  // MACアドレスとIPアドレスの設定
  // 参考URL http://arduino.cc/en/Reference/EthernetBegin
  if (useDhcp) {
#ifdef USE_ETHERNET
    Ethernet.init(ETHERNET_CHIP_SELECT);
    if (Ethernet.begin(mac) == 0) {
      //Serial.println(F("DHCP fail."));

      outputBootlog(F("DHCP fail."));

#ifdef USE_COLOR_LED
      leds.setColorRGB(0, 200, 40, 0);  //オレンジ
#endif  /* USE_COLOR_LED */
      reboot();
    }
#endif /* USE_ETHERNET */

#ifdef USE_WIFI
    WiFi.begin(SSID_STR, WIFI_PASS);

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
#endif /* USE_WIFI */

  } else {
#ifdef USE_ETHERNET
    Ethernet.begin(mac, ip, dnsServer, gatewayAddress, netMask);
#endif /* USE_ETHERNET */
#ifdef USE_WIFI
    WiFi.config(ip, dnsServer, gatewayAddress, netMask);
    WiFi.begin(SSID_STR, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
#endif /* USE_WIFI */
  }
#ifdef USE_ETHERNET
  Serial.print(F("IP address : "));
  Serial.println(Ethernet.localIP());

  //String ipaddr = Ethernet.localIP()[0] + "." + Ethernet.localIP()[1] + "." + Ethernet.localIP()[2] + "." + Ethernet.localIP()[3];
  //outputBootlog(F("IP address : "));
  //outputBootlog(F(ipaddr.c_str()));
#endif /* USE_ETHERNET */
#ifdef USE_WIFI
  Serial.print(F("IP address : "));
  Serial.println(WiFi.localIP());
  //String ipaddr = WiFi.localIP()[0] + "." + WiFi.localIP()[1] + "." + WiFi.localIP()[2] + "." + WiFi.localIP()[3];
  //outputBootlog(F("IP address : "));
  //outputBootlog(F(ipaddr.c_str()));
#endif /* USE_WIFI */

  outputBootlog(F("network setup done"));


#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

#if defined(USE_NTP) || defined(UPDATE_RTC_BY_NTP)
  timeClient.begin();
  timeClient.update();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_NTP or UPDATE_RTC_BY_NTP */

#ifdef USE_NTP
  syslog.SetNTP(&timeClient, DATE_TIME);
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_NTP */

#ifdef UPDATE_RTC_BY_NTP
  //unsigned long currentTime = timeClient.getEpochTime();
  currentTime = timeClient.getEpochTime();
  if (update_RTC_Time(currentTime)) {
    outputBootlog(F("update RTC time by NTP."));
  } else {
    outputBootlog(F("fail to update RTC time using NTP."));
  }
#endif /* UPDATE_RTC_BY_NTP */

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

#ifdef USE_LOG_SERIAL
  if (SERIAL_RESET) {
    if (HARD_SERIAL) {
      syslog.SetSerial(&HARD_SERIAL);
    } else {
      outputBootlog(F("setup serial for syslog fail."));
    }
  } else {
    syslog.SetSerial(&HARD_SERIAL);
  }
#endif /* USE_LOG_SERIAL */

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

  mqttClient.setId(HOSTNAME);

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

#ifdef USE_MQTT_AUTH
  mqttClient.setUsernamePassword(MQTT_AUTH_USERNAME, MQTT_AUTH_PASSWORD);
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_MQTT_AUTH */

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

  if (!mqttClient.connect(serverAddress, port)) {
    syslog.logf(LOG_CRIT, "MQTT connection failed! Error code =  %d", mqttClient.connectError());
#ifdef USE_COLOR_LED
    leds.setColorRGB(0, 200, 40, 0);  //オレンジ
#endif  /* USE_COLOR_LED */
    reboot();
  }

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

  syslog.log(LOG_INFO, "You're connected to the MQTT broker!");

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

  syslog.log(LOG_INFO, "sensor setup start.");

  allSensors = init_sensors();

  syslog.log(LOG_INFO, "sensor setup end.");

  if (!allSensors) {
    syslog.log(LOG_ERR, "could not use any kind of sensor.");
    syslog.log(LOG_ERR, "reboot.");
    reboot();
  }

  syslog.log(LOG_INFO, "Unified Sensor mqtt client program.");

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

  output_sensors_info();

#ifdef USE_COLOR_LED
  leds.setColorRGB(0, 0, 0, 0);  // 消灯
#endif                           /* USE_COLOR_LED */

#ifdef USE_WDT
  Watchdog.disable();
#endif /* USE_WDT */
}

/*
 * メインプログラム
 */
void loop() {


#ifdef USE_WDT
  int countdownMS = Watchdog.enable(WDT_DURATION);
#endif /* USE_WDT */

  if (0 == mqttClient.connected()) {
    syslog.log(LOG_CRIT, "Server connection is not available.");
#ifdef USE_COLOR_LED
    leds.setColorRGB(0, 200, 40, 0);  //オレンジ
#endif  /* USE_COLOR_LED */
    reboot();
  }

#ifdef USE_COLOR_LED
  leds.setColorRGB(0, 0, 128, 0);
#endif /* USE_COLOR_LED */
  mqttClient.poll();

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

  channel.mqttClient = &mqttClient;
  outputDevice.SetIO(AUSEX_OUTPUT_CHANNEL_MQTT_CLIENT, channel, MQTT_MESSAGE_FORMAT);
  //
  syslog.log(LOG_INFO, "making MQTT publish.");
  outputDevice.SetMqttTopic(topic);

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */


#ifdef USE_NTP
  timeClient.update();
  currentTime = timeClient.getEpochTime();
#endif /* USE_NTP */

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

#ifdef USE_RTC
  currentTime = rtcDate();

#endif /* USE_RTC */

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

  process_sensors();

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

  flushAll();

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

#ifdef USE_COLOR_LED
  leds.setColorRGB(0, 0, 0, 0);
#endif /* USE_COLOR_LED */

#ifdef USE_SLEEP
#if CPU_TYPE==TYPE_ESP32
  delay(1000);
#endif /* CPU_TYPE==TYPE_ESP32 */
#endif /* USE_SLEEP */

#ifdef USE_WDT
  Watchdog.disable();
#endif /* USE_WDT */


#ifdef USE_SLEEP
#ifdef USE_RTC_INTERUPT
  if (TIMER_INTERUPT_ON==checkTimerInterupt()) {
    int flag = rtc.clearInterupt(0xFF);
    if (0>flag) {
#ifdef USE_WDT
      int countdownMS = Watchdog.enable(WDT_DURATION);
#endif /* USE_WDT */
      syslog.log(LOG_CRIT, "Error : can not clear interupt flag.");
      reboot();
    }
  }
#endif /* USE_RTC_INTERUPT */

  int sleepMode = helper.SetSleepMode(SLEEP_MODE, MAX_DURATION);
  if ( sleepMode != UNI_SLEEP_SUCCESS ) { /* AVRの場合は、スリープ時間は無意味 */
    syslog.logf(LOG_CRIT, "Set sleep mode failure, val =  %d", sleepMode);
    delay(MAX_DURATION);
  } else {
#if HARDWARE_SERIAL_TYPE==SERIAL_TYPE_MKR
    USBDevice.detach();
#endif /* HARDWARE_SERIAL_TYPE==SERIAL_TYPE_MKR */
    if (!helper.Sleep()) {
#if HARDWARE_SERIAL_TYPE==SERIAL_TYPE_MKR
      USBDevice.attach();
      delay(2000);
#endif /* HARDWARE_SERIAL_TYPE==SERIAL_TYPE_MKR */
      syslog.log(LOG_CRIT, "fail to sleep.");
      delay(MAX_DURATION);
    }
  }
#if CPU_ARCH==XTENSA_LX6_ARCH /* ESP32 */
  WiFi.disconnect(true);
#endif /* CPU_ARCH==XTENSA_LX6_ARCH */

#if HARDWARE_SERIAL_TYPE==SERIAL_TYPE_MKR
  USBDevice.attach();
  delay(2000);
#endif /* HARDWARE_SERIAL_TYPE==SERIAL_TYPE_MKR */

#else /* USE_SLEEP */

  delay(MAX_DURATION);  // DHTは測定の周波数が非常に長いため，連続してアクセスできないように，待ち時間をはさむ



#endif /* USE_SLEEP */


}


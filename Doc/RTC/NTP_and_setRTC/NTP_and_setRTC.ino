/*
 * NTPを使って、RTCに時刻を設定するプログラム
 */
#include "config.h"


#ifndef USE_ETHERNET
#if defined(ARDUINO_AVR_UNO_WIFI_DEV_ED) || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRWIFI1010) || defined(ARDUINO_SAMD_MKRVIDOR4000)
#include <WiFiNINA.h>
#else
#include <WiFi.h>
#endif
#include <WiFiUdp.h>
#else /* ! USE_ETHERNET */
#include <Ethernet.h>
#include <EthernetUdp.h>
#endif /* !USE_ETHERNET */

#include <NTPClient.h>


#ifdef USE_DHCP
boolean useDhcp = true;  // DHCPでIPアドレスを設定
#else                    /* USE_DHCP */
boolean useDhcp = false;  // 固定IPアドレス
#endif                   /* USE_DHCP */


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


#ifdef USE_ETHERNET
EthernetUDP ntpUDP;
#else /* USE_ETHERNET */
WiFiUDP ntpUDP;
#endif   /* USE_ETHERNET */
NTPClient timeClient(ntpUDP, 9 * 60 * 60);  // JST

/*
 * ネットワークのセットアップ
 */
void setupNetwork() {
  if (useDhcp) {
#ifdef USE_ETHERNET
    if (Ethernet.begin(mac) == 0) {
      Serial.println(F("DHCP fail."));
      while(true) {
      };
    };

#else /* USE_ETHERNET */
    WiFi.begin(SSID_STR, WIFI_PASS);

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
#endif /* USE_ETHERNET */
  } else {
#ifdef USE_ETHERNET
    Ethernet.begin(mac, ip, dnsServer, gatewayAddress, netMask);
#else /* USE_ETHERNET */
    WiFi.config(ip, dnsServer, gatewayAddress, netMask);
    WiFi.begin(SSID_STR, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
#endif /* USE_ETHERNET */
  }
#ifdef USE_ETHERNET
  Serial.print(F("IP address : "));
  Serial.println(Ethernet.localIP());
#else /* USE_ETHERNET */
  Serial.print(F("IP address : "));
  Serial.println(WiFi.localIP());
#endif /* USE_ETHERNET */
  Serial.println(F("network setup done"));
}

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


void setup() {
  Serial.begin(9600) ;         // シリアル通信の初期化
  while (!Serial) {
    ; // シリアルポートが開くのを待つ
  }
  delay(10000);
  Serial.println("");
  Serial.println("setup start");
  delay(5000);

  if (rtc.begin(false)) {
    Serial.println("Successful initialization of the RTC"); // 初期化成功
  } else {
    Serial.print("Failed initialization of the RTC");  // 初期化失敗
    while(1) ;                                              // 処理中断
  }

  setupNetwork();
  timeClient.begin();
  timeClient.update();

  unsigned long currentTime = timeClient.getEpochTime();

  date_t date;
  rtc.convertEpochTime(&date, currentTime);

  Serial.println("setting time.");
  printTime(&date);
  if (!rtc.setTime(&date)) {
    Serial.print("set time to RTC fail.");     // 初期化失敗
    while(1);
  } else {
    Serial.println("set time to RTC success."); // 初期化成功
  }

}

void loop() {
  date_t date;
  if (!rtc.getTime(&date)) Serial.println("Error : can not get time data.");
  else printTime(&date);
  delay(10000) ;            // １秒後に繰り返す
}


# NTPを使って、RTCに時刻を設定するプログラム


## 1. 動作確認した環境

- ESPr One 32 (ESP32) https://www.switch-science.com/products/3555
- Arduino Mega 2560 + Arduino ETHERNET shield2
- Arduino MKR WiFi1010

ネットワークの条件は「pool.ntp.org」とUDP通信が可能であること．

## 2. 設定
「``config.h``」を編集して，以下の項目を利用する環境に合わせて変更

### 2.1. ネットワークメディア
イーサネットを利用する場合，「``USE_ETHERNET``」を有効にして，
MACアドレス(「``FIX_MAC_ADDRESS``」)を変更する．
WiFiネットワークを利用する場合は，「``USE_ETHERNET``」をコメントアウトする．
```
#define USE_ETHERNET
#define FIX_MAC_ADDRESS  0x90, 0xa2, 0xda, 0x10, 0x11, 0x51
```

WiFiネットワークを使う場合は，以下の2項目を接続するネットワークに合わせる．
```
#define SSID_STR "ssid"
#define WIFI_PASS "wifi_password"
```

### 2.2. IPアドレス
IPアドレスは自動設定(「DHCP」)を用いる場合は，「``#define USE_DHCP``」を有効化，
固定設定を行う場合は，「``#define USE_DHCP``」をコメントアウト．

さらに，固定のIPアドレスの情報4項目を使う環境に合わせて編集する．
もし，DHCPを利用する場合は，固定IPアドレスの設定項目は編集せず
そのまま残す(消さない)．

```
#define USE_DHCP

#define SELF_IP_ADDRESS 192, 168, 1, 111
#define DNS_SERVER_ADDRESS 192, 168, 1, 254
#define GATEWAY_ADDRESS 192, 168, 1, 254
#define NETMASK 255, 255, 255, 0
```


### 2.3. 利用するRTCの選択
利用するRTCの種類に関する定義のみ有効化する．
```
//#define USE_RTC_4543
//#define USE_RTC8564NB
//#define USE_DS1307
//#define USE_DS3231
//#define USE_DS3234
//#define USE_PCF8523
//#define USE_RV8803
//#define USE_RX8025
//#define USE_RX8900
```

### 2.4. RTCのインターフェース
I2Cではないインターフェースを持つ，RTCを使う場合は，Arduinoと接続する際のピン番号を以下の項目に定義(編集)する．
```
// 独自I/F : EPSON 4543
#define DATA_PIN 5
#define CLK_PIN 4
#define WR_PIN 12
#define CE_PIN 11
#define FSEL_PIN 13
// SPI : DS3234
#define CS_PIN 53 // 5 esp32  53 mega
#define SPI_IF SPI
// I2C : 各種
#define I2C_IF Wire
```

***
- [「README_RTC」に戻る](../README_RTC.md)
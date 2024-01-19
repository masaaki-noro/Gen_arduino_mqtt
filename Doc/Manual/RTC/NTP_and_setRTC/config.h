/*
 * 全体の設定
 */
//#define USE_ETHERNET
#define USE_DHCP

/*
 * ネットワーク関係の設定
 */

#define SELF_IP_ADDRESS 192, 168, 1, 111
#define DNS_SERVER_ADDRESS 192, 168, 1, 254
#define GATEWAY_ADDRESS 192, 168, 1, 254
#define NETMASK 255, 255, 255, 0

#define FIX_MAC_ADDRESS  0x90, 0xa2, 0xda, 0x10, 0x11, 0x51

//#define SSID_STR "elecom2g01-192886"
//#define WIFI_PASS "6386800297444"
#define SSID_STR "Xperia_noro"
#define WIFI_PASS "houtbrionhome"

/*
 * 使用するRTCの選択
 */
//#define USE_RTC_4543
//#define USE_RTC8564NB
//#define USE_DS1307
#define USE_DS3231
//#define USE_DS3234
//#define USE_PCF8523
//#define USE_RV8803
//#define USE_RX8025
//#define USE_RX8900

/*
 * 使用するRTCのI/Fに関する定義
 */

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


#ifdef USE_RTC_4543
#include "RTC_4543_U.h"

RTC_4543_U rtc = RTC_4543_U(DATA_PIN, CLK_PIN, WR_PIN, CE_PIN, FSEL_PIN);
#endif /* USE_RTC_4543 */

#ifdef USE_RTC8564NB
#include "RTC_8564NB_U.h"
RTC_8564NB_U rtc = RTC_8564NB_U(&I2C_IF);
#endif /* USE_RTC8564NB */

#ifdef USE_DS1307
#include "RTC_DS1307_U.h"
RTC_DS1307_U rtc = RTC_DS1307_U(&I2C_IF);
#endif /* USE_DS1307 */

#ifdef USE_DS3231
#include "RTC_DS3231_U.h"
RTC_DS3231_U rtc = RTC_DS3231_U(&I2C_IF);
#endif /* USE_DS3231 */

#ifdef USE_DS3234
#include "RTC_DS3234_U.h"

RTC_DS3234_U rtc = RTC_DS3234_U(CS_PIN,&SPI_IF);
#endif /* USE_DS3234 */

#ifdef USE_PCF8523
#include "RTC_PCF8523_U.h"
RTC_PCF8523_U rtc = RTC_PCF8523_U(&I2C_IF);
#endif /* USE_PCF8523 */

#ifdef USE_RV8803
#include "RTC_RV8803_U.h"
RTC_RV8803_U rtc = RTC_RV8803_U(&I2C_IF);
#endif /* USE_RV8803 */

#ifdef USE_RX8025
#include "RTC_RX8025_U.h"
RTC_RX8025_U rtc = RTC_RX8025_U(&I2C_IF);
#endif /* USE_RX8025 */

#ifdef USE_RX8900
#include "RTC_RX8900_U.h"
RTC_RX8900_U rtc = RTC_RX8900_U(&I2C_IF);
#endif /* USE_RX8900 */

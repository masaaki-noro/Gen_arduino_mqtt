#include "detectArduinoHardware.h"
#if HARDWARE_TYPE==ARDUINO_GIGA_WIFI_MAIN || HARDWARE_TYPE==ARDUINO_GIGA_WIFI_SUB
#define I2C_IF Wire1
#else
#define I2C_IF Wire
#endif
#define USE_WIFI
#define USE_RTC
#define USE_PCF8523
#define USE_COLOR_LED
#define LED_DATA_PIN 8
#define LED_CLK_PIN 7
#define LED_DURATION 3000
#define LED_SHORT_DURATION 1000
#define SD_CHIP_SELECT 10
#define WDT_DURATION 20000
#define WDT_SHORT_DURATION 500
#define SERIAL_SPEED 9600
#define HOSTNAME "Nano_RP2040_WiFi"
#define APP_NAME "AusEx_mqtt_client"
#define USE_LOG_FILE
#define LOGFILE_NAME_HEAD "/syslog"
#define LOG_FILE_SIZE_MAX 10000000
#define USE_LOG_SERIAL
#define SSID_STR "Buffalo-G-9C50"
#define WIFI_PASS "jxgdekvmujfyh"
#define FIX_MAC_ADDRESS 0x90, 0xa2, 0xda, 0x10, 0x11, 0x51
#define USE_DHCP
#define SELF_IP_ADDRESS 192, 168, 1, 111
#define DNS_SERVER_ADDRESS 192, 168, 1, 254
#define GATEWAY_ADDRESS 192, 168, 1, 254
#define NETMASK 255, 255, 255, 0
#define MQTT_MESSAGE_FORMAT FORMAT_TYPE_PLAIN_TEXT
#define MQTT_AUTH_USERNAME "foo"
#define MQTT_AUTH_PASSWORD "bar"
#define MQTT_TOPIC "arduino/NanoRP2040C"
#define MQTT_SERVER_ADDR "192.168.1.254"
#define MQTT_PORT 1883
#define MAX_SLEEP_DURATION 15000
#define SLEEP_MODE MODE_PWR_DOWN
#define USE_SENSOR_TSL2561
#define TSL2561_I2C_ADDR TSL2561_ADDR_FLOAT
#define TSL2561_GAIN TSL2561_GAIN_1X
#define TSL2561_INT_TIME TSL2561_INTEGRATIONTIME_13MS
#define SENSOR_ID_TSL2561 -1

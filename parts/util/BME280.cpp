
#include "config.h"

#include <Syslog.h>
#include "AusExOutputPlugin.h"

extern Syslog syslog;
extern AuxExSensorIO outputDevice;

#if defined(USE_NTP) || defined(USE_RTC)
extern unsigned long currentTime;
#endif /* USE_NTP or USE_RTC */

#ifdef USE_WDT
#include <Adafruit_SleepyDog.h>
#endif /* USE_WDT */

#ifdef USE_SENSOR_BME280
#include "AusExBME280.h"

#ifndef SENSOR_ID_BME280_TEMPERATURE
#define SENSOR_ID_BME280_TEMPERATURE  -1
#endif /* SENSOR_ID_BME280_TEMPERATURE */

#ifndef SENSOR_ID_BME280_HUMIDITY
#define SENSOR_ID_BME280_HUMIDITY  -1
#endif /* SENSOR_ID_BME280_HUMIDITY */

#ifndef SENSOR_ID_BME280_PRESSURE
#define SENSOR_ID_BME280_PRESSURE  -1
#endif /* SENSOR_ID_BME280_PRESSURE */

#ifdef BME280_I2C
AusExBME280 bme280 = AusExBME280(&I2C_IF,SENSOR_ID_BME280_TEMPERATURE,SENSOR_ID_BME280_HUMIDITY,SENSOR_ID_BME280_PRESSURE);
#endif /* BME280_I2C */
#ifdef BME280_HARD_SPI
AusExBME280 bme280 = AusExBME280(0xFF, 0xFF, 0xFF, BME280_CS,SENSOR_ID_BME280_TEMPERATURE,SENSOR_ID_BME280_HUMIDITY,SENSOR_ID_BME280_PRESSURE);
#endif /* BME280_HARD_SPI */
#ifdef BME280_HARD_SPI
AusExBME280 bme280 = AusExBME280(BME280_SCK, BME280_MOSI, BME280_MISO, BME280_CS,SENSOR_ID_BME280_TEMPERATURE,SENSOR_ID_BME280_HUMIDITY,SENSOR_ID_BME280_PRESSURE);
#endif /* BME280_HARD_SPI */

/*
 * センサの初期化
 */
bool bme280_init(){
  if (!bme280.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid BME280 sensor, check wiring!");
    return false;
  }
#ifdef USE_WDT
  Watchdog.disable();
#endif /* USE_WDT */
  delay(AUSEX_BME280_SENSOR_HUMIDITY_MIN_DELAY/1000);
#ifdef USE_WDT
  int countdownMS = Watchdog.enable(WDT_DURATION);
#endif /* USE_WDT */
  return true;
}

/*
 * センサ情報の出力
 */
void bme280_output_info() {
  sensor_t sensor;
  bme280.temperature().getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
  // Print humidity sensor details.
  bme280.humidity().getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
  // Print pressure sensor details.
  bme280.pressure().getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * BME280温湿度, 気圧センサ
 */
void bme280_Sensor(){
  // Get temperature event and print its value.
  sensors_event_t event;
  syslog.log(LOG_INFO, "bme280 read temperature");
  bme280.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    syslog.log(LOG_ERR, F("Error reading temperature!"));
  } else {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "bme280 temperature = %f",event.temperature);
    outputDevice.EventOutput(event);
  }
  syslog.log(LOG_INFO, "bme280 read humidity");
  // Get humidity event and print its value.
  bme280.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    syslog.log(LOG_ERR, F("Error reading humidity!"));
  } else {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "bme280 humidity = %f",event.relative_humidity);
    outputDevice.EventOutput(event);
  }
  syslog.log(LOG_INFO, "bme280 read pressure");
  // Get pressure event and print its value.
  bme280.pressure().getEvent(&event);
  if (isnan(event.pressure)) {
    syslog.log(LOG_ERR, F("Error reading pressure!"));
  } else {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "bme280 pressure = %f",event.pressure);
    outputDevice.EventOutput(event);
  }
}
#endif /* USE_SENSOR_BME280 */
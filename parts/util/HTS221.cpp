
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

#ifdef USE_SENSOR_HTS221
#include "AusExHTS221.h"

#ifndef SENSOR_ID_HTS221_TEMPERATURE
#define SENSOR_ID_HTS221_TEMPERATURE  -1
#endif /* SENSOR_ID_HTS221_TEMPERATURE */

#ifndef SENSOR_ID_HTS221_HUMIDITY
#define SENSOR_ID_HTS221_HUMIDITY  -1
#endif /* SENSOR_ID_HTS221_HUMIDITY */

AusExHTS221 hts221 = AusExHTS221(&Wire,SENSOR_ID_HTS221_TEMPERATURE,SENSOR_ID_HTS221_HUMIDITY);

/*
 * センサの初期化
 */
bool hts221_init(){
  if (!hts221.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid HTS221 sensor, check wiring!");
    return false;
  }
#ifdef USE_WDT
  Watchdog.disable();
#endif /* USE_WDT */
  delay(AUSEX_HTS221_SENSOR_INIT_DELAY/1000);
#ifdef USE_WDT
  int countdownMS = Watchdog.enable(WDT_DURATION);
#endif /* USE_WDT */
  return true;
}

/*
 * センサ情報の出力
 */
void hts221_output_info() {
  sensor_t sensor;
  hts221.temperature().getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
  // Print humidity sensor details.
  hts221.humidity().getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * HTS221温湿度
 */
void hts221_Sensor(){
  // Get temperature event and print its value.
  sensors_event_t event;
  syslog.log(LOG_INFO, "hts221 read temperature");
  hts221.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    syslog.log(LOG_ERR, F("Error reading temperature!"));
  } else {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "hts221 temperature = %f",event.temperature);
    outputDevice.EventOutput(event);
  }
  syslog.log(LOG_INFO, "hts221 read humidity");
  // Get humidity event and print its value.
  hts221.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    syslog.log(LOG_ERR, F("Error reading humidity!"));
  } else {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "hts221 humidity = %f",event.relative_humidity);
    outputDevice.EventOutput(event);
  }
}
#endif /* USE_SENSOR_HTS221 */
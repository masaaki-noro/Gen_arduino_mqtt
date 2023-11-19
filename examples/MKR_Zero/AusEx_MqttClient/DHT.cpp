
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

#ifdef USE_SENSOR_DHT
#include "AusExDHT.h"


#ifndef SENSOR_ID_DHT_TEMPERATURE
#define SENSOR_ID_DHT_TEMPERATURE -1
#endif /* SENSOR_ID_DHT_TEMPERATURE */

#ifndef SENSOR_ID_DHT_HUMIDITY
#define SENSOR_ID_DHT_HUMIDITY -1
#endif /* SENSOR_ID_DHT_HUMIDITY */


AusExDHT dht = AusExDHT(SENSOR_DHT_PIN, DHTTYPE, SENSOR_ID_DHT_TEMPERATURE,SENSOR_ID_DHT_HUMIDITY );

/*
 * センサの初期化
 */
bool dht_init(void) {
  if (!dht.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid DHT series sensor, check wiring!");
    return false;
  }
  return true;
}


/*
 * センサ情報の出力
 */
void dht_output_info(void) {
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * DHT温湿度センサ
 */
void dht_Sensor(void) {
 // Get temperature event and print its value.
  sensors_event_t event;
  syslog.log(LOG_INFO, "DHT read temperature");
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    syslog.log(LOG_ERR, F("Error reading temperature!"));
  } else {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "DHT temperature = %f",event.temperature);
    outputDevice.EventOutput(event);
  }

#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */

  syslog.log(LOG_INFO, "DHT read humidity");
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    syslog.log(LOG_ERR, F("Error reading humidity!"));
  } else {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "DHT humidity = %f",event.relative_humidity);
    outputDevice.EventOutput(event);
  }
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
}

#endif /* USE_SENSOR_DHT */

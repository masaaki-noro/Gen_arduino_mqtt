
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

#ifdef USE_SENSOR_WATER_DETECTION
#include "AusExGroveWaterSensor.h"

#ifndef SENSOR_ID_WATER_DETECTION
#define SENSOR_ID_WATER_DETECTION -1
#endif /* SENSOR_ID_WATER_DETECTION */

AusExGroveWaterSensor groveWaterDetection = AusExGroveWaterSensor(SENSOR_WATER_DETECTION_PIN, SENSOR_ID_WATER_DETECTION);

/*
 * センサの初期化
 */
bool groveWaterDetection_init(void) {
  if (!groveWaterDetection.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid Grove water detection sensor, check wiring!");
    return false;
  }
  return true;
}


/*
 * センサ情報の出力
 */
void groveWaterDetection_output_info(void) {
  sensor_t sensor;
  groveWaterDetection.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * Grove water detect sensor
 */
void groveWaterDetection_Sensor(void) {
  sensors_event_t event;
  if (groveWaterDetection.getEvent(&event)) {
    if (isnan(event.value)) {
      syslog.log(LOG_ERR, F("Error reading Grove water detection sensor!"));
    } else {
#if defined(USE_NTP) || defined(USE_RTC)
      event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
      outputDevice.EventOutput(event);
      syslog.logf(LOG_INFO, "Grove water detection sensor = %u",event.value);
    }
  } else {
    syslog.log(LOG_ERR, F("Error reading Grove water detection sensor!"));
  }
}
#endif /* USE_SENSOR_WATER_DETECTION */
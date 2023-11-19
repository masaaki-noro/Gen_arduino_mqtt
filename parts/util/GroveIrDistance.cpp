
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


#ifdef USE_SENSOR_IR_DISTANCE_INTERRUPTER
#include "AusExGroveInfraredDistanceSensor.h"

#ifndef SENSOR_ID_IR_DISTANCE_INTERRUPTER
#define SENSOR_ID_IR_DISTANCE_INTERRUPTER -1
#endif /* SENSOR_ID_IR_DISTANCE_INTERRUPTER */

AusExGroveInfraredDistanceSensor groveIrDistance = AusExGroveInfraredDistanceSensor(SENSOR_IR_DISTANCE_INTERRUPTER_PIN, SENSOR_ID_IR_DISTANCE_INTERRUPTER);

/*
 * センサの初期化
 */
bool groveIrDistance_init(void) {
  if (!groveIrDistance.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid Grove IR distance interrupter, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void groveIrDistance_output_info(void) {
  sensor_t sensor;
  groveIrDistance.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * Grove IR distance interrupter
 */
void groveIrDistance_Sensor(void) {
  sensors_event_t event;
  if (groveIrDistance.getEvent(&event)) {
    if (isnan(event.value)) {
      syslog.log(LOG_ERR, F("Error reading Grove IR distance interrupter!"));
    } else {
#if defined(USE_NTP) || defined(USE_RTC)
      event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
      outputDevice.EventOutput(event);
      syslog.logf(LOG_INFO, "Grove IR distance interrupter = %u",event.value);
    }
  } else {
    syslog.log(LOG_ERR, F("Error reading Grove IR distance interrupter!"));
  }
}

#endif /* USE_SENSOR_IR_DISTANCE_INTERRUPTER */


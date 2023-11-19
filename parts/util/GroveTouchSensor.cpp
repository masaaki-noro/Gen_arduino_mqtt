
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


#ifdef USE_SENSOR_TOUCH
#include "AusExGroveTouchSensor.h"

#ifndef SENSOR_ID_TOUCH
#define SENSOR_ID_TOUCH  -1
#endif /* SENSOR_ID_TOUCH */

AusExGroveTouchSensor groveTouch = AusExGroveTouchSensor(SENSOR_TOUCH_PIN, SENSOR_ID_TOUCH);
/*
 * センサの初期化
 */
bool groveTouch_init(void) {
  if (!groveTouch.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid Grove touch sensor, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void groveTouch_output_info(void) {
  sensor_t sensor;
  groveTouch.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * Grove touch sensor
 */
void groveTouch_Sensor(void) {
  sensors_event_t event;
  if (groveTouch.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "Grove touch sensor = %u",event.value);
  } else {
    syslog.log(LOG_ERR, F("Error reading grove touch sensor!"));
  }
}

#endif /* USE_SENSOR_TOUCH */

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

#ifdef USE_SENSOR_LINE_FINDER
#include "AusExGroveLineFinder.h"

#ifndef SENSOR_ID_LINE_FINDER
#define SENSOR_ID_LINE_FINDER -1
#endif /* SENSOR_ID_LINE_FINDER */

AUSEX_GROVE_LINE_FINDER_CLASS groveLineFinder = AUSEX_GROVE_LINE_FINDER_CLASS(SENSOR_LINE_FINDER_PIN, SENSOR_ID_LINE_FINDER);

/*
 * センサの初期化
 */
bool groveLineFinder_init(void) {
  if (!groveLineFinder.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid Grove line finder, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void groveLineFinder_output_info(void) {
  sensor_t sensor;
  groveLineFinder.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * Grove Line Finder
 */
void groveLineFinder_Sensor(void) {
  sensors_event_t event;
  if (groveLineFinder.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "Grove line finder = %u",event.value);
  } else {
    syslog.log(LOG_ERR, F("Error reading grove line finder sensor!"));
  }
}
#endif /* USE_SENSOR_LINE_FINDER */
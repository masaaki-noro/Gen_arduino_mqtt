
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


#ifdef USE_SENSOR_GROVE_GSR
#include "AusExGroveGsr.h"

#ifndef SENSOR_ID_GROVE_GSR
#define SENSOR_ID_GROVE_GSR  -1
#endif /* SENSOR_ID_GROVE_GSR */

GroveGsrAusEx groveGSR = GroveGsrAusEx(SENSOR_GROVE_GSR_PIN, (int32_t) SENSOR_ID_GROVE_GSR);

/*
 * センサの初期化
 */
bool groveGSR_init(void) {
  if (!groveGSR.begin()){
    syslog.log(LOG_CRIT, "Could not initialize analog GSR sensor, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void groveGSR_output_info(void) {
  sensor_t sensor;
  groveGSR.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * センサ読み取り
 */
void groveGSR_Sensor(void) {
  sensors_event_t event;
  if (groveGSR.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "grove GSR = %u",event.value);
  } else {
    syslog.log(LOG_ERR, F("Error reading Grove GSR sensor!"));
  }
}

#endif /* USE_SENSOR_GROVE_GSR */


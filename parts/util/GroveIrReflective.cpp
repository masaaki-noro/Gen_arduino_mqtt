
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

#ifdef USE_SENSOR_IR_RPR_220  // Grove - Infrared Reflective Sensor
#include "AusExGroveInfraredReflectiveSensor.h"

#ifndef SENSOR_ID_IR_RPR_220
#define SENSOR_ID_IR_RPR_220 -1
#endif /* SENSOR_ID_IR_RPR_220 */

AusExGroveInfraredReflectiveSensor groveIrReflective = AusExGroveInfraredReflectiveSensor(SENSOR_IR_RPR_220_PIN, SENSOR_ID_IR_RPR_220);



/*
 * センサの初期化
 */

bool groveIrReflective_init(void) {
  if (!groveIrReflective.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid Grove IR refrective sensor, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void groveIrReflective_output_info(void) {
  sensor_t sensor;
  groveIrReflective.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * IR refrective sensor RPR220
 */
void groveIrReflective_Sensor(void) {
  sensors_event_t event;
  if (groveIrReflective.getEvent(&event)) {
    if (isnan(event.value)) {
      syslog.log(LOG_ERR, F("Error reading Grove IR refrective sensor!"));
    } else {
#if defined(USE_NTP) || defined(USE_RTC)
      event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
      outputDevice.EventOutput(event);
      syslog.logf(LOG_INFO, "Grove IR refrective = %u",event.value);
    }
  } else {
    syslog.log(LOG_ERR, F("Error reading Grove IR refrective sensor!"));
  }
}

#endif /* USE_SENSOR_IR_RPR_220 */

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



#ifdef USE_SENSOR_GROVE_MOISTURE
#include "AusExGroveSimpleMoisture.h"

#ifndef SENSOR_ID_GROVE_MOISTURE
#define SENSOR_ID_GROVE_MOISTURE -1
#endif /* SENSOR_ID_GROVE_MOISTURE */

AusExGroveSimpleMoisture groveAnalogMoisture = AusExGroveSimpleMoisture(SENSOR_GROVE_MOISTURE_PIN, (int32_t)SENSOR_ID_GROVE_MOISTURE);

/*
 * センサの初期化
 */
bool groveAnalogMoisture_init(void) {
  if (!groveAnalogMoisture.begin()){
    syslog.log(LOG_CRIT, "Could not initialize analog moisture sensor, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void groveAnalogMoisture_output_info(void) {
  sensor_t sensor;
  groveAnalogMoisture.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * センサ読み取り
 */
void groveAnalogMoisture_Sensor(void) {
  sensors_event_t event;
  if (groveAnalogMoisture.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "grove analog moisture = %u",event.value);
  } else {
    syslog.log(LOG_ERR, F("Error reading grove analog moisture sensor!"));
  }
}
#endif /* USE_SENSOR_GROVE_MOISTURE */





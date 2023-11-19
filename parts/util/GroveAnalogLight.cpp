
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




#ifdef USE_SENSOR_GROVE_ANALOG_LIGHT
#include "AusExGroveSimpleLight.h"

#ifndef SENSOR_ID_GROVE_ANALOG_LIGHT
#define SENSOR_ID_GROVE_ANALOG_LIGHT  -1
#endif /* SENSOR_ID_GROVE_ANALOG_LIGHT */

AusExGroveSimpleLight groveAnalogLight = AusExGroveSimpleLight(SENSOR_GROVE_ANALOG_LIGHT_PIN, (int32_t) SENSOR_ID_GROVE_ANALOG_LIGHT);

/*
 * センサの初期化
 */
bool groveAnalogLight_init(void) {
  if (!groveAnalogLight.begin()){
    syslog.log(LOG_CRIT, "Could not initialize analog light sensor, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void groveAnalogLight_output_info(void) {
  sensor_t sensor;
  groveAnalogLight.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * センサ読み取り
 */
void groveAnalogLight_Sensor(void) {
  sensors_event_t event;
  if (groveAnalogLight.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "grove analog light = %u",event.value);
  } else {
    syslog.log(LOG_ERR, F("Error reading analog light sensor!"));
  }
}


#endif /* USE_SENSOR_GROVE_ANALOG_LIGHT */



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

#ifdef USE_SENSOR_GROVE_CURRENT
#include "AusExGroveAnalogCurrentSensor.h"

#ifndef SENSOR_ID_GROVE_CURRENT
#define SENSOR_ID_GROVE_CURRENT  -1
#endif /* SENSOR_ID_GROVE_CURRENT */

AusExGroveAnalogCurrentSensor groveCurrent = AusExGroveAnalogCurrentSensor(SENSOR_GROVE_CURRENT_PIN, (float)SENSOR_GROVE_CURRENT_VDD, (int32_t) SENSOR_ID_GROVE_CURRENT);

/*
 * センサの初期化
 */
bool groveCurrent_init(void) {
  if (!groveCurrent.begin()){
    syslog.log(LOG_CRIT, "Could not initialize Grove current sensor, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void groveCurrent_output_info(void) {
  sensor_t sensor;
  groveCurrent.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * センサ読み取り
 */
void groveCurrent_Sensor(void) {
  if (1 != groveCurrent.setMode(SENSOR_GROVE_CURRENT_MODE)) {
    syslog.log(LOG_ERR, F("Error setting Grove current sensor mode!"));
    return;
  }
  sensors_event_t event;
  if (groveCurrent.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "grove analog current = %f",event.current);
  } else {
   syslog.log(LOG_ERR, F("Error reading Grove current sensor!"));
  }
}

#endif /* USE_SENSOR_GROVE_CURRENT */

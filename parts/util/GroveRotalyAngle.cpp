
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

#ifdef USE_SENSOR_GROVE_ANALOG_ROTALY_ANGLE
#include "AusExGroveRotaryAngleSensor.h"

#ifndef SENSOR_ID_GROVE_ROTALY_ANGLE
#define SENSOR_ID_GROVE_ROTALY_ANGLE  -1
#endif /* SENSOR_ID_GROVE_ROTALY_ANGLE */

AusExGroveRotaryAngleSensor groveAnalogRotalyAngle = AusExGroveRotaryAngleSensor(SENSOR_GROVE_ROTALY_ANGLE_PIN, (float)SENSOR_GROVE_ROTALY_ANGLE_VDD, SENSOR_ID_GROVE_ROTALY_ANGLE);

/*
 * センサの初期化
 */
bool groveAnalogRotalyAngle_init(void) {
  if (!groveAnalogRotalyAngle.begin()){
    syslog.log(LOG_CRIT, "Could not initialize analog rotaly angle sensor, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void groveAnalogRotalyAngle_output_info(void) {
  sensor_t sensor;
  groveAnalogRotalyAngle.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * センサ読み取り
 */
void groveAnalogRotalyAngle_Sensor(void) {
  sensors_event_t event;
  if (groveAnalogRotalyAngle.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "grove analog rotaly angle = %f",event.angle);
  } else {
    syslog.log(LOG_ERR, F("Error reading grove rotaly angle sensor!"));
  }
}


#endif /* USE_SENSOR_GROVE_ANALOG_ROTALY_ANGLE */


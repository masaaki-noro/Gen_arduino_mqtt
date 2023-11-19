
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


#ifdef USE_SENSOR_ANALOG_TEMPERATURE
#include "AusExGroveAnalogTemperatureSensor.h"

#ifndef SENSOR_ID_GROVE_ANALOG_TEMPERATURE
#define SENSOR_ID_GROVE_ANALOG_TEMPERATURE -1
#endif /* SENSOR_ID_GROVE_ANALOG_TEMPERATURE */

AusExGroveAnalogTemperature groveTemperatureSensor=AusExGroveAnalogTemperature(SENSOR_GROVE_ANALOG_TEMPERATURE_PIN, SENSOR_ID_GROVE_ANALOG_TEMPERATURE);



/*
 * センサの初期化
 */
bool groveAnalogTemperature_init(void) {
  if (!groveTemperatureSensor.begin()){
    syslog.log(LOG_CRIT, "Could not initialize analog temperature sensor, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void groveAnalogTemperature_output_info(void) {
  sensor_t sensor;
  groveTemperatureSensor.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * センサ読み取り
 */
void groveAnalogTemperature_Sensor(void) {
  sensors_event_t event;
  if (groveTemperatureSensor.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "grove analog temperature sensor = %f",event.temperature);
  } else {
    syslog.log(LOG_ERR, F("Error reading analog temperature sensor!"));
  }
}


#endif /* USE_SENSOR_ANALOG_TEMPERATURE */



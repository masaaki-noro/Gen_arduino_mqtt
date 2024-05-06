
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

#ifdef USE_SENSOR_TCS34725
#include "AusExTCS34725.h"

#ifndef SENSOR_ID_TCS34725
#define SENSOR_ID_TCS34725  -1
#endif /* SENSOR_ID_TCS34725 */

AUSEX_TCS34725_CLASS tcs34725=AUSEX_TCS34725_CLASS(&I2C_IF, SENSOR_ID_TCS34725);

/*
 * センサの初期化
 */
bool tcs34725_init(void) {
  if (!tcs34725.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid TCS34725 sensor, check wiring!");
    return false;
  }
  if (0==tcs34725.setMode(tcs34725.generateMode(TCS34725_GAIN,TCS34725_INTEGRATIONTIME))) {
    syslog.log(LOG_ERR, F("Error change TCS34725 parameter!"));
  }
  return true;
}

/*
 * センサ情報の出力
 */
void tcs34725_output_info(void) {
  sensor_t sensor;
  tcs34725.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * TCS34725色センサ
 */
void tcs34725_Sensor(void) {
  sensors_event_t event;
  if (tcs34725.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "TCS34725 R                : %f",event.color.r);
    syslog.logf(LOG_INFO, "TCS34725 G                : %f",event.color.g);
    syslog.logf(LOG_INFO, "TCS34725 B                : %f",event.color.b);
    syslog.logf(LOG_INFO, "TCS34725 RGBA             : %u",event.color.rgba);
    syslog.logf(LOG_INFO, "TCS34725 ColorTemperature : %f",tcs34725.calculateColorTemperature());
    syslog.logf(LOG_INFO, "TCS34725 Lux              : %f",tcs34725.calculateLux());
  } else {
    syslog.log(LOG_ERR, F("Error reading TCS34725!"));
  };
}
#endif /* USE_SENSOR_TCS34725 */


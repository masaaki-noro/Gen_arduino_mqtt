
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


#ifdef USE_SENSOR_ADXL335
#include "AusExADXL335.h"

#ifndef SENSOR_ID_ADXL335
#define SENSOR_ID_ADXL335 -1
#endif /* SENSOR_ID_ADXL335 */

AUSEX_ADXL335_CLASS adxl335 = AUSEX_ADXL335_CLASS(SENSOR_ADXL335_X_PIN,SENSOR_ADXL335_Y_PIN,SENSOR_ADXL335_Z_PIN,5.0, AUSEX_ADXL335_ZERO_X, AUSEX_ADXL335_ZERO_Y, AUSEX_ADXL335_ZERO_Z, AUSEX_ADXL335_SENSITIVITY, SENSOR_ID_ADXL335);


/*
 * センサの初期化
 */
bool adxl335_init(void) {
  if (!adxl335.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid ADXL335 sensor, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void adxl335_output_info(void) {
  sensor_t sensor;
  adxl335.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}


void adxl335_Sensor(void) {
  sensors_event_t event;
  if (adxl335.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "adxl335 x = %f",event.acceleration.x);
    syslog.logf(LOG_INFO, "adxl335 y = %f",event.acceleration.y);
    syslog.logf(LOG_INFO, "adxl335 z = %f",event.acceleration.z);
  } else {
    syslog.log(LOG_ERR, F("Error reading ADXL335 sensor!"));
  }
}





#endif /* USE_SENSOR_ADXL335 */

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

#ifdef USE_SENSOR_BMP180
#include "AusExBMP180.h"

#ifndef SENSOR_ID_BMP180
#define SENSOR_ID_BMP180  -1
#endif /* SENSOR_ID_BMP180 */

AUSEX_BMP180_CLASS bmp180=AUSEX_BMP180_CLASS(&Wire,SENSOR_ID_BMP180);

/*
 * センサの初期化
 */
bool bmp180_init(){
  if (!bmp180.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid BMP180 sensor, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void bmp180_output_info() {
  sensor_t sensor;
  bmp180.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * BMP180気圧センサ
 */
void bmp180_Sensor(){
  sensors_event_t event;
  
  bmp180.setMode(BMP180_MODE);

  if (bmp180.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "bmp180 pressure = %f",event.pressure);
    outputDevice.EventOutput(event);
  } else {
    syslog.log(LOG_ERR, F("Error reading sensor BMP180 !"));
  }
}
#endif /* USE_SENSOR_BMP180 */
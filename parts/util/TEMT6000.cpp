
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




#ifdef USE_SENSOR_TEMT6000
#include "AusExTEMT6000.h"

#ifndef SENSOR_ID_TEMT6000
#define SENSOR_ID_TEMT6000  -1
#endif /* SENSOR_ID_TEMT6000 */

AusExTEMT6000 temt6000 = AusExTEMT6000(SENSOR_TEMT6000_PIN, (float)SENSOR_TEMT6000_VDD,(int32_t) SENSOR_ID_TEMT6000);

/*
 * センサの初期化
 */
bool temt6000_init(void) {
  if (!temt6000.begin()){
    syslog.log(LOG_CRIT, "Could not initialize TEMT6000 sensor, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void temt6000_output_info(void) {
  sensor_t sensor;
  temt6000.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * センサ読み取り
 */
void temt6000_Sensor(void) {
  sensors_event_t event;
  if (temt6000.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "TEMT6000 = %f",event.light);
    outputDevice.EventOutput(event);
  } else {
    syslog.log(LOG_ERR, F("Error reading TEMT6000!"));
  }
}


#endif /* USE_SENSOR_TEMT6000 */


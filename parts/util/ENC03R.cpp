

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



#ifdef USE_SENSOR_MURATA_ENC03R // Grove 1軸アナログジャイロ
#include "AusExGroveAnalog1AxisGyro.h"

#ifndef SENSOR_ID_MURATA_ENC03R
#define SENSOR_ID_MURATA_ENC03R -1
#endif /* SENSOR_ID_MURATA_ENC03R */

AusExGroveAnalog1AxisGyro enc03r = AusExGroveAnalog1AxisGyro(SENSOR_MURATA_ENC03R_PIN, (int32_t) SENSOR_ID_MURATA_ENC03R);
float murata_enc03_reference_Value = 0;

/*
 * センサの初期化
 */
bool enc03r_init(void) {
  if (!enc03r.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid Analog single axis gyro (enc03r), check wiring!");
    return false;
  }
#ifdef USE_WDT
  Watchdog.disable();
#endif /* USE_WDT */
  int count=0;
  sensors_event_t event;
  for (int i=0;i<SENSOR_MURATA_ENC03R_TRY;i++){
    if (enc03r.getEvent(&event)) {
      murata_enc03_reference_Value+=event.roll;
      count++;
    }
  }
  murata_enc03_reference_Value=murata_enc03_reference_Value/count;
#ifdef USE_WDT
  int countdownMS = Watchdog.enable(WDT_DURATION);
#endif /* USE_WDT */
  return true;
}


/*
 * センサ情報の出力
 */
void enc03r_output_info(void) {
  sensor_t sensor;
  enc03r.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}


/*
 * センサ読み取り処理
 */
void enc03r_Sensor(void) {
  sensors_event_t event;
  if (enc03r.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    event.roll=event.roll-murata_enc03_reference_Value;
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "analog single axis gyro = %f",event.roll);
  } else {
    syslog.log(LOG_ERR, F("Error reading analog single axis gyro!"));
  }
}


#endif /* USE_SENSOR_MURATA_ENC03R */

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

#ifdef USE_SENSOR_ITG320
#include "AusExGrove3AxisDigitalGyro.h"

#ifndef SENSOR_ID_ITG320
#define SENSOR_ID_ITG320  -1
#endif /* SENSOR_ID_ITG320 */

AusExGrove3AxisDigitalGyro itg320=AusExGrove3AxisDigitalGyro(&Wire,ITG320_SAMPLES,ITG320_SAMPLE_DELAY,SENSOR_ID_ITG320);

/*
 * センサの初期化
 */
bool itg320_init(void) {
#ifdef USE_WDT
  Watchdog.disable();
#endif /* USE_WDT */

  if (!itg320.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid ITG320 3 aixs gyro sensor, check wiring!");
    return false;
  }

#ifdef USE_WDT
  int countdownMS = Watchdog.enable(WDT_DURATION);
#endif /* USE_WDT */

  return true;
}

/*
 * センサ情報の出力
 */
void itg320_output_info(void) {
  sensor_t sensor;
  itg320.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * 3軸ジャイロ
 */
void itg320_Sensor(void) {
  sensors_event_t event;
  if (itg320.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "ITG320 3 aixs gyro x = %f",event.gyro.x);
    syslog.logf(LOG_INFO, "ITG320 3 aixs gyro y = %f",event.gyro.y);
    syslog.logf(LOG_INFO, "ITG320 3 aixs gyro z = %f",event.gyro.z);
  } else {
    syslog.log(LOG_ERR, F("Error reading sensor ITG320 !"));
  }
}
#endif /* USE_SENSOR_ITG320 */
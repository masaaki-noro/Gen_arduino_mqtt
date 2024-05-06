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

#ifdef USE_SENSOR_ITG3200
#include "AusExGrove3AxisDigitalGyro.h"

#ifndef SENSOR_ID_ITG3200
#define SENSOR_ID_ITG3200  -1
#endif /* SENSOR_ID_ITG3200 */

AusExGrove3AxisDigitalGyro itg3200=AusExGrove3AxisDigitalGyro(&I2C_IF,ITG3200_SAMPLES,ITG3200_SAMPLE_DELAY,SENSOR_ID_ITG3200);

/*
 * センサの初期化
 */
bool itg3200_init(void) {
#ifdef USE_WDT
  Watchdog.disable();
#endif /* USE_WDT */

  if (!itg3200.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid ITG3200 3 aixs gyro sensor, check wiring!");
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
void itg3200_output_info(void) {
  sensor_t sensor;
  itg3200.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * 3軸ジャイロ
 */
void itg3200_Sensor(void) {
  sensors_event_t event;
  if (itg3200.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "ITG3200 3 aixs gyro x = %f",event.gyro.x);
    syslog.logf(LOG_INFO, "ITG3200 3 aixs gyro y = %f",event.gyro.y);
    syslog.logf(LOG_INFO, "ITG3200 3 aixs gyro z = %f",event.gyro.z);
  } else {
    syslog.log(LOG_ERR, F("Error reading sensor ITG3200 !"));
  }
}
#endif /* USE_SENSOR_ITG3200 */
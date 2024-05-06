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


#ifdef USE_SENSOR_MMA7660FC // Grove3軸加速度センサ
#include "AusExGrove3AxisDigitalAccelerometer1_5g.h"

#ifndef SENSOR_ID_MMA7660
#define SENSOR_ID_MMA7660  -1
#endif /* SENSOR_ID_MMA7660 */

AusExGrove3AxisDigitalAccelerometer1_5g mma7660=AusExGrove3AxisDigitalAccelerometer1_5g(&I2C_IF,SENSOR_ID_MMA7660);

/*
 * センサの初期化
 */
bool mma7660_init(void) {
  if (!mma7660.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid MMA7660FC 3 aixs accelometer, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void mma7660_output_info(void) {
  sensor_t sensor;
  mma7660.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * MMA7660FC // Grove3軸加速度センサ
 */
void mma7660_Sensor(void) {
  mma7660.setMode(MMA7660FC_SAMPLING_RATE);
#ifdef USE_WDT
  Watchdog.disable();
#endif /* USE_WDT */
  delay(MMA7660FC_SAMPLING_DELAY);
#ifdef USE_WDT
  int countdownMS = Watchdog.enable(WDT_DURATION);
#endif /* USE_WDT */
  sensors_event_t event;
  if (mma7660.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "Grove 3 axis accelerometer x = %f",event.acceleration.x);
    syslog.logf(LOG_INFO, "Grove 3 axis accelerometer y = %f",event.acceleration.y);
    syslog.logf(LOG_INFO, "Grove 3 axis accelerometer z = %f",event.acceleration.z);
    outputDevice.EventOutput(event);
  } else {
    syslog.log(LOG_ERR, F("Error reading Grove 3 axis accelerometer!"));
  }
}

#endif /* USE_SENSOR_MMA7660FC */


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

#ifdef USE_SENSOR_GROVE_I2C_TOUCH // FreeScale - MPR121
#include "AusExGroveI2cTouchSensor.h"

#ifndef SENSOR_ID_MPR121
#define SENSOR_ID_MPR121  -1
#endif /* SENSOR_ID_MPR121 */

AusExGroveI2cTouchSensor mpr121=AusExGroveI2cTouchSensor(&I2C_IF, SENSOR_ID_MPR121);

/*
 * センサの初期化
 */
bool mpr121_init(void) {
  if (!mpr121.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid Grove I2C touch sensor (mpr121), check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void mpr121_output_info(void) {
  sensor_t sensor;
  mpr121.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}


/*
 * Grove I2C タッチセンサ (FreeScale - MPR121)
 */
void mpr121_Sensor(void) {
  sensors_event_t event;
  if (mpr121.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    for (int i=0; i< AUSEX_GROVE_I2C_TOUCH_NUM_OF_SENSORS; i++){
      if (mpr121.getTouchState(event.value,i)) {
        syslog.logf(LOG_INFO, "Grove I2C touch sensor pin no.%d is touched.",i);
      } else {
        syslog.logf(LOG_INFO, "Grove I2C touch sensor pin no.%d is not touched.",i);
      }
    }
  } else {
    syslog.log(LOG_ERR, F("Error reading Grove I2C touch sensor!"));
  }
}
#endif /* USE_SENSOR_GROVE_I2C_TOUCH */

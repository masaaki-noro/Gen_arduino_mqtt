
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

#ifdef USE_SENSOR_TSL2561 // 照度センサ
#include "AusExTSL2561.h"

#ifndef SENSOR_ID_TSL2561
#define SENSOR_ID_TSL2561  -1
#endif /* SENSOR_ID_TSL2561 */

AUSEX_TSL2561_CLASS tsl2561=AUSEX_TSL2561_CLASS(&Wire, (int32_t) SENSOR_ID_TSL2561);


/*
 * センサの初期化
 */


bool tsl2561_init(void) {
  if (!tsl2561.begin(TSL2561_I2C_ADDR)) {
    syslog.log(LOG_CRIT, "Could not find a valid tsl2561 light sensor, check wiring!");
    return false;
  }
  int mode=tsl2561.generateMode(TSL2561_GAIN,TSL2561_INT_TIME);
  tsl2561.setMode(mode);
  return true;
}

/*
 * センサ情報の出力
 */
void tsl2561_output_info(void) {
  sensor_t sensor;
  tsl2561.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * センサ読み取り
 */
void tsl2561_Sensor(void) {
  sensors_event_t event;
  if (tsl2561.getEvent(&event)) {
    syslog.logf(LOG_INFO, "tsl2561 = %f",event.AUSEX_TSL2561_LIGHT_SENSOR_RETURN_VALUE);
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
  } else {
    syslog.log(LOG_ERR, F("Error reading TSL2561 light sensor!"));
  }
}

#endif /* USE_SENSOR_TSL2561 */
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

#ifdef USE_SENSOR_LPS22HB
#include "AusExLPS22HB.h"

#ifndef SENSOR_ID_LPS22HB
#define SENSOR_ID_LPS22HB  -1
#endif /* SENSOR_ID_LPS22HB */

AusExLPS22HB lps22hb=AusExLPS22HB(&I2C_IF,SENSOR_ID_LPS22HB);

/*
 * センサの初期化
 */
bool lps22hb_init(){
#if 0
  if (!lps22hb.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid LPS22HB sensor, check wiring!");
    return false;
  }
#else
  lps22hb.begin();
#endif
  return true;
}

/*
 * センサ情報の出力
 */
void lps22hb_output_info() {
  sensor_t sensor;
  lps22hb.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * LPS22HB気圧センサ
 */
void lps22hb_Sensor(){
  sensors_event_t event;
  
  lps22hb.setMode(AUSEX_LPS22HB_MODE_HPA);

  if (lps22hb.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "lps22hb pressure = %f",event.pressure);
    outputDevice.EventOutput(event);
  } else {
    syslog.log(LOG_ERR, F("Error reading sensor LPS22HB !"));
  }
}
#endif /* USE_SENSOR_LPS22HB */
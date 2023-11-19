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

#ifdef USE_SENSOR_AM232X

#include "AusExAM232X.h"

#ifdef SENSOR_ID_SHT2X_TEMPERATURE
#ifdef SENSOR_ID_SHT2X_HUMIDITY
AusExAM232X am232x = AusExAM232X(&Wire, SENSOR_AM232X_TYPE,SENSOR_ID_AM232X_TEMPERATURE,SENSOR_ID_AM232X_HUMIDITY);
#else /* SENSOR_ID_SHT2X_HUMIDITY */
AusExAM232X am232x = AusExAM232X(&Wire, SENSOR_AM232X_TYPE,SENSOR_ID_AM232X_TEMPERATURE);
#endif /* SENSOR_ID_SHT2X_HUMIDITY */
#else /* SENSOR_ID_SHT2X_TEMPERATURE */
#ifdef SENSOR_ID_SHT2X_HUMIDITY
AusExAM232X am232x = AusExAM232X(&Wire, SENSOR_AM232X_TYPE,,SENSOR_ID_AM232X_HUMIDITY);
#else /* SENSOR_ID_SHT2X_HUMIDITY */
AusExAM232X am232x = AusExAM232X(&Wire, SENSOR_AM232X_TYPE);
#endif /* SENSOR_ID_SHT2X_HUMIDITY */
#endif /* SENSOR_ID_SHT2X_TEMPERATURE */

/*
 * センサの初期化
 */
bool am232x_init(){
  if (!am232x.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid AM232X sensor, check wiring!");
    return false;
  }
#ifdef USE_WDT
  Watchdog.disable();
#endif /* USE_WDT */
  delay(AUSEX_AM232X_SENSOR_HUMIDITY_MIN_DELAY/1000);
#ifdef USE_WDT
  int countdownMS = Watchdog.enable(WDT_DURATION);
#endif /* USE_WDT */
  return true;
}

/*
 * センサ情報の出力
 */
void am232x_output_info() {
  sensor_t sensor;
  am232x.temperature().getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
  am232x.humidity().getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * AM232X温湿度センサ
 */
void am232x_Sensor(){
  sensors_event_t event;
  // Get humidity event and print its value.
  am232x.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    syslog.log(LOG_ERR, F("Error reading humidity!"));
  } else {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "am232x humidity = %f",event.relative_humidity);
    outputDevice.EventOutput(event);
  }
  // Get temperature event and print its value.
  am232x.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    syslog.log(LOG_ERR, F("Error reading temperature!"));
  } else {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "am232x temperature = %f",event.temperature);
    outputDevice.EventOutput(event);
  }
}

#endif /* USE_SENSOR_AM232X */
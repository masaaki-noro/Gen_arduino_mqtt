
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

#ifdef USE_SENSOR_SHT2X
#include "AusExSHT2x.h"

#ifdef SENSOR_ID_SHT2X_TEMPERATURE
#ifdef SENSOR_ID_SHT2X_HUMIDITY
AusExSHT2x sht2x = AusExSHT2x(&Wire, SENSOR_SHT2X_TYPE,SENSOR_ID_SHT2X_TEMPERATURE,SENSOR_ID_SHT2X_HUMIDITY);
#else /* SENSOR_ID_SHT2X_HUMIDITY */
AusExSHT2x sht2x = AusExSHT2x(&Wire, SENSOR_SHT2X_TYPE,SENSOR_ID_SHT2X_TEMPERATURE);
#endif /* SENSOR_ID_SHT2X_HUMIDITY */
#else /* SENSOR_ID_SHT2X_TEMPERATURE */
#ifdef SENSOR_ID_SHT2X_HUMIDITY
AusExSHT2x sht2x = AusExSHT2x(&Wire, SENSOR_SHT2X_TYPE,,SENSOR_ID_SHT2X_HUMIDITY);
#else /* SENSOR_ID_SHT2X_HUMIDITY */
AusExSHT2x sht2x = AusExSHT2x(&Wire, SENSOR_SHT2X_TYPE);
#endif /* SENSOR_ID_SHT2X_HUMIDITY */
#endif /* SENSOR_ID_SHT2X_TEMPERATURE */

/*
 * センサの初期化
 */
bool sht2x_init(){
  if (!sht2x.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid SHT2X sensor, check wiring!");
    return false;
  }
#ifdef USE_WDT
  Watchdog.disable();
#endif /* USE_WDT */
  delay(AUSEX_SHT2X_SENSOR_INIT_DELAY);
#ifdef USE_WDT
  int countdownMS = Watchdog.enable(WDT_DURATION);
#endif /* USE_WDT */
  return true;
}

/*
 * センサ情報の出力
 */
void sht2x_output_info() {
  sensor_t sensor;
  sht2x.temperature().getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
  sht2x.humidity().getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}


/*
 * SHT2X 温湿度センサ
 */

void sht2x_Sensor(){
  sensors_event_t event;
  // Get humidity event and print its value.
  sht2x.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    syslog.log(LOG_ERR, F("Error reading sht2x humidity!"));
  } else {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "sht2x humidity = %f",event.relative_humidity);
    outputDevice.EventOutput(event);
  }
  // Get temperature event and print its value.
  sht2x.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    syslog.log(LOG_ERR, F("Error reading sht2x temperature!"));
  } else {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "sht2x temperature = %f",event.temperature);
    outputDevice.EventOutput(event);
  }
}

#endif /* USE_SENSOR_SHT2X */

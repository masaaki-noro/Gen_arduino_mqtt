
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

#ifdef USE_SENSOR_SHT31
#include "AusExSHT31.h"

#ifdef SENSOR_ID_SHT31_TEMPERATURE
#ifdef SENSOR_ID_SHT31_HUMIDITY
AusExSHT31 sht31 = AusExSHT31(&I2C_IF, SENSOR_ID_SHT31_TEMPERATURE,SENSOR_ID_SHT31_HUMIDITY);
#else /* SENSOR_ID_SHT31_HUMIDITY */
AusExSHT31 sht31 = AusExSHT31(&I2C_IF, SENSOR_ID_SHT31_TEMPERATURE);
#endif /* SENSOR_ID_SHT31_HUMIDITY */
#else /* SENSOR_ID_SHT31_TEMPERATURE */
#ifdef SENSOR_ID_SHT31_HUMIDITY
AusExSHT31 sht31 = AusExSHT31(&I2C_IF, ,SENSOR_ID_SHT31_HUMIDITY);
#else /* SENSOR_ID_SHT31_HUMIDITY */
AusExSHT31 sht31 = AusExSHT31(&I2C_IF);
#endif /* SENSOR_ID_SHT31_HUMIDITY */
#endif /* SENSOR_ID_SHT31_TEMPERATURE */

/*
 * センサの初期化
 */
bool sht31_init(){
  if (!sht31.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid SHT31 sensor, check wiring!");
    return false;
  }
#ifdef USE_WDT
  Watchdog.disable();
#endif /* USE_WDT */
  delay(AUSEX_SHT31_SENSOR_HUMIDITY_MIN_DELAY/1000);
#ifdef USE_WDT
  int countdownMS = Watchdog.enable(WDT_DURATION);
#endif /* USE_WDT */
  return true;
}

/*
 * センサ情報の出力
 */
void sht31_output_info() {
  sensor_t sensor;
  sht31.temperature().getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
  sht31.humidity().getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}


/*
 * SHT31 温湿度センサ
 */

void sht31_Sensor(){
  sensors_event_t event;
  sht31.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    syslog.log(LOG_ERR, F("Error reading sht31 temperature!"));
  } else {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "sht31 temperature = %f",event.temperature);
    outputDevice.EventOutput(event);
  }
  // Get humidity event and print its value.
  sht31.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    syslog.log(LOG_ERR, F("Error reading sht31 humidity!"));
  } else {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "sht31 humidity = %f",event.relative_humidity);
    outputDevice.EventOutput(event);
  }
}

#endif /* USE_SENSOR_SHT31 */

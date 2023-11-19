
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


#ifdef USE_SENSOR_PIR
#include "AusExGrovePirSensor.h"

#ifndef SENSOR_ID_PIR
#define SENSOR_ID_PIR  -1
#endif /* SENSOR_ID_PIR */

AusExGrovePirSensor pir = AusExGrovePirSensor(SENSOR_PIR_PIN, SENSOR_ID_PIR);

/*
 * センサの初期化
 */
bool pir_init(void) {
  if (!pir.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid PIR sensor, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void pir_output_info(void) {
  sensor_t sensor;
  pir.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
#ifdef USE_WDT
  Watchdog.disable();
#endif /* USE_WDT */
  delay(sensor.init_delay/1000);
#ifdef USE_WDT
  int countdownMS = Watchdog.enable(WDT_DURATION);
#endif /* USE_WDT */
}

/*
 * 人感センサー (Grove PIR sensor)
 */
void pir_Sensor(void) {
  sensors_event_t event;
  if (pir.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
      event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "PIR sensor = %u",event.value);
  } else {
    syslog.log(LOG_ERR, F("Error reading PIR sensor!"));
  }
}

#endif /* USE_SENSOR_PIR */




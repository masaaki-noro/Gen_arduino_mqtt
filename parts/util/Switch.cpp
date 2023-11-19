
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

#ifdef USE_SENSOR_DIGITAL_SWITCH
#include "AusExDigitalSwitch.h"

#ifndef SENSOR_ID_DIGITAL_SWITCH
#define SENSOR_ID_DIGITAL_SWITCH -1
#endif /* SENSOR_ID_DIGITAL_SWITCH */

AusExGroveSwitch digitalSwitch = AusExGroveSwitch(SENSOR_DIGITAL_SWITCH_PIN, SENSOR_ID_DIGITAL_SWITCH);

/*
 * センサの初期化
 */
bool digitalSwitch_init(void) {
  if (!digitalSwitch.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid digital switch, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void digitalSwitch_output_info(void) {
  sensor_t sensor;
  digitalSwitch.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}


void digitalSwitch_Sensor(void) {
  sensors_event_t event;
  if (digitalSwitch.getEvent(&event)) {
    if (isnan(event.value)) {
      syslog.log(LOG_ERR, F("Error reading digital switch!"));
    } else {
#if defined(USE_NTP) || defined(USE_RTC)
      event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
      syslog.logf(LOG_INFO, "switch = %u",event.value);
      outputDevice.EventOutput(event);
    }
  } else {
    syslog.log(LOG_ERR, F("Error reading digital switch!"));
  }
}

#endif /* USE_SENSOR_DIGITAL_SWITCH */
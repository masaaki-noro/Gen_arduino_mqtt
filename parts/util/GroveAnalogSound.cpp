
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


#ifdef USE_SENSOR_GROVE_ANALOG_SOUND
#include "AusExGroveSimpleSound.h"

#ifndef SENSOR_ID_GROVE_ANALOG_SOUND
#define SENSOR_ID_GROVE_ANALOG_SOUND  -1
#endif /* SENSOR_ID_GROVE_ANALOG_SOUND */

GroveSimpleSoundAusEx groveAnalogSound = GroveSimpleSoundAusEx(SENSOR_GROVE_SOUND_PIN, (int32_t) SENSOR_ID_GROVE_ANALOG_SOUND);

/*
 * センサの初期化
 */
bool groveAnalogSound_init(void) {
  if (!groveAnalogSound.begin()){
    syslog.log(LOG_CRIT, "Could not initialize analog sound sensor, check wiring!");
    return false;
  }
  return true;
}

/*
 * センサ情報の出力
 */
void groveAnalogSound_output_info(void) {
  sensor_t sensor;
  groveAnalogSound.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * センサ読み取り
 */
void groveAnalogSound_Sensor(void) {
  sensors_event_t event;
  if (groveAnalogSound.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    outputDevice.EventOutput(event);
    syslog.logf(LOG_INFO, "grove analog sound = %u",event.value);
  } else {
    syslog.log(LOG_ERR, F("Error reading Grove analog sound sensor!"));
  }
}


#endif /* USE_SENSOR_GROVE_ANALOG_SOUND */


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

#ifdef USE_SENSOR_ADXL345 // 3軸加速度センサー Grove 3軸加速度センサ 16g
#include "AusExADXL345.h"

#ifndef SENSOR_ID_ADXL345
#define SENSOR_ID_ADXL345 -1
#endif /* SENSOR_ID_ADXL345 */

#if !defined(ADXL_INTER_I2C) && !defined(ADXL_INTER_HARD_SPI) && !defined(ADXL_INTER_SOFT_SPI)
#error "interface of ADXL345 is not defined."
#endif
#ifdef ADXL_INTER_I2C
AusExADXL345 adxl345 = AusExADXL345(&I2C_IF, SENSOR_ID_ADXL345);
#endif /* ADXL_INTER_I2C */
#ifdef ADXL_INTER_HARD_SPI
AusExADXL345 adxl345 = AusExADXL345(0xFF, 0, 0, ADXL345_CS, SENSOR_ID_ADXL345);
#endif /* ADXL_INTER_HARD_SPI */
#ifdef ADXL_INTER_SOFT_SPI
AusExADXL345 adxl345 = AusExADXL345(ADXL345_SCK, ADXL345_MISO, ADXL345_MOSI, ADXL345_CS, SENSOR_ID_ADXL345);
#endif /* ADXL_INTER_SOFT_SPI */

/*
 * センサの初期化
 */
bool adxl345_init(void) {
  if (!adxl345.begin()) {
    syslog.log(LOG_CRIT, "Could not find a valid ADXL345 sensor, check wiring!");
    return false;
  }
  adxl345.setMode(adxl345.getModeParam(ADXL345_RANGE,ADXL345_DATA_RATE));
  return true;
}

/*
 * センサ情報の出力
 */
void adxl345_output_info(void) {
  sensor_t sensor;
  adxl345.getSensor(&sensor);
  outputDevice.InfoOutput(sensor);
}

/*
 * ADXL345 3軸加速度センサ
 */
void adxl345_Sensor(void) {
  sensors_event_t event;
  if (adxl345.getEvent(&event)) {
#if defined(USE_NTP) || defined(USE_RTC)
    event.timestamp = currentTime;
#endif /* USE_NTP or USE_RTC */
    syslog.logf(LOG_INFO, "adxl345 x = %f",event.acceleration.x);
    syslog.logf(LOG_INFO, "adxl345 y = %f",event.acceleration.y);
    syslog.logf(LOG_INFO, "adxl345 z = %f",event.acceleration.z);
    outputDevice.EventOutput(event);
  } else {
    syslog.log(LOG_ERR, F("Error reading sensor ADXL345 !"));
  }
}

#endif /* USE_SENSOR_ADXL345 */
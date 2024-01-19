#include "config.h"
#include "sensor.h"

#ifdef USE_WDT
#include <Adafruit_SleepyDog.h>
#endif /* USE_WDT */

bool init_sensors(void) {

// I2C , SPI interface sensors
#ifdef USE_SENSOR_SHT31
  use_SHT31 = sht31_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_SHT31 */

#ifdef USE_SENSOR_SHT2X
  use_SHT2X = sht2x_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_SHT2X */

#ifdef USE_SENSOR_AM232X
  use_AM232X = am232x_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_AM232X */

#ifdef USE_SENSOR_BME280
  use_BME280 = bme280_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_BME280 */

#ifdef USE_SENSOR_BMP180
  use_BMP180 = bmp180_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_BMP180 */

#ifdef USE_SENSOR_ADSX345 // 3軸加速度センサー Grove 3軸加速度センサ 16g
  use_ADXL345 = adxl345_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_ADSX345 */

#ifdef USE_SENSOR_ITG3200
  use_ITG3200 = itg3200_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_ITG3200 */

#ifdef USE_SENSOR_MMA7660FC // Grove3軸加速度センサ
  use_MMA7660 = mma7660_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_MMA7660FC */

#ifdef USE_SENSOR_GROVE_I2C_TOUCH // FreeScale - MPR121
  use_MPR121 = mpr121_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_I2C_TOUCH */

#ifdef USE_SENSOR_TCS34725
  use_TCS34725 = tcs34725_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_TCS34725 */

#ifdef USE_SENSOR_TSL2561 // 照度センサ
  use_TSL2561 = tsl2561_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_TSL2561 */

#ifdef USE_SENSOR_HTS221 // 温湿度センサ
  use_HTS221 = hts221_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_HTS221 */

#ifdef USE_SENSOR_LPS22HB // 気圧センサ
  use_LPS22HB = lps22hb_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_LPS22HB */

// digital interface sensors
#ifdef USE_SENSOR_DHT
  use_DHT = dht_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_DHT */

#ifdef USE_SENSOR_DIGITAL_SWITCH
  use_digitalSwitch = digitalSwitch_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_DIGITAL_SWITCH */

#ifdef USE_SENSOR_TOUCH
  use_GroveTouch = groveTouch_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_TOUCH */

#ifdef USE_SENSOR_WATER_DETECTION
  use_GroveWaterDetection = groveWaterDetection_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_WATER_DETECTION */

#ifdef USE_SENSOR_LINE_FINDER
  use_GroveLineFinder = groveLineFinder_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_LINE_FINDER */

#ifdef USE_SENSOR_IR_DISTANCE_INTERRUPTER
  use_GroveIrDistance = groveIrDistance_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_IR_DISTANCE_INTERRUPTER */

#ifdef USE_SENSOR_IR_RPR_220  // Grove - Infrared Reflective Sensor
  use_GroveIrReflective = groveIrReflective_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_IR_RPR_220 */

#ifdef USE_SENSOR_PIR
  use_PIR = pir_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_PIR */


// analog interface sensors
#ifdef USE_SENSOR_ADXL335
  use_ADXL335 = adxl335_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_ADXL335 */

#ifdef USE_SENSOR_MURATA_ENC03R // Grove 1軸アナログジャイロ
  use_ENC03R = enc03r_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_MURATA_ENC03R */

#ifdef USE_SENSOR_ANALOG_TEMPERATURE
  use_GroveAnalogTemperature = groveAnalogTemperature_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_ANALOG_TEMPERATURE */

#ifdef USE_SENSOR_GROVE_ANALOG_ROTARY_ANGLE
  use_GroveAnalogRotaryAngle = groveAnalogRotaryAngle_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_ANALOG_ROTARY_ANGLE */

#ifdef USE_SENSOR_GROVE_ANALOG_LIGHT
  use_GroveAnalogLight = groveAnalogLight_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_ANALOG_LIGHT */

#ifdef USE_SENSOR_GROVE_ANALOG_SOUND
  use_GroveAnalogSound = groveAnalogSound_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_ANALOG_SOUND */

#ifdef USE_SENSOR_GROVE_MOISTURE
  use_GroveAnalogMoisture = groveAnalogMoisture_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_MOISTURE */

#ifdef USE_SENSOR_GROVE_GSR
  use_GroveGSR = groveGSR_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_GSR */

#ifdef USE_SENSOR_GROVE_CURRENT
  use_GroveCurrent = groveCurrent_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_CURRENT */

#ifdef USE_SENSOR_TEMT6000 // 照度センサ
  use_TEMT6000 = temt6000_init();
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_TEMT6000 */

  bool total=false;

// I2C , SPI interface sensors
#ifdef USE_SENSOR_SHT31
  total |= use_SHT31;
#endif /* USE_SENSOR_SHT31 */

#ifdef USE_SENSOR_SHT2X
  total |= use_SHT2X;
#endif /* USE_SENSOR_SHT2X */

#ifdef USE_SENSOR_AM232X
  total |= use_AM232X;
#endif /* USE_SENSOR_AM232X */

#ifdef USE_SENSOR_BME280
  total |= use_BME280;
#endif /* USE_SENSOR_BME280 */

#ifdef USE_SENSOR_BMP180
  total |= use_BMP180;
#endif /* USE_SENSOR_BMP180 */

#ifdef USE_SENSOR_ADSX345 // 3軸加速度センサー Grove 3軸加速度センサ 16g
  total |= use_ADXL345;
#endif /* USE_SENSOR_ADSX345 */

#ifdef USE_SENSOR_ITG3200
  total |= use_ITG3200;
#endif /* USE_SENSOR_ITG320 */

#ifdef USE_SENSOR_MMA7660FC // Grove3軸加速度センサ
  total |= use_MMA7660;
#endif /* USE_SENSOR_MMA7660FC */

#ifdef USE_SENSOR_GROVE_I2C_TOUCH // FreeScale - MPR121
  total |= use_MPR121;
#endif /* USE_SENSOR_GROVE_I2C_TOUCH */

#ifdef USE_SENSOR_TCS34725
  total |= use_TCS34725;
#endif /* USE_SENSOR_TCS34725 */

#ifdef USE_SENSOR_TSL2561 // 照度センサ
  total |= use_TSL2561;
#endif /* USE_SENSOR_TSL2561 */

#ifdef USE_SENSOR_HTS221 // 温湿度センサ
  total |= use_HTS221;
#endif /* USE_SENSOR_HTS221 */

#ifdef USE_SENSOR_LPS22HB // 気圧センサ
  total |= use_LPS22HB;
#endif /* USE_SENSOR_LPS22HB */


// digital interface sensors
#ifdef USE_SENSOR_DHT
  total |= use_DHT;
#endif /* USE_SENSOR_DHT */

#ifdef USE_SENSOR_DIGITAL_SWITCH
  total |= use_digitalSwitch;
#endif /* USE_SENSOR_DIGITAL_SWITCH */

#ifdef USE_SENSOR_TOUCH
  total |= use_GroveTouch;
#endif /* USE_SENSOR_TOUCH */

#ifdef USE_SENSOR_WATER_DETECTION
  total |= use_GroveWaterDetection;
#endif /* USE_SENSOR_WATER_DETECTION */

#ifdef USE_SENSOR_LINE_FINDER
  total |= use_GroveLineFinder;
#endif /* USE_SENSOR_LINE_FINDER */

#ifdef USE_SENSOR_IR_DISTANCE_INTERRUPTER
  total |= use_GroveIrDistance;
#endif /* USE_SENSOR_IR_DISTANCE_INTERRUPTER */

#ifdef USE_SENSOR_IR_RPR_220  // Grove - Infrared Reflective Sensor
  total |= use_GroveIrReflective;
#endif /* USE_SENSOR_IR_RPR_220 */

#ifdef USE_SENSOR_PIR
  total |= use_PIR;
#endif /* USE_SENSOR_PIR */

// analog interface sensors
#ifdef USE_SENSOR_ADXL335
  total |= use_ADXL335;
#endif /* USE_SENSOR_ADXL335 */

#ifdef USE_SENSOR_MURATA_ENC03R // Grove 1軸アナログジャイロ
  total |= use_ENC03R;
#endif /* USE_SENSOR_MURATA_ENC03R */

#ifdef USE_SENSOR_ANALOG_TEMPERATURE
  total |= use_GroveAnalogTemperature;
#endif /* USE_SENSOR_ANALOG_TEMPERATURE */

#ifdef USE_SENSOR_GROVE_ANALOG_ROTARY_ANGLE
  total |= use_GroveAnalogRotaryAngle;
#endif /* USE_SENSOR_GROVE_ANALOG_ROTARY_ANGLE */

#ifdef USE_SENSOR_GROVE_ANALOG_LIGHT
  total |= use_GroveAnalogLight;
#endif /* USE_SENSOR_GROVE_ANALOG_LIGHT */

#ifdef USE_SENSOR_GROVE_ANALOG_SOUND
  total |= use_GroveAnalogSound;
#endif /* USE_SENSOR_GROVE_ANALOG_SOUND */

#ifdef USE_SENSOR_GROVE_MOISTURE
  total |= use_GroveAnalogMoisture;
#endif /* USE_SENSOR_GROVE_MOISTURE */

#ifdef USE_SENSOR_GROVE_GSR
  total |= use_GroveGSR;
#endif /* USE_SENSOR_GROVE_GSR */

#ifdef USE_SENSOR_GROVE_CURRENT
  total |= use_GroveCurrent;
#endif /* USE_SENSOR_GROVE_CURRENT */

#ifdef USE_SENSOR_TEMT6000 // 照度センサ
  total |= use_TEMT6000;
#endif /* USE_SENSOR_TEMT6000 */

  return total;
}

void output_sensors_info(void) {

// I2C and SPI interface sensors
#ifdef USE_SENSOR_SHT31
  if (use_SHT31) {
    sht31_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_SHT31 */

#ifdef USE_SENSOR_SHT2X
  if (use_SHT2X) {
    sht2x_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_SHT2X */

#ifdef USE_SENSOR_AM232X
  if (use_AM232X) {
    am232x_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_AM232X */

#ifdef USE_SENSOR_BME280
  if (use_BME280) {
    bme280_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_BME280 */


#ifdef USE_SENSOR_BMP180
  if (use_BMP180) {
    bmp180_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_BMP180 */

#ifdef USE_SENSOR_ADSX345 // 3軸加速度センサー Grove 3軸加速度センサ 16g
  if (use_ADXL345) {
    adxl345_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_ADSX345 */

#ifdef USE_SENSOR_ITG3200
  if (use_ITG3200) {
    itg3200_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_ITG3200 */

#ifdef USE_SENSOR_MMA7660FC // Grove3軸加速度センサ
  if (use_MMA7660) {
    mma7660_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_MMA7660FC */

#ifdef USE_SENSOR_GROVE_I2C_TOUCH // FreeScale - MPR121
  if (use_MPR121) {
    mpr121_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_I2C_TOUCH */

#ifdef USE_SENSOR_TCS34725
  if (use_TCS34725) {
    tcs34725_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_TCS34725 */

#ifdef USE_SENSOR_TSL2561 // 照度センサ
  if (use_TSL2561) {
    tsl2561_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_TSL2561 */

#ifdef USE_SENSOR_HTS221 // 温湿度センサ
  if (use_HTS221) {
    hts221_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_HTS221 */

#ifdef USE_SENSOR_LPS22HB // 気圧センサ
  if (use_LPS22HB) {
    lps22hb_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_LPS22HB */

// digital interface sensors
#ifdef USE_SENSOR_DHT
  if (use_DHT) {
    dht_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_DHT */

#ifdef USE_SENSOR_DIGITAL_SWITCH
  if (use_digitalSwitch) {
    digitalSwitch_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_DIGITAL_SWITCH */

#ifdef USE_SENSOR_TOUCH
  if (use_GroveTouch) {
    groveTouch_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_TOUCH */

#ifdef USE_SENSOR_WATER_DETECTION
  if (use_GroveWaterDetection) {
    groveWaterDetection_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_WATER_DETECTION */

#ifdef USE_SENSOR_LINE_FINDER
  if (use_GroveLineFinder) {
    groveLineFinder_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_LINE_FINDER */

#ifdef USE_SENSOR_IR_DISTANCE_INTERRUPTER
  if (use_GroveIrDistance) {
    groveIrDistance_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_IR_DISTANCE_INTERRUPTER */

#ifdef USE_SENSOR_IR_RPR_220  // Grove - Infrared Reflective Sensor
  if (use_GroveIrReflective) {
    groveIrReflective_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_IR_RPR_220 */

#ifdef USE_SENSOR_PIR
  if (use_PIR) {
    pir_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_PIR */

// analog interface sensors
#ifdef USE_SENSOR_ADXL335
  if (use_ADXL335) {
    adxl335_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_ADXL335 */

#ifdef USE_SENSOR_MURATA_ENC03R
  if (use_ENC03R) {
    enc03r_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_MURATA_ENC03R */

#ifdef USE_SENSOR_ANALOG_TEMPERATURE
  if (use_GroveAnalogTemperature) {
    groveAnalogTemperature_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_ANALOG_TEMPERATURE */

#ifdef USE_SENSOR_GROVE_ANALOG_ROTARY_ANGLE
  if (use_GroveAnalogRotaryAngle) {
    groveAnalogRotaryAngle_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_ANALOG_ROTARY_ANGLE */

#ifdef USE_SENSOR_GROVE_ANALOG_LIGHT
  if (use_GroveAnalogLight) {
    groveAnalogLight_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_ANALOG_LIGHT */

#ifdef USE_SENSOR_GROVE_ANALOG_SOUND
  if (use_GroveAnalogSound) {
    groveAnalogSound_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_ANALOG_SOUND */

#ifdef USE_SENSOR_GROVE_MOISTURE
  if (use_GroveAnalogMoisture) {
    groveAnalogMoisture_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_MOISTURE */

#ifdef USE_SENSOR_GROVE_GSR
  if (use_GroveGSR) {
    groveGSR_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_GSR */

#ifdef USE_SENSOR_GROVE_CURRENT
  if (use_GroveCurrent) {
    groveCurrent_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_CURRENT */

#ifdef USE_SENSOR_TEMT6000 // 照度センサ
  if (use_TEMT6000) {
    temt6000_output_info();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_TEMT6000 */

}

void process_sensors(void) {

// I2C, SPI intarface sensors
#ifdef USE_SENSOR_SHT31
  if (use_SHT31) {
    sht31_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_SHT31 */

#ifdef USE_SENSOR_SHT2X
  if (use_SHT2X) {
    sht2x_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_SHT2X */

#ifdef USE_SENSOR_AM232X
  if (use_AM232X) {
    am232x_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_AM232X */

#ifdef USE_SENSOR_BME280
  if (use_BME280) {
    bme280_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_BME280 */

#ifdef USE_SENSOR_BMP180
  if (use_BMP180) {
    bmp180_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_BMP180 */

#ifdef USE_SENSOR_ADSX345 // 3軸加速度センサー Grove 3軸加速度センサ 16g
  if (use_ADXL345) {
    adxl345_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_ADSX345 */

#ifdef USE_SENSOR_ITG3200
  if (use_ITG3200) {
    itg3200_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_ITG3200 */

#ifdef USE_SENSOR_MMA7660FC // Grove3軸加速度センサ
  if (use_MMA7660) {
    mma7660_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_MMA7660FC */

#ifdef USE_SENSOR_GROVE_I2C_TOUCH // FreeScale - MPR121
  if (use_MPR121) {
    mpr121_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_I2C_TOUCH */

#ifdef USE_SENSOR_TCS34725
  if (use_TCS34725) {
    tcs34725_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_TCS34725 */

#ifdef USE_SENSOR_TSL2561 // 照度センサ
  if (use_TSL2561) {
    tsl2561_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_TSL2561 */

#ifdef USE_SENSOR_HTS221 // 温湿度センサ
  if (use_HTS221) {
    hts221_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_HTS221 */

#ifdef USE_SENSOR_LPS22HB // 気圧センサ
  if (use_LPS22HB) {
    lps22hb_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_LPS22HB */

// digital interafce sensors
#ifdef USE_SENSOR_DHT
  if (use_DHT) {
    dht_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_DHT */

#ifdef USE_SENSOR_DIGITAL_SWITCH
  if (use_digitalSwitch) {
    digitalSwitch_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_DIGITAL_SWITCH */

#ifdef USE_SENSOR_TOUCH
  if (use_GroveTouch) {
    groveTouch_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_TOUCH */

#ifdef USE_SENSOR_WATER_DETECTION
  if (use_GroveWaterDetection) {
    groveWaterDetection_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_WATER_DETECTION */

#ifdef USE_SENSOR_LINE_FINDER
  if (use_GroveLineFinder) {
    groveLineFinder_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_LINE_FINDER */

#ifdef USE_SENSOR_IR_DISTANCE_INTERRUPTER
  if (use_GroveIrDistance) {
    groveIrDistance_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_IR_DISTANCE_INTERRUPTER */

#ifdef USE_SENSOR_IR_RPR_220
  if (use_GroveIrReflective) {
    groveIrReflective_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_IR_RPR_220 */

#ifdef USE_SENSOR_PIR
  if (use_PIR) {
    pir_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_PIR */

// analog interface sensors
#ifdef USE_SENSOR_ADXL335
  if (use_ADXL335) {
    adxl335_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_ADXL335 */

#ifdef USE_SENSOR_MURATA_ENC03R
  if (use_ENC03R) {
    enc03r_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_MURATA_ENC03R */

#ifdef USE_SENSOR_ANALOG_TEMPERATURE
  if (use_GroveAnalogTemperature) {
    groveAnalogTemperature_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_ANALOG_TEMPERATURE */

#ifdef USE_SENSOR_GROVE_ANALOG_ROTARY_ANGLE
  if (use_GroveAnalogRotaryAngle) {
    groveAnalogRotaryAngle_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_ANALOG_ROTARY_ANGLE */

#ifdef USE_SENSOR_GROVE_ANALOG_LIGHT
  if (use_GroveAnalogLight) {
    groveAnalogLight_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_ANALOG_LIGHT */

#ifdef USE_SENSOR_GROVE_ANALOG_SOUND
  if (use_GroveAnalogSound) {
    groveAnalogSound_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_ANALOG_SOUND */

#ifdef USE_SENSOR_GROVE_MOISTURE
  if (use_GroveAnalogMoisture) {
    groveAnalogMoisture_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_MOISTURE */

#ifdef USE_SENSOR_GROVE_GSR
  if (use_GroveGSR) {
    groveGSR_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_GSR */

#ifdef USE_SENSOR_GROVE_CURRENT
  if (use_GroveCurrent) {
    groveCurrent_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_GROVE_CURRENT */

#ifdef USE_SENSOR_TEMT6000 // 照度センサ
  if (use_TEMT6000) {
    temt6000_Sensor();
  };
#ifdef USE_WDT
  Watchdog.reset();
#endif /* USE_WDT */
#endif /* USE_SENSOR_TEMT6000 */

}
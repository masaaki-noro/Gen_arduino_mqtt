/*
 * センサ関係グローバル変数定義
 */

// i2c , SPI sensors
#ifdef USE_SENSOR_SHT2X
bool use_SHT2X = false;
#endif /* USE_SENSOR_SHT2X */

#ifdef USE_SENSOR_SHT31
bool use_SHT31 = false;
#endif /* USE_SENSOR_SHT31 */

#ifdef USE_SENSOR_AM232X
bool use_AM232X = false;
#endif /* USE_SENSOR_AM232X */

#ifdef USE_SENSOR_BME280
bool use_BME280 = false;
#endif /* USE_SENSOR_BME280 */

#ifdef USE_SENSOR_BMP180
bool use_BMP180 = false;
#endif /* USE_SENSOR_BMP180 */

#ifdef USE_SENSOR_ADXL345 // 3軸加速度センサー Grove 3軸加速度センサ 16g
bool use_ADXL345 = false;
#endif /* USE_SENSOR_ADXL345 */

#ifdef USE_SENSOR_ITG3200
bool use_ITG3200 = false;
#endif /* USE_SENSOR_ITG3200 */

#ifdef USE_SENSOR_MMA7660FC // Grove3軸加速度センサ
bool use_MMA7660 = false;
#endif /* USE_SENSOR_MMA7660FC */

#ifdef USE_SENSOR_GROVE_I2C_TOUCH // FreeScale - MPR121
bool use_MPR121 = false;
#endif /* USE_SENSOR_GROVE_I2C_TOUCH */

#ifdef USE_SENSOR_TCS34725
bool use_TCS34725 = false;
#endif /* USE_SENSOR_TCS34725 */

#ifdef USE_SENSOR_TSL2561 // 照度センサ
bool use_TSL2561 = false;
#endif /* USE_SENSOR_TSL2561 */

#ifdef USE_SENSOR_HTS221 // 温湿度センサ
bool use_HTS221 = false;
#endif /* USE_SENSOR_HTS221 */

#ifdef USE_SENSOR_LPS22HB // 気圧センサ
bool use_LPS22HB = false;
#endif /* USE_SENSOR_LPS22HB */


// digital interface sensors
#ifdef USE_SENSOR_DHT
bool use_DHT = false;
#endif /* USE_SENSOR_DHT */

#ifdef USE_SENSOR_DIGITAL_SWITCH
bool use_digitalSwitch = false;
#endif /* USE_SENSOR_DIGITAL_SWITCH */

#ifdef USE_SENSOR_TOUCH
bool use_GroveTouch = false;
#endif /* USE_SENSOR_TOUCH */

#ifdef USE_SENSOR_WATER_DETECTION
bool use_GroveWaterDetection = false;
#endif /* USE_SENSOR_WATER_DETECTION */

#ifdef USE_SENSOR_LINE_FINDER
bool use_GroveLineFinder = false;
#endif /* USE_SENSOR_LINE_FINDER */

#ifdef USE_SENSOR_IR_DISTANCE_INTERRUPTER
bool use_GroveIrDistance = false;
#endif /* USE_SENSOR_IR_DISTANCE_INTERRUPTER */

#ifdef USE_SENSOR_IR_RPR_220  // Grove - Infrared Reflective Sensor
bool use_GroveIrReflective = false;
#endif /* USE_SENSOR_IR_RPR_220 */

#ifdef USE_SENSOR_PIR
bool use_PIR = false;
#endif /* USE_SENSOR_PIR */

// analog interface sensors
#ifdef USE_SENSOR_ADXL335
bool use_ADXL335 = false;
#endif /* USE_SENSOR_ADXL335 */

#ifdef USE_SENSOR_MURATA_ENC03R // Grove 1軸アナログジャイロ
bool use_ENC03R = false;
#endif /* USE_SENSOR_MURATA_ENC03R */

#ifdef USE_SENSOR_ANALOG_TEMPERATURE
bool use_GroveAnalogTemperature = false;
#endif /* USE_SENSOR_ANALOG_TEMPERATURE */

#ifdef USE_SENSOR_GROVE_ANALOG_ROTARY_ANGLE
bool use_GroveAnalogRotaryAngle = false;
#endif /* USE_SENSOR_GROVE_ANALOG_ROTARY_ANGLE */

#ifdef USE_SENSOR_GROVE_ANALOG_LIGHT
bool use_GroveAnalogLight = false;
#endif /* USE_SENSOR_GROVE_ANALOG_LIGHT */

#ifdef USE_SENSOR_GROVE_ANALOG_SOUND
bool use_GroveAnalogSound = false;
#endif /* USE_SENSOR_GROVE_ANALOG_SOUND */

#ifdef USE_SENSOR_GROVE_MOISTURE
bool use_GroveAnalogMoisture = false;
#endif /* USE_SENSOR_GROVE_MOISTURE */

#ifdef USE_SENSOR_GROVE_GSR
bool use_GroveGSR = false;
#endif /* USE_SENSOR_GROVE_GSR */

#ifdef USE_SENSOR_GROVE_CURRENT
bool use_GroveCurrent = false;
#endif /* USE_SENSOR_GROVE_CURRENT */

#ifdef USE_SENSOR_TEMT6000 // 照度センサ
bool use_TEMT6000 = false;
#endif /* #ifdef USE_SENSOR_TEMT6000 */

/*
 * センサ処理関数定義
 */

/*
 * I2C and SPI
 */
#ifdef USE_SENSOR_SHT2X
bool sht2x_init(void);
void sht2x_output_info(void);
void sht2x_Sensor(void);
#endif /* USE_SENSOR_SHT2X */

#ifdef USE_SENSOR_SHT31
bool sht31_init(void);
void sht31_output_info(void);
void sht31_Sensor(void);
#endif /* USE_SENSOR_SHT31 */

#ifdef USE_SENSOR_AM232X
bool am232x_init(void);
void am232x_output_info(void);
void am232x_Sensor(void);
#endif /* USE_SENSOR_AM232X */

#ifdef USE_SENSOR_BME280
bool bme280_init(void);
void bme280_output_info(void);
void bme280_Sensor(void);
#endif /* USE_SENSOR_BME280 */

#ifdef USE_SENSOR_BMP180
bool bmp180_init(void);
void bmp180_output_info(void);
void bmp180_Sensor(void);
#endif /* USE_SENSOR_BMP180 */

#ifdef USE_SENSOR_ADXL345 // 3軸加速度センサー Grove 3軸加速度センサ 16g
bool adxl345_init(void);
void adxl345_output_info(void);
void adxl345_Sensor(void);
#endif /* USE_SENSOR_ADXL345 */

#ifdef USE_SENSOR_ITG3200
bool itg3200_init(void);
void itg3200_output_info(void);
void itg3200_Sensor(void);
#endif /* USE_SENSOR_ITG3200 */

#ifdef USE_SENSOR_MMA7660FC // Grove3軸加速度センサ
bool mma7660_init(void);
void mma7660_output_info(void);
void mma7660_Sensor(void);
#endif /* USE_SENSOR_MMA7660FC */

#ifdef USE_SENSOR_GROVE_I2C_TOUCH // FreeScale - MPR121
bool mpr121_init(void);
void mpr121_output_info(void);
void mpr121_Sensor(void);
#endif /* USE_SENSOR_GROVE_I2C_TOUCH */

#ifdef USE_SENSOR_TCS34725
bool tcs34725_init(void);
void tcs34725_output_info(void);
void tcs34725_Sensor(void);
#endif /* USE_SENSOR_TCS34725 */

#ifdef USE_SENSOR_TSL2561 // 照度センサ
bool tsl2561_init(void);
void tsl2561_output_info(void);
void tsl2561_Sensor(void);
#endif /* USE_SENSOR_TSL2561 */

#ifdef USE_SENSOR_HTS221 // 温湿度センサ
bool hts221_init(void);
void hts221_output_info(void);
void hts221_Sensor(void);
#endif /* USE_SENSOR_HTS221 */

#ifdef USE_SENSOR_LPS22HB // 気圧センサ
bool lps22hb_init(void);
void lps22hb_output_info(void);
void lps22hb_Sensor(void);
#endif /* USE_SENSOR_LPS22HB */


/*
 * Digital interface
 */
#ifdef USE_SENSOR_DHT
bool dht_init(void);
void dht_output_info(void);
void dht_Sensor(void);
#endif /* USE_SENSOR_DHT */

#ifdef USE_SENSOR_DIGITAL_SWITCH
bool digitalSwitch_init(void);
void digitalSwitch_output_info(void);
void digitalSwitch_Sensor(void);
#endif /* USE_SENSOR_DIGITAL_SWITCH */

#ifdef USE_SENSOR_TOUCH
bool groveTouch_init(void);
void groveTouch_output_info(void);
void groveTouch_Sensor(void);
#endif /* USE_SENSOR_TOUCH */

#ifdef USE_SENSOR_WATER_DETECTION
bool groveWaterDetection_init(void);
void groveWaterDetection_output_info(void);
void groveWaterDetection_Sensor(void);
#endif /* USE_SENSOR_WATER_DETECTION */

#ifdef USE_SENSOR_LINE_FINDER
bool groveLineFinder_init(void);
void groveLineFinder_output_info(void);
void groveLineFinder_Sensor(void);
#endif /* USE_SENSOR_LINE_FINDER */

#ifdef USE_SENSOR_IR_DISTANCE_INTERRUPTER
bool groveIrDistance_init(void);
void groveIrDistance_output_info(void);
void groveIrDistance_Sensor(void);
#endif /* USE_SENSOR_IR_DISTANCE_INTERRUPTER */

#ifdef USE_SENSOR_IR_RPR_220  // Grove - Infrared Reflective Sensor
bool groveIrReflective_init(void);
void groveIrReflective_output_info(void);
void groveIrReflective_Sensor(void);
#endif /* USE_SENSOR_IR_RPR_220 */

#ifdef USE_SENSOR_PIR
bool pir_init(void);
void pir_output_info(void);
void pir_Sensor(void);
#endif /* USE_SENSOR_PIR */

/*
 * Analog Interface
 */
#ifdef USE_SENSOR_ADXL335
bool adxl335_init(void);
void adxl335_output_info(void);
void adxl335_Sensor(void);
#endif /* USE_SENSOR_ADXL335 */

#ifdef USE_SENSOR_MURATA_ENC03R // Grove 1軸アナログジャイロ
bool enc03r_init(void);
void enc03r_output_info(void);
void enc03r_Sensor(void);
#endif /* USE_SENSOR_MURATA_ENC03R */

#ifdef USE_SENSOR_ANALOG_TEMPERATURE
bool groveAnalogTemperature_init(void);
void groveAnalogTemperature_output_info(void);
void groveAnalogTemperature_Sensor(void);
#endif /* USE_SENSOR_ANALOG_TEMPERATURE */


#ifdef USE_SENSOR_GROVE_ANALOG_ROTARY_ANGLE
bool groveAnalogRotaryAngle_init(void);
void groveAnalogRotaryAngle_output_info(void);
void groveAnalogRotaryAngle_Sensor(void);
#endif /* USE_SENSOR_GROVE_ANALOG_ROTARY_ANGLE */

#ifdef USE_SENSOR_GROVE_ANALOG_LIGHT
bool groveAnalogLight_init(void);
void groveAnalogLight_output_info(void);
void groveAnalogLight_Sensor(void);
#endif /* USE_SENSOR_GROVE_ANALOG_LIGHT */

#ifdef USE_SENSOR_GROVE_ANALOG_SOUND
bool groveAnalogSound_init(void);
void groveAnalogSound_output_info(void);
void groveAnalogSound_Sensor(void);
#endif /* USE_SENSOR_GROVE_ANALOG_SOUND */

#ifdef USE_SENSOR_GROVE_MOISTURE
bool groveAnalogMoisture_init(void);
void groveAnalogMoisture_output_info(void);
void groveAnalogMoisture_Sensor(void);
#endif /* USE_SENSOR_GROVE_MOISTURE */

#ifdef USE_SENSOR_GROVE_GSR
bool groveGSR_init(void);
void groveGSR_output_info(void);
void groveGSR_Sensor(void);
#endif /* USE_SENSOR_GROVE_GSR */

#ifdef USE_SENSOR_GROVE_CURRENT
bool groveCurrent_init(void);
void groveCurrent_output_info(void);
void groveCurrent_Sensor(void);
#endif /* USE_SENSOR_GROVE_CURRENT */

#ifdef USE_SENSOR_TEMT6000 // 照度センサ
bool temt6000_init(void);
void temt6000_output_info(void);
void temt6000_Sensor(void);
#endif /* USE_SENSOR_TEMT6000 */

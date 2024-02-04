# センサの手配

本プロジェクトの本開発環境でサポートしているセンサをセンシング対象別にリストアップしておく．
ただし，既に生産停止になったものや，入手が困難なものも含まれるため，それぞれのセンサの発売元の
URL等を確認して手配していただきたい．

また，センサの種類によっては，5Vや3.3Vのいずれかの動作電圧の機器でしか使えないものもあるため，
販売元の情報を確認すること．

## 1. 環境測定系センサ

|センサ名|温度|湿度|気圧|インターフェース|入手元情報|
|---|---|---|---|---|---|
|BME280|◯|◯|◯|I2C|[秋月電子](https://akizukidenshi.com/catalog/g/gK-09421/), [スイッチサイエンス](https://www.switch-science.com/products/2236)|
|BMP180|✕|✕|◯|I2C|[Grove - Barometer Sensor](https://www.seeedstudio.com/Grove-Barometer-Sensor-BMP18-p-1840.html)|
|SHT31|◯|◯|✕|I2C|[秋月電子](https://akizukidenshi.com/catalog/g/gK-12125/), [Grove - Temperature&Humidity Sensor (SHT31)](https://www.seeedstudio.com/Grove-Temperature-Humidity-Sensor-SHT31.html)|
|SHT2X|◯|◯|✕|I2C|[ストロベリーリナックス](https://strawberry-linux.com/catalog/items?code=80021)|
|AM232X|◯|◯|✕|I2C|[秋月電子](https://akizukidenshi.com/catalog/g/gM-10880/)|
|DHT|◯|◯|✕|デジタル✕1|[Grove 温度および湿度センサPro](https://jp.seeedstudio.com/Grove-Temperature-Humidity-Sensor-Pro-AM2302-DHT22.html), [Grove - 温度および湿度センサ](https://jp.seeedstudio.com/Grove-Temperature-Humidity-Sensor-DHT11.html)|
|Grove - Temperature Sensor|◯|✕|✕|アナログ✕1|[Grove - Temperature Sensor](https://jp.seeedstudio.com/Grove-Temperature-Sensor.html)|



## 2. 振動・加速度等

|センサ名|加速度(軸数)|ジャイロ(軸数)|インターフェース|入手元情報|
|---|---|---|---|---|
|ITG320|✕|3|I2C|[Grove 三軸デジタルジャイロ](https://jp.seeedstudio.com/Grove-3-Axis-Digital-Gyro.html)|
|MMA7660|3|✕|I2C|[Grove 三軸デジタル加速度計(±1.5g)](https://jp.seeedstudio.com/Grove-3-Axis-Digital-Accelerometer-1-5g.html)|
|ADXL345|3|✕|I2C|[Grove 三軸デジタル加速度計(±16g)](https://jp.seeedstudio.com/Grove-3-Axis-Digital-Accelerometer-16g.html)|
|ADXL335|3|✕|アナログ✕3|[Grove - 3-Axis Analog Accelerometer (±3g)](https://www.seeedstudio.com/Grove-3-Axis-Analog-Accelerometer-ADXL335.html)|
|村田ENC03R|✕|1|アナログ✕1|販売終了|


## 3. 対人センサ

|センサ名|接触|人感(赤外線)|インターフェース|入手元情報|
|---|---|---|---|---|
|GROVE - I2C タッチセンサ(MPR121)|12(最大)|✕|I2C|[Grove I2Cタッチセンサ](https://jp.seeedstudio.com/Grove-I2C-Touch-Sensor-p-840.html), [Grove 静電容量式I2Cタッチセンサー 12キー](https://jp.seeedstudio.com/Grove-12-Key-Capacitive-I2C-Touch-Sensor-V3-MPR121-p-4694.html)|
|Grove - Touch Sensor|1|✕|デジタル✕1|[Grove - Touch Sensor](https://www.seeedstudio.com/Grove-Touch-Sensor.html)|
|Grove - PIR Motion Sensor|✕|◯|デジタル✕1|[Grove - PIR Motion Sensor](https://www.seeedstudio.com/Grove-PIR-Motion-Sensor.html)|

|センサ名|観測/測定対象|インターフェース|入手元情報|
|---|---|---|---|
|Grove - GSR Sensor|体(手)の湿り気(汗)|アナログ✕1|[Grove 電気皮膚反応測定センサ](https://jp.seeedstudio.com/Grove-GSR-sensor-p-1614.html)|

## 4. 視覚関連

|センサ名|照度|色彩|インターフェース|入手元情報|
|---|---|---|---|---|
|TCS34725|✕|◯|I2C|[秋月電子](https://akizukidenshi.com/catalog/g/gM-08220/)|
|TSL2561|◯|✕|I2C|[Adafruit](https://www.adafruit.com/product/439)|

## 5. その他

|センサ名|観測/測定対象|インターフェース|入手元情報|
|---|---|---|---|
|Grove - Switch|物理的な切り替え(スイッチ等)|デジタル✕1|[Grove - Digital Switch(P)](https://www.seeedstudio.com/Grove-Switch-P.html)|
|Grove - Water Sensor|水の検知(端子間の短絡)|デジタル✕1|[Grove 水検出センサ](https://jp.seeedstudio.com/Grove-Water-Sensor.html)|
|Grove - Line Finder|黒色の検出(赤外線反射)|デジタル✕1|[Grove ラインファインダー](https://jp.seeedstudio.com/Grove-Line-Finder-v1-1.html)|
|Grove IR Distance Interrupter|物体検出(赤外線反射)|デジタル✕1|[Grove IR 距離遮断器](https://jp.seeedstudio.com/Grove-IR-Distance-Interrupter-v1-2.html)|
|Grove - Infrared Reflective Sensor|物体検出(赤外線反射)|デジタル✕1|[Grove 赤外線反射センサー](https://jp.seeedstudio.com/Grove-Infrared-Reflective-Sensor-v1-2.html)|
|Grove - Rotary Angle Sensor|回転角度|アナログ✕1|[Grove 回転角センサ](https://jp.seeedstudio.com/Grove-Rotary-Angle-Sensor.html)|
|Grove - Light Sensor|光の強弱(照度ではない)|アナログ✕1|[Grove 光センサ](https://jp.seeedstudio.com/Grove-Light-Sensor-v1-2-LS06-S-phototransistor.html)|
|Grove - Sound Sensor|音の大小(デジタル値ではない)|アナログ✕1|[Grove - Sound Sensor](https://www.seeedstudio.com/Grove-Sound-Sensor-Based-on-LM358-amplifier-Arduino-Compatible.html)|
|Grove水分センサー|土の湿り気|アナログ✕1|[Grove水分センサー](https://jp.seeedstudio.com/Grove-Moisture-Sensor.html)|
|Grove電流センサ|電流の強弱(正確な値ではない)|アナログ✕1|[Grove - Electricity Sensor](https://www.seeedstudio.com/Grove-Electricity-Sensor.html)|



***
- [「はんだ付け」に進む](Soldering.md)
- [「Arduinoの機種別のパーツリスト」に戻る](Parts_List.md)
- [マニュアルトップに戻る](../Manual.md)

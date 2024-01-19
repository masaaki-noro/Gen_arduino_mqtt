# ADXL345 3軸加速度センサ

アナログ・デバイセズ社の3軸加速度センサ ADXL345はI2CとSPIの2種類のインターフェースをサポートし，
16gまで測定可能なセンサICである．

このICを使ったセンサモジュールには以下のようなものがある．

- Grove - 3 Axis Digital Accelerometer(±16g) https://wiki.seeedstudio.com/Grove-3-Axis_Digital_Accelerometer-16g/
- SparkFun Triple Axis Accelerometer Breakout - ADXL345 https://www.sparkfun.com/products/9836

チップの動作電圧は，2.0から3.6Vであるが，上記のモジュールのうち，Groveのモジュールは3.3V, 5V両方対応となっている．
また，GroveのモジュールはI2C専用の配線がされている．

## Arduinoとの接続方法
本ソフトウェア環境では，ADXL345はI2C接続のみをサポートしているため，Groveのモジュールで説明する．

I2C接続となるため，MKRシリーズ用のGrove基板の場合は，「TWI」コネクタと接続する．

- MKRシリーズ用Grove基板 https://store-usa.arduino.cc/products/arduino-mkr-connector-carrier-grove-compatible?selectedStore=us
![MKRシリーズGrove基板](../../images/MKR_carrier.png)

Uno等のクラシックシリーズ用のGrove基板の場合は，下の写真にも見えているように，「I2C」端子に接続する．
- Unoシリーズ用Grove基板  https://jp.seeedstudio.com/Base-Shield-V2.html 
![UnoシリーズGrove基板](../../images/Groveシールド.jpg)

下の写真は，Groveのシールドを用いて接続した事例である．
- 画像出典 https://wiki.seeedstudio.com/Grove-3-Axis_Digital_Accelerometer-16g/
![ADXL345接続例](../../images/Grove_-_3-Axis_Digital_Accelerometer_ADXL345_connect_photo.jpg)

## 接続先の情報

I2Cで接続する機器は特に情報をメモしておく必要はない．

***

- [「センサ端末の詳細定義」に戻る](../SensorSelection.md)
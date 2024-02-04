# Grove I2C タッチセンサ

Seeed studio社が販売するセンサで，I2C接続で複数のタッチセンサの値を同時に読み取れるタッチセンサ．製品ページの写真では，4つしかセンサが接続されていないが，8本まで繋ぐコネクタが存在する．さらに，外部に4つセンサを拡張できる端子が基板上に存在している．そのため，ハードを拡張すると最大12個のタッチセンサを接続できる．

- [製品ページ](https://wiki.seeedstudio.com/Grove-I2C_Touch_Sensor/)


<div style="text-align: center;">
<img src="../../images/Grove-I2C-Touch-Sensor.jpg" width="80%">
</div>



本タッチセンサの主要部品であるセンサIC(MPR121)の動作電圧は1.71-3.6Vであるが，Groveのモジュールは3.0-5.5Vで動作する．

## Arduinoとの接続方法
このモジュールはI2C接続となるため，MKRシリーズ用のGrove基板の場合は，「TWI」コネクタと接続する．

- [MKRシリーズ用Grove基板](https://store-usa.arduino.cc/products/arduino-mkr-connector-carrier-grove-compatible?selectedStore=us)

<div style="text-align: center;">
<img src="../../images/MKR_carrier.png" width="50%">
</div>



Uno等のクラシックシリーズ用のGrove基板の場合は，下の写真にも見えているように，「I2C」端子に接続する．
- [Unoシリーズ用Grove基板](https://jp.seeedstudio.com/Base-Shield-V2.html)

<div style="text-align: center;">
<img src="../../images/Groveシールド.jpg" width="70%">
</div>

## 接続先の情報

I2Cで接続する機器は特に情報をメモしておく必要はない．

***

- [「センサ端末の詳細定義」に戻る](../SensorSelection.md)
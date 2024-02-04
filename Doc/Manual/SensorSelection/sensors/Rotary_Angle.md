# Grove - Rotary Angle Sensor

このGroveモジュールの詳細は以下のWebに記載されている．

- Grove - Rotary Angle Sensor https://wiki.seeedstudio.com/Grove-Rotary_Angle_Sensor/

上記Groveモジュールは3.3V, 5V両方対応できる．

このモジュールの動作原理はオーディオ機器のボリューム等と同じで回転させると
電気抵抗が変化するので，それを読み取ることでどの程度回転したかを判断するものである．


## Arduinoとの接続方法
上記Groveモジュールは，通常のGrove端子が利用できるため，
下記「MKRシリーズ用Grove基板」では，「A0」から「A5,A6」端子の何れかに接続する．

- [MKRシリーズ用Grove基板](https://store-usa.arduino.cc/products/arduino-mkr-connector-carrier-grove-compatible?selectedStore=us)

<div style="text-align: center;">
<img src="../../images/MKR_carrier.png" width="50%">
</div>

Uno等のクラシックシリーズ用のGrove基板の場合は，下の写真にも見えているように，「A0」から「A3」端子のいずれかに接続する．
- [Unoシリーズ用Grove基板](https://jp.seeedstudio.com/Base-Shield-V2.html)

<div style="text-align: center;">
<img src="../../images/Groveシールド.jpg" width="70%">
</div>


## 接続先の情報

スイッチをどのピン(A0,A1など)に接続したかをメモしておく．

***

- [「センサ端末の詳細定義」に戻る](../SensorSelection.md)



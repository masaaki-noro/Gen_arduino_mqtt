# Grove - Temperature Sensor 

これは，サーミスタを使った温度センサで，このGroveモジュールの詳細は以下のWebに記載されている．
なお，サーミスタとは，温度で抵抗値が変化する電気抵抗である．


- Grove - Temperature Sensor https://wiki.seeedstudio.com/Grove-Temperature_Sensor_V1.2/

上記Groveモジュールは3.3V, 5V両方対応できる．

また，測定可能範囲は-40℃～125℃で測定誤差は±1.5℃である．


## Arduinoとの接続方法
上記Groveモジュールは，通常のGrove端子が利用できるため，
下記「MKRシリーズ用Grove基板」では，「A0」から「A5,A6」端子の何れかに接続する．

- MKRシリーズ用Grove基板 https://store-usa.arduino.cc/products/arduino-mkr-connector-carrier-grove-compatible?selectedStore=us
![MKRシリーズGrove基板](../images/MKR_carrier.png)

Uno等のクラシックシリーズ用のGrove基板の場合は，下の写真にも見えているように，「A0」から「A3」端子のいずれかに接続する．
- Unoシリーズ用Grove基板  https://jp.seeedstudio.com/Base-Shield-V2.html 
![UnoシリーズGrove基板](../images/Groveシールド.jpg)




## 接続先の情報

スイッチをどのピン(A0,A1など)に接続したかをメモしておく．

***

- [「センサ端末の詳細定義」に戻る](../SensorSelection.md)


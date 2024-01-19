# Grove - Electricity Sensor

以下のGroveセンサモジュールは，電磁誘導で流れる電流を測定するもので，5Vのみに対応．

- Grove - Electricity Sensor https://wiki.seeedstudio.com/Grove-Electricity_Sensor/

このモジュールは，下の写真のように，モジュールのコイルの内部に測定対称のケーブルを通した上で，測定を行う．
このとき，2本のケーブルのうち，1本だけを通す必要がある(両方通してはいけない)．

また，このモジュールは，交流電流しか測定できない．

- 画像出典 https://wiki.seeedstudio.com/Grove-Electricity_Sensor/
![Grove電流センサ](../../images/grove_current.jpg)

## Arduinoとの接続方法
上記Groveモジュールは，通常のGrove端子が利用できるため，
下記「MKRシリーズ用Grove基板」では，「A0」から「A5,A6」端子の何れかに接続する．

- MKRシリーズ用Grove基板 https://store-usa.arduino.cc/products/arduino-mkr-connector-carrier-grove-compatible?selectedStore=us
![MKRシリーズGrove基板](../../images/MKR_carrier.png)

Uno等のクラシックシリーズ用のGrove基板の場合は，下の写真にも見えているように，「A0」から「A3」端子のいずれかに接続する．
- Unoシリーズ用Grove基板  https://jp.seeedstudio.com/Base-Shield-V2.html 
![UnoシリーズGrove基板](../../images/Groveシールド.jpg)


## 接続先の情報

スイッチをどのピン(A0,A1など)に接続したかをメモしておく．

***

- [「センサ端末の詳細定義」に戻る](../SensorSelection.md)



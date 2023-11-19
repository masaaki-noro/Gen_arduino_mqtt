# 水センサ

1つのデジタル端子を使い，水で濡れか否かを判断するためのセンサであり，Groveとしてモジュール化されたものも存在する．

- Grove - Water Sensor https://wiki.seeedstudio.com/Grove-Water_Sensor/

下の写真はこのセンサモジュール本体であるが，基板の表面に出ている銀色の配線部分が水で隣の配線と通電(漏電)したことを判断するのがこのセンサの目的である．

![Grove Buttonの接続例](../images/Grove-Water_Sensor_module.png)
[写真出典](https://wiki.seeedstudio.com/Grove-Water_Sensor/)


## Arduinoとの接続例
デジタル端子1つに接続する必要があるため，Groveの端子に接続できるモジュールを用いる場合は，ケーブル1本で何れかのデジタル端子に接続すれば良い．

以下のイメージは，タッチセンサを触れた場合にLEDを点灯させるようなアプリケーションを想定した接続である．
![Grove Buttonの接続例](../images/Grove-Water_Sensor.jpg)
[写真出典](https://wiki.seeedstudio.com/Grove-Water_Sensor/)


## 接続先の情報

スイッチをどのピン(D0,D1など)に接続したかをメモしておく．

***

- [「センサ端末の詳細定義」に戻る](../SensorSelection.md)
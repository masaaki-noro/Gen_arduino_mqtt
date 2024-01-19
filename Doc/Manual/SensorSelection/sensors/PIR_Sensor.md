# 人感センサ

トイレなどで，人が入ると電灯がつくような仕組みがあるが，これは人感センサで人の動きを検出して，電灯のON/OFFを制御している．
Passive Infra-Redを縮めて，PIRセンサとも呼ばれる．

このセンサの特徴は，受信した赤外線に変動があった場合のみ，「何かを検出した」と出力するため，人や動物が
ジッとしていると検出できなくなる．

以下は，PIRセンサをGrove用のモジュールにしたもので，デジタル端子1つを使う．
また，このモジュールは3.3V, 5V両用である．
- Grove - PIR Motion Sensor https://wiki.seeedstudio.com/Grove-PIR_Motion_Sensor/



## Arduinoとの接続例
デジタル端子1つに接続する必要があるため，Groveの端子に接続できるモジュールを用いる場合は，ケーブル1本で何れかのデジタル端子に接続すれば良い．


![PIRセンサ](../../images/PIR_Sensor.jpg)
[写真出典](https://wiki.seeedstudio.com/Grove-PIR_Motion_Sensor/)




## 接続先の情報

スイッチをどのピン(D0,D1など)に接続したかをメモしておく．

***

- [「センサ端末の詳細定義」に戻る](../SensorSelection.md)


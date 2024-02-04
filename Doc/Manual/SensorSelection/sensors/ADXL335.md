# ADXL335 3軸加速度センサ

アナログ・デバイセズ社の3軸加速度センサ ADXL335は±3gの範囲の加速度を測定できる3軸加速度センサである．

このICを使ったセンサモジュールには以下のようなものがある．

- [Grove - 3-Axis Analog Accelerometer](https://wiki.seeedstudio.com/Grove-3-Axis_Analog_Accelerometer/)

チップの動作電圧は，1.8から3.6Vであるが，上記のGroveのモジュールは3.0-5.0Vの範囲の電圧で動作する．

## Arduinoとの接続方法
本ソフトウェア環境では，ADXL335はアナログ接続かつ，3つの軸それぞれ別のアナログ端子に接続する必要があるため，多くのGroveモジュールで
利用されるコネクタでArduinoと接続することはできない．

下の写真は，ADXL335のGroveモジュールに関する解説ページの写真であるが，Arduinoのアナログ端子3つに加えて，電源とGNDの合計5つの端子をジャンパーケーブルで接続する必要がある．


- [画像出典](https://wiki.seeedstudio.com/Grove-3-Axis_Analog_Accelerometer/)


<div style="text-align: center;">
<img src="../../images/Grove-3-axis_analog_accelerometer_V1.0_hardware.jpg" width="80%">
</div>





## 接続先の情報

x,y,zのどれをどのピン(A1,A2など)に接続したかをメモしておく．

***

- [「センサ端末の詳細定義」に戻る](../SensorSelection.md)

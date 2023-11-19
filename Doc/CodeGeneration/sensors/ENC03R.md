# 村田ENC03R 1軸アナログジャイロ

村田製作所のEND03Rは1軸アナログジャイロである．

このICを使ったセンサモジュールには以下のようなものがある．

- Grove-Single Axis Analog Gyro https://wiki.seeedstudio.com/Grove-Single_Axis_Analog_Gyro/


## 設定項目
設定すべき項目は4つ存在し，以下は設定ファイルのデフォルトを表している．

```
#
# Grove Analog 1 Axis Gyro
#
murataENC03:
  use_murataENC03: true # true(使う) , false(使わない)
  murataENC03_pin: A3
  murataENC03_try: 1000
  sensor_id: -1
```

## 利用のスイッチ
センサを使う場合は，この項目にtrueを設定する．
```
use_murataENC03: true # true(使う) , false(使わない)
```

## 接続端子の指定
Arduinoに接続した際に作ったメモのピン番号をそのまま書き込めば良い．

下の例(デフォルト)は，アナログ端子の3番に接続していることを表している．
```
murataENC03_pin: A3
```


## パラメータ
```
murataENC03_try: 1000
```
ENC03Rを駆動するソフトウェアでは，動作開始時に静かな環境で測定を繰り返し，その平均値を基準の値として用いる．
この基準の値を求めるための測定回数をこのパラメータで指定する．

## センサID
この数字を変更することで，多数のセンサが交じる環境で，このセンサのデータを特定することが可能．
```
sensor_id: -1
```

***

- [「センサの定義」に戻る](../SensorDefinition.md)

# ADXL335 3軸加速度センサ

アナログ・デバイセズ社の3軸加速度センサ ADXL335は±3gの範囲の加速度を測定できる3軸加速度センサである．

このICを使ったセンサモジュールには以下のようなものがある．

- Grove - 3-Axis Analog Accelerometer https://wiki.seeedstudio.com/Grove-3-Axis_Analog_Accelerometer/


## 設定項目
設定すべき項目は2つ存在し，以下は設定ファイルのデフォルトを表している．

```
#
# ADXL335
#
adxl335:
  use_adxl335: true # true(使う) , false(使わない)
  adxl335_x_pin: A1
  adxl335_y_pin: A2
  adxl335_z_pin: A3
  sensor_id: -1
```

## 利用のスイッチ
センサを使う場合は，この項目にtrueを設定する．
```
use_adxl335: true # true(使う) , false(使わない)
```

## 接続端子の指定
```
adxl335_x_pin: A1
adxl335_y_pin: A2
adxl335_z_pin: A3
```
3軸の各データ端子をどのアナログ端子に接続したか，センサ取付時のメモを参照して記入する．



## センサID
この数字を変更することで，多数のセンサが交じる環境で，このセンサのデータを特定することが可能．
```
sensor_id: -1
```

***

- [「センサの定義」に戻る](../SensorDefinition.md)

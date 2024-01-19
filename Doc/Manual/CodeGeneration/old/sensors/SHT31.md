# SHT31

SENSIRION社の温湿度センサでI2Cインターフェースで接続できます．

このセンサICを利用したセンサモジュールとしては，以下のようなものがある．

- 秋月電子 : https://akizukidenshi.com/catalog/g/gK-12125/


## 設定項目
設定すべき項目は2種類(3項目)存在し，以下は設定ファイルのデフォルトを表している．

```
#
# SHT31
#
sht31:
  use_sht31: true # true(使う) , false(使わない)
  temperature_sensor_id: -1
  humidity_sensor_id: -1
```

## 利用のスイッチ
センサを使う場合は，この項目にtrueを設定する．
```
use_sht31: true # true(使う) , false(使わない)
```


## センサID

```
temperature_sensor_id: -1
humidity_sensor_id: -1
```


「```temperature_sensor_id```」と「```humidity_sensor_id```」を用いて，温度,湿度にそれぞれセンサIDを与えることができる．

この設定項目は，利用するセンサに他のセンサと区別するための番号を割り当てる場合のみ値を変更すれば良い．

***

- [「センサの定義」に戻る](../SensorDefinition.md)

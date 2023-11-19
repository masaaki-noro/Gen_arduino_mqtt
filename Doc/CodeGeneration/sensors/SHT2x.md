# SHT2x

SENSIRION社の温湿度センサでI2Cインターフェースで接続できます．

- 製品ページ https://www.sensirion.com/search/products?q=SHT2x

このセンサICを利用したセンサモジュールとしては，以下のようなものがある．

- ストロベリーリナックス SHT21 : https://strawberry-linux.com/catalog/items?code=80021
![SHT21](../images/SHT21.jpg)

SHT2xシリーズのセンサICは3種類存在し，低価格版のSHT20系，標準的な性能のSHT21系，高精度のSHT25系になる．



## 設定項目
設定すべき項目は2種類(3項目)存在し，以下は設定ファイルのデフォルトを表している．

```
#
# SHT2x
#
sht2x:
  use_sht2x: true
  sht2x_type: SHT21 # sht21
  temperature_sensor_id: -1
  humidity_sensor_id: -1

```

## 利用のスイッチ
センサを使う場合は，この項目にtrueを設定する．
```
use_sht2x: true # true(使う) , false(使わない)
```

## センサ種別
センサICの種類を定義する項目で，SHT21の場合は大文字でSHT21と記載する．
```
sht2x_type: SHT21 # sht21
```

ここは，センサをArduinoに接続した際に作成したメモに基づいて記入する．

## センサID

```
temperature_sensor_id: -1
humidity_sensor_id: -1
```


「```temperature_sensor_id```」と「```humidity_sensor_id```」を用いて，温度,湿度にそれぞれセンサIDを与えることができる．

この設定項目は，利用するセンサに他のセンサと区別するための番号を割り当てる場合のみ値を変更すれば良い．


***

- [「センサの定義」に戻る](../SensorDefinition.md)

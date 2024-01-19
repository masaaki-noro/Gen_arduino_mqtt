# DHTシリーズ温湿度計

1つのデジタル端子を使い，独自のプロトコルで通信を行う温湿度センサのシリーズ．

このシリーズのセンサを利用した代表的なセンサ製品には以下のようなものがある．

- DHT11 : https://wiki.seeedstudio.com/Grove-TemperatureAndHumidity_Sensor/

- DHT22 : https://wiki.seeedstudio.com/Grove-Temperature_and_Humidity_Sensor_Pro/


## 設定項目
設定すべき項目は4つ存在する．

```
#
# DHTシリーズ温湿度計
#
dht:
  use_dht: true # true(使う) , false(使わない)
  dht_pin: 2
  dht_type: DHT22 # DHT11 , DHT21 , DHT22
  temperature_sensor_id: -1
  humidity_sensor_id: -1
```

### 利用のスイッチ
DHTシリーズのセンサを使う場合は，この項目にtrueを設定する．
```
use_dht: true # true(使う) , false(使わない)
```


### 接続するピン番号

ArduinoにDHTを接続した際に作ったメモのピン番号をそのまま書き込めば良い．

下の例(デフォルト)は，デジタル端子の2番に接続していることを表している．
```
dht_pin: 2
```

下の図はArduino MKRシリーズ用のGroveモジュールを接続するための拡張基板であり，上の設定値の場合，「D2」端子に接続されていることになる．

![Alt text](../../images/MKR_carrier.png)
[写真出典](https://store-usa.arduino.cc/products/arduino-mkr-connector-carrier-grove-compatible)


### DHTシリーズのどれを使うか
以下の例は，DHT22を利用することを宣言している．
```
dht_type: DHT22 # DHT11 , DHT21 , DHT22
```

ここも，手元にあるDHTシリーズのセンサに合わせた値にする．

### センサID

```
temperature_sensor_id: -1
humidity_sensor_id: -1
```


「```temperature_sensor_id```」と「```humidity_sensor_id```」を用いて，温度と湿度に別のセンサIDを与えることができる．

この設定項目は，利用するDHTシリーズのセンサに他のセンサと区別するために番号を割り当てる場合のみ値を変更すれば良い．

***

- [「センサの定義」に戻る](../SensorDefinition.md)

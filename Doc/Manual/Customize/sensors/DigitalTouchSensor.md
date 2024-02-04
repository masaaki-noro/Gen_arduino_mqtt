# Groveタッチセンサ

1つのデジタル端子を使い，人が触れているか否かを判別するためのセンサである．

- Grove - Touch Sensor https://wiki.seeedstudio.com/Grove-Touch_Sensor/


## 設定項目
設定すべき項目は3つ存在する．

```
#
# Grove タッチセンサ
#
groveTouch:
  use_groveTouch: true # true(使う) , false(使わない)
  groveTouch_pin: 2
  sensor_id: -1
```

### 利用のスイッチ
タッチセンサを使う場合は，この項目にtrueを設定する．
```
use_groveTouch: true # true(使う) , false(使わない)
```


### 接続するピン番号

下の例(デフォルト)は，デジタル端子の2番に接続していることを表している．
```
groveTouch_pin: 2
```

下の図はArduino MKRシリーズ用のGroveモジュールを接続するための拡張基板であり，上の設定値の場合，接続するのは，「D2」端子となる．


[写真出典](https://store-usa.arduino.cc/products/arduino-mkr-connector-carrier-grove-compatible)

<div style="text-align: center;">
<img src="../../images/MKR_carrier.png" width="70%">
</div>


### センサID
```
sensor_id: -1
```
この設定項目は，利用するスイッチと他のセンサと区別するために番号を割り当てる場合のみ値を変更すれば良い．


***

- [「センサの定義」に戻る](../SensorDefinition.md)

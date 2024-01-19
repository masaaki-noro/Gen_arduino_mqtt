# Grove - Light Sensor

これは，光可変抵抗を使った照度センサで，このGroveモジュールの詳細は以下のWebに記載されている．
光可変抵抗とは，その部品に当たっている光の強さで電気抵抗値が変化する素子である．

- Grove - Light Sensor https://wiki.seeedstudio.com/Grove-Light_Sensor/



## 設定項目
設定すべき項目は3つ存在する．

```
#
# Grove analog light
#
groveAnalogLight:
  use_groveAnalogLight: true # true(使う) , false(使わない)
  groveAnalogLight_pin: A3
  sensor_id: -1

```

### 利用のスイッチ
センサを使う場合は，この項目にtrueを設定する．
```
use_groveAnalogLight: true # true(使う) , false(使わない)
```

### 接続端子の指定
```
groveAnalogLight_pin: A3
```
センサをどのアナログ端子に接続するかを明示する．上の例はアナログ端子の3番に接続していることを
示している．


### センサID
この数字を変更することで，多数のセンサが交じる環境で，このセンサのデータを特定することが可能．
```
sensor_id: -1
```

***

- [「センサの定義」に戻る](../SensorDefinition.md)

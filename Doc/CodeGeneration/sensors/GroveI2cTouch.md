# Grove I2C タッチセンサ

Seeed studio社が販売するセンサで，I2C接続で複数のタッチセンサの値を同時に読み取れるタッチセンサ．製品ページの写真では，4つしかセンサが接続されていないが，8本まで繋ぐコネクタが存在する．さらに，外部に4つセンサを拡張できる端子が基板上に存在している．そのため，ハードを拡張すると最大12個のタッチセンサを接続できる．

- 製品ページ : https://wiki.seeedstudio.com/Grove-I2C_Touch_Sensor/

![Grove I2C タッチセンサ](../images/Grove-I2C-Touch-Sensor.jpg)



## 設定項目
設定すべき項目は2つ存在し，以下は設定ファイルのデフォルトを表している．

```
#
# Grove I2C タッチセンサ
#
groveI2C_Touch:
  use_groveI2C_Touch: true # true(使う) , false(使わない)
  sensor_id: -1
```

## 利用のスイッチ
センサを使う場合は，この項目にtrueを設定する．
```
use_groveI2C_Touch: true # true(使う) , false(使わない)
```


## センサID
この数字を変更することで，多数のセンサが交じる環境で，このセンサのデータを特定することが可能．
```
sensor_id: -1
```

***

- [「センサの定義」に戻る](../SensorDefinition.md)


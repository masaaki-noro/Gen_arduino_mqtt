# Grove - Water Sensor

これは，センサを土などに差し込み，土などが含む水分の量に応じて，センサの出力電圧が変化するタイプのセンサである．

- Grove - Water Sensor https://wiki.seeedstudio.com/Grove-Water_Sensor/

## 設定項目
設定すべき項目は3つ存在し，以下は設定ファイルのデフォルトを表している．

```
#
# Grove水検知センサ
#
waterDetection:
  use_waterDetection: true # true(使う) , false(使わない)
  waterDetection_pin: 2
  sensor_id: -1
```

## 利用のスイッチ
センサを使う場合は，この項目にtrueを設定する．
```
use_waterDetection: true # true(使う) , false(使わない)
```

## 接続端子の指定
Arduinoに接続した際に作ったメモのピン番号をそのまま書き込めば良い．

下の例(デフォルト)は，デジタル端子の2番に接続していることを表している．
```
waterDetection_pin: 2
```



## センサID
この数字を変更することで，多数のセンサが交じる環境で，このセンサのデータを特定することが可能．
```
sensor_id: -1
```

***

- [「センサの定義」に戻る](../SensorDefinition.md)

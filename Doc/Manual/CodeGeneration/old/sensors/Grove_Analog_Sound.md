# Grove - Sound Sensor

これは，簡易なマイクから出力される音声信号の強弱で音圧/音量を測定するタイプのセンサでする．

- Grove - Sound Sensor https://wiki.seeedstudio.com/Grove-Sound_Sensor/


## 設定項目
設定すべき項目は3つ存在し，以下は設定ファイルのデフォルトを表している．

```
#
# Grove analog sound
#
groveAnalogSound:
  use_groveAnalogSound: true # true(使う) , false(使わない)
  groveAnalogSound_pin: A3
  sensor_id: -1
```

## 利用のスイッチ
センサを使う場合は，この項目にtrueを設定する．
```
use_groveAnalogSound: true # true(使う) , false(使わない)
```

## 接続端子の指定
センサをどのアナログ端子に接続するかを明示する．
```
groveAnalogSound_pin: A3
```

上の例はアナログ端子の3番に接続していることを示しているが，ここにはセンサをArduinoに接続した際に作成したメモを参照して記入する．

## センサID
この数字を変更することで，多数のセンサが交じる環境で，このセンサのデータを特定することが可能．
```
sensor_id: -1
```

***

- [「センサの定義」に戻る](../SensorDefinition.md)

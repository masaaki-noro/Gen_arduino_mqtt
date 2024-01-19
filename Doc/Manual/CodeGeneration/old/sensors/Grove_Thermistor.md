# Grove - Temperature Sensor 

これは，サーミスタを使った温度センサで，このGroveモジュールの詳細は以下のWebに記載されている．
なお，サーミスタとは，温度で抵抗値が変化する電気抵抗である．


- Grove - Temperature Sensor https://wiki.seeedstudio.com/Grove-Temperature_Sensor_V1.2/


## 設定項目
設定すべき項目は3つ存在し，以下は設定ファイルのデフォルトを表している．

```
#
# Grove analog temperature
#
analogTemperature:
  use_analogTemperature: true # true(使う) , false(使わない)
  analogTemperature_pin: A3
  sensor_id: -1
```

## 利用のスイッチ
センサを使う場合は，この項目にtrueを設定する．
```
use_analogTemperature: true # true(使う) , false(使わない)
```

## 接続端子の指定
センサをどのアナログ端子に接続するかを明示する．
```
analogTemperature_pin: A3
```

上の例はアナログ端子の3番に接続していることを示しているが，ここにはセンサをArduinoに接続した際に作成したメモを参照して記入する．



## センサID
この数字を変更することで，多数のセンサが交じる環境で，このセンサのデータを特定することが可能．
```
sensor_id: -1
```

***

- [「センサ端末の詳細定義」に戻る](../CodeGeneration/TotalDefinition.md)

# Grove - GSR Sensor

指に測定用の端子をつけて，その端子間の電流の流れやすさを測定するためのセンサである．

- Grove - GSR Sensor https://wiki.seeedstudio.com/Grove-GSR_Sensor/


## 設定項目
設定すべき項目は3つ存在する．

```
#
# Grove GSR
#
groveGSR:
  use_groveGSR: true # true(使う) , false(使わない)
  groveGSR_pin: A3
  sensor_id: -1
```

### 利用のスイッチ
センサを使う場合は，この項目にtrueを設定する．
```
use_groveGSR: true # true(使う) , false(使わない)
```

### 接続端子の指定
センサをどのアナログ端子に接続するかを明示する．
```
groveGSR_pin: A3
```

上の例はアナログ端子の3番に接続していることを示している．



### センサID
この数字を変更することで，多数のセンサが交じる環境で，このセンサのデータを特定することが可能．
```
sensor_id: -1
```


***

- [「センサ端末の詳細定義」に戻る](../CodeGeneration/TotalDefinition.md)

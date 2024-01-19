# Grove - Rotary Angle Sensor

このGroveモジュールの詳細は以下のWebに記載されている．

- Grove - Rotary Angle Sensor https://wiki.seeedstudio.com/Grove-Rotary_Angle_Sensor/


このモジュールの動作原理はオーディオ機器のボリューム等と同じで回転させると
電気抵抗が変化するので，それを読み取ることでどの程度回転したかを判断するものである．


## 設定項目
設定すべき項目は3つ存在する．

```
#
# Grove Rotaly Angle sensor
#
analogRotalyAngle:
  use_analogRotalyAngle: true # true(使う) , false(使わない)
  analogRotalyAngle_pin: A3
  analogRotalyAngle_vdd: 3.3
  sensor_id: -1
```

### 利用のスイッチ
センサを使う場合は，この項目にtrueを設定する．
```
use_analogRotalyAngle: true # true(使う) , false(使わない)
```

### 接続端子の指定
センサをどのアナログ端子に接続するかを明示する．
```
analogRotalyAngle_pin: A3
```

上の例はアナログ端子の3番に接続していることを示している．


### パラメータ
```
analogRotalyAngle_vdd: 3.3
```
そもそも，このモジュールは電気抵抗を測定することで回転した角度を計算するため，計算に必要な電源電圧(3.3 or 5.0)を与える．

### センサID
この数字を変更することで，多数のセンサが交じる環境で，このセンサのデータを特定することが可能．
```
sensor_id: -1
```
***

- [「センサの定義」に戻る](../SensorDefinition.md)

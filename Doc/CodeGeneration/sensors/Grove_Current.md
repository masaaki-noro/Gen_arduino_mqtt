# Grove - Electricity Sensor

これは，センサを土などに差し込み，土などが含む水分の量に応じて，センサの出力電圧が変化するタイプのセンサである．

- Grove - Electricity Sensor https://wiki.seeedstudio.com/Grove-Electricity_Sensor/


## 設定項目
設定すべき項目は5つ存在し，以下は設定ファイルのデフォルトを表している．

```
#
# Grove電流センサ
#
groveCurrent:
  use_groveCurrent: true # true(使う) , false(使わない)
  groveCurrent_pin: A3
  groveCurrent_vdd: 3.3
  groveCurrent_mode: 0 # 0 , 1
  sensor_id: -1
```

## 利用のスイッチ
センサを使う場合は，この項目にtrueを設定する．
```
use_groveCurrent: true # true(使う) , false(使わない)
```

## 接続端子の指定
センサをどのアナログ端子に接続するかを明示する．
```
groveCurrent_pin: A3
```

上の例はアナログ端子の3番に接続していることを示しているが，ここにはセンサをArduinoに接続した際に作成したメモを参照して記入する．


## パラメータ
```
groveCurrent_vdd: 3.3
```
このセンサはアナログ端子にかかる電圧からコイルに流れる電流を計算するため，測定回路にかかっている電圧が必要になる．この電圧を指定するパラメータがこれにあたる．
センサを繋いだArduinoの動作電圧を記入する．

```
groveCurrent_mode: 0 # 0 , 1
```
このセンサでは，複数回の測定を行い，その平均値を返す(モードが0)場合と，ピーク(最大値)の値を返す場合(モードが1)で選択することができる．

### センサID
この数字を変更することで，多数のセンサが交じる環境で，このセンサのデータを特定することが可能．
```
sensor_id: -1
```


***

- [「センサ端末の詳細定義」に戻る](../CodeGeneration/TotalDefinition.md)

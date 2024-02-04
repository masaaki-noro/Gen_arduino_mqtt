# Grove - Electricity Sensor

これは，センサを土などに差し込み，土などが含む水分の量に応じて，センサの出力電圧が変化するタイプのセンサである．

- Grove - Electricity Sensor 製品ページ : https://wiki.seeedstudio.com/Grove-Electricity_Sensor/


## 設定項目


<div style="text-align: center;">
<img src="../../images/editConfig_Grove_Current.png" width="30%">
</div>



### センサID
この数字を変更することで，多数のセンサが交じる環境で，このセンサのデータを特定することが可能．



### 接続端子の指定
センサをどのアナログ端子に接続するかを明示する．

上図の例はアナログ端子の3番に接続していることを示している．


### 電圧

このセンサはアナログ端子にかかる電圧からコイルに流れる電流を計算するため，測定回路にかかっている電圧が必要になる．この電圧を指定するパラメータがこれにあたる．
センサを繋いだArduinoの動作電圧(3.3 or 5.0)を記入する．


### 動作モード

このセンサでは，複数回の測定を行い，その平均値を返す(モードが0)場合と，ピーク(最大値)の値を返す場合(モードが1)で選択する．



***

- [「センサ端末の詳細定義」に戻る](../CodeGeneration/TotalDefinition.md)

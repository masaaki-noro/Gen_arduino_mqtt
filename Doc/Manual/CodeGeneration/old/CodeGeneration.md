# Arduinoスケッチ(プログラム)の生成


Arduinoにインストールするスケッチを生成するプログラムが``genSketch.py``(下図参照)である．

![genSketch画面](../images/genSketch画面.png)

ここで，先程編集した詳細定義のyamlファイルを「``config file``」ボタンで選択し，
「``output directory``」ボタンでスケッチを出力するディレクトリを選ぶ．

最後に，「``Create Arduino sketch``」ボタンで生成を実行となる．

先程選択したスケッチ出力先のディレクトリに「``AusEx_MqttClient``」という
ディレクトリができており．``AusEx_MqttClient.ino``というファイルやいくつかの
C++のプログラムが含まれているはずである．

***
- [「スケッチのインストール」に進む](Install.md)
- [「センサの定義」に戻る](SensorDefinition.md)
- [マニュアルトップに戻る](../Manual.md)


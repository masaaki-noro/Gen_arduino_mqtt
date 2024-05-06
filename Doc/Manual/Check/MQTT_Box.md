# 動作確認(MQTTアプリケーション編)
下の図はユーザが開発するセンサ端末の動作テストに利用する環境を示している．
ユーザが動作確認に用いるのは開発用PCとなる．

<div style="text-align: center;">
<img src="../images/Test_Environment.png" width="80%">
</div>


## 1. Windowsの場合
### 1.1 テスト用アプリケーションのインストール

テストに用いるアプリケーションは，「MQTT Box」というMQTTクライアントアプリケーションである．
まず，最初にMQTT Boxをインストールする．
MQTT BoxはMac, Windows, Linux, Chrome OSの全てで動作するアプリケーションで，下図は
マイクロソフトストアのMQTT Boxの画面である．

<div style="text-align: center;">
<img src="../images/MQTT_box_マイクロソフトストア.png" width="80%">
</div>


### 1.2 MQTT Boxの設定
下の図はMQTT Box起動時の初期画面である．最初に，「Create MQTT Client」ボタンを押す．

<div style="text-align: center;">
<img src="../images/MQTT_box_初期画面.png" width="80%">
</div>

次に，Arduinoのテストに用いるパラメータを設定する．

- ➀ 適当な名前を入力
- ➁ 「mqtt/tcp」を選択
- ➂,➃ MQTTの認証を行う場合は，認められているユーザ名とパスワードを入力
- ➄ mosquittoが動作するIoTゲートウェイのIPアドレスを入力
- ➅ 「Save」ボタンを押す

➀は，MQTTに関する設定を保存して，別の時に流用するために用いるものであるため，特に規制はない．
➂と➃に入力する項目については，MQTTの認証を行うか否かであるため，IoTゲートウェイのIPアドレスや認証のユーザ名(とパスワード)は管理者に確認すること．
➄については，管理者から教えられたIoTゲートウェイの情報を入力する．


<div style="text-align: center;">
<img src="../images/MQTT_box_setting.png" width="80%">
</div>

MQTT Boxのクライアント画面の右側(subscribe欄)に，Arduino設定で定義した「トピック」の文字列を入力し，「Subscribe」ボタンを押す．

<div style="text-align: center;">
<img src="../images/MQTT_box_監視画面.png" width="80%">
</div>

### 1.3 MQTT Boxによる動作確認
下の図は，温湿度・気圧センサであるBME280を搭載したArduinoをテスト環境のネットワークに接続した場合の画面である．
この図にあるように，一番上に気圧，次に，気温，最後に温度が出力されているのが読み取れる．

<div style="text-align: center;">
<img src="../images/MQTT_box_実行例.png" width="80%">
</div>


先程の温度,湿度,気圧の出力文字列と下図のような，Arduino IDEのシリアル監視画面に出力されている内容が一致していることを確認する．

<div style="text-align: center;">
<img src="../images/センサ端末実行例_IDE.png" width="80%">
</div>

## 2. MacやLinuxの場合
MacやLinuxでは，MQTTをサポートしたツール(Mosquitto)が利用できます．

Macの場合は，以下のURLを参照して，brewでインストールする．
- 「https://qiita.com/segur/items/0536ced1fe741b55713d」

なお，以下の2つのパスを環境変数に追加することを忘れない用にしてください．
- /usr/local/opt/mosquitto/sbin
- /usr/local/opt/mosquitto/bin

また，動作確認時は以下のコマンドを使ってください．
```
$ mosquitto_sub -d -t orz -h MQTTブローカのIPアドレス –topic センサ端末のトピック
```


***
- [マニュアルトップに戻る](../Manual.md)

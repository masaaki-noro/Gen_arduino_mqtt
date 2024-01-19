# ハードウェアの定義
Arduino用プログラムの生成は以下の2つのステップで行う．

- センサ端末のハードウェアを記述した定義ファイルから，センサ端末の詳細な定義ファイルのテンプレートを出力
- 出力されたテンプレートを編集して，センサ端末の詳細な定義を作り，この定義からセンサ端末のプログラムを生成

最初に，ハードウェアの定義ファイルを作成する．

この定義ファイルはテンプレートを編集する方法とPythonのアプリケーションで
対話的に生成する方法の2種類が存在する．


## 専用アプリ``genHardDef.py``による方法

本プロジェクトの関連ファイルのトップディレクトリに移動し，pythonで``genHardDef.py``を起動する．

UNIXのshell環境では以下のように実行する．
```
$ python genHardDef.py
```

下図は起動時の画面である．
![genHardDef起動時画面](../images/genHardDef起動時画面.png)


### 出力ファイルの選択
最初に「``hardware definition file``」をクリックし，出力するファイルを先に選択する．

選択すると，下のように，ファイルのパスが表示される．
![ハード定義ファイル選択後の画面](../images/ハード定義ファイル選択後の画面.png)

もし，作業をやめる場合は「``Close``」をクリックする．

作業を続ける場合は「``Next``」をクリックする．


### プラットフォームの定義
下はプラットフォームの定義画面である．
![プラットフォーム定義画面](../images/プラットフォーム定義画面.png)


最初に``Arduino Family``のプルダウンメニューで，利用するArduinoのファミリ(classicやMKR等)が何であるかを選択する．

次に，``network type``メニューで，WiFiもしくはイーサネットのいずれを使うかを選択する．

RTCを使わない場合は，``RTC``メニューで``none``を選び，RTCを使う場合は利用するICの型番を選択する．
利用可能なICは以下の8種類．
- PCF8523 , RTC8564NB , DS1307 , DS3231 , PCF8523 , RV8803 , RX8025 , RX8900

あとは，``LED``と``SD``を使うか否かをスイッチで定義する．

もし，システム管理者からハードウェアを配布されている場合は，その機種と接続されている
周辺機器と同じものをこの画面で選択する．

ここまで終われば「``Next``」ボタンを押す．

### 環境系センサの選択

温湿度センサ等の環境測定系のセンサを使う場合は，利用するセンサICのスイッチをONにした上で「``Next``」ボタンをクリックする．

![環境系センサ選択画面](../images/環境系センサ選択画面.png)

環境測定系のセンサを使わない場合は，何も選択せずに「``Next``」を押す．

### 振動・加速度センサの選択

振動センサ，加速度センサを使う人は，利用するICのスイッチをONにして，「``Next``」ボタンをクリックする．
![振動・加速度センサ選択画面](../images/振動・加速度センサ選択画面.png)


### 対人センサの選択
PIRセンサやタッチセンサなど，人を対象するセンサを使う場合は，この画面で利用するセンサのスイッチをONにする．
![対人センサ選択画面](../images/対人センサ選択画面.png)

利用しない人は何も選択せずに，そのまま``Next``をクリックする．

### 視覚関連センサ
色センサ等の視覚関連センサを利用する場合は，この画面で利用するセンサICのスイッチをONにする．
![視覚関連センサ選択画面](../images/視覚関連センサ選択画面.png)


### その他の種類のセンサ
次の画面は上記の分類に属さないセンサを選択する画面である．
![その他のセンサ選択画面](../images/その他のセンサ選択画面.png)

利用するセンサに対応するスイッチのみをONにして，``Next``をクリックする．

### 定義ファイルの生成
ここまでの選択内容に問題がなければ，``Generate Hardware Config``ボタンをクリックして定義ファイルを生成する．
![ハードウェア定義生成画面](../images/ハードウェア定義生成画面.png)

ここまでの定義を確認する場合は，``Back``ボタンを使い，定義を確認する．


## テンプレートの編集による方法
ハードウェアの定義ファイルを自分で編集する場合は，以下のテンプレートの内容を適当なファイル名で保存する．
```
platform:
  type: mkr # classic , mega , nano , mkr , none
  network: wifi # wifi , ethernet 
  rtc: PCF8523 # RTC8564NB , DS1307 , DS3231 , PCF8523 , RV8803 , RX8025 , RX8900 , none
  use_led: true # true(使う) , false(使わない)
  use_sd: true # true(使う) , false(使わない)

sensor:
  # I2C
  #sht31: true # true(使う) , false(使わない)
  #sht2x: true # true(使う) , false(使わない)
  #am232x: true # true(使う) , false(使わない)
  #bme280: true # true(使う) , false(使わない)
  #bmp180: true # true(使う) , false(使わない)
  #adxl345: true # true(使う) , false(使わない)
  #mma7660: true # true(使う) , false(使わない)
  #itg320: true # true(使う) , false(使わない)
  #groveI2C_Touch: true # true(使う) , false(使わない)
  #tcs34725: true # true(使う) , false(使わない)
  #tsl2561: true # true(使う) , false(使わない)
  #use_hts221: true # true(使う) , false(使わない)
  #use_lps22hb: true # true(使う) , false(使わない)
  # digital
  #dht: true # true(使う) , false(使わない)
  #digitalSwitch: true # true(使う) , false(使わない)
  #groveTouch: true # true(使う) , false(使わない)
  #waterDetection: true # true(使う) , false(使わない)
  #groveLineFinder: true # true(使う) , false(使わない)
  #groveDistanceInterrupter: true # true(使う) , false(使わない)
  #groveIrRefrect: true # true(使う) , false(使わない)
  #grovePIR: true # true(使う) , false(使わない)
  # analog
  #adxl335: true # true(使う) , false(使わない)
  #murataENC03: true # true(使う) , false(使わない)
  #analogTemperature: true # true(使う) , false(使わない)
  #analogRotalyAngle: true # true(使う) , false(使わない)
  #groveAnalogLight: true # true(使う) , false(使わない)
  #groveAnalogSound: true # true(使う) , false(使わない)
  #groveAnalogMoisture: true # true(使う) , false(使わない)
  #groveGSR: true # true(使う) , false(使わない)
  #groveCurrent: true # true(使う) , false(使わない)
  #use_temt6000: true # true(使う) , false(使わない)
```


### 基本システムの定義内容
基本システムの定義部分は以下のようなものになっている．
```
platform:
  type: mkr # classic , mega , nano , mkr , none
  network: wifi # wifi , ethernet , none
  rtc: PCF8523 # RTC8564NB , DS1307 , DS3231 , PCF8523 , RV8803 , RX8025 , RX8900 , none
  use_led: true # true(使う) , false(使わない)
  use_sd: true # true(使う) , false(使わない)
```
定義の各項目について説明する．

#### ``type``
ここは，仕様するArduinoのファミリが何であるかを定義する項目である．
基本システムを構成するArduinoがどのファミリに分類されるかは，[公式サイトのハードウェアページ](https://www.arduino.cc/en/hardware)を参照して
いただきたい．

この定義はGroveシールドを使う場合のコネクタ数等を数えることを想定しているが，現在未実装であるため，``none``にしてもかまわない．

#### ``network``

ここの定義は，基本システムが備えているネットワークが有線イーサネットかWiFiかを選択する．


#### ``rtc``
基本システムに接続しているRTCのICの種別を選択する．
上の例では，「NXP Semiconductors」の「PCF8523」を使うことを指示している．


#### ``use_led``
基本システムに[LED](https://wiki.seeedstudio.com/Grove-Chainable_RGB_LED/)を採用しているか否かを記載する．
採用している場合は``true``，そうでなければ``false``を記入する．


#### ``use_sd``
基本システムにマイクロSDスロットが存在するか否かを記載する．
マイクロSDスロットがある場合は``true``，そうでなければ``false``を記入する．


### センサの定義
センサ定義部分の例を下に示す．下の例では，大量にコメントアウトされている行があるが，これらの行は無視されるため，利用するセンサのみコメントを外し，``true``と定義する．

```
sensor:
  # I2C
  sht31: true # true(使う) , false(使わない)
  sht2x: false # true(使う) , false(使わない)
  #am232x: true # true(使う) , false(使わない)
  bme280: true # true(使う) , false(使わない)
  #bmp180: true # true(使う) , false(使わない)
  #adxl345: true # true(使う) , false(使わない)
  #mma7660: true # true(使う) , false(使わない)
  #itg320: true # true(使う) , false(使わない)
  #groveI2C_Touch: true # true(使う) , false(使わない)
  #tcs34725: true # true(使う) , false(使わない)
  #tsl2561: true # true(使う) , false(使わない)
  #use_hts221: true # true(使う) , false(使わない)
  #use_lps22hb: true # true(使う) , false(使わない)
  # digital
  #dht: true # true(使う) , false(使わない)
  #digitalSwitch: true # true(使う) , false(使わない)
  #groveTouch: true # true(使う) , false(使わない)
  #waterDetection: true # true(使う) , false(使わない)
  #groveLineFinder: true # true(使う) , false(使わない)
  #groveDistanceInterrupter: true # true(使う) , false(使わない)
  #groveIrRefrect: true # true(使う) , false(使わない)
  #grovePIR: true # true(使う) , false(使わない)
  # analog
  #adxl335: true # true(使う) , false(使わない)
  #murataENC03: true # true(使う) , false(使わない)
  #analogTemperature: true # true(使う) , false(使わない)
  #analogRotalyAngle: true # true(使う) , false(使わない)
  #groveAnalogLight: true # true(使う) , false(使わない)
  #groveAnalogSound: true # true(使う) , false(使わない)
  #groveAnalogMoisture: true # true(使う) , false(使わない)
  #groveGSR: true # true(使う) , false(使わない)
  #groveCurrent: true # true(使う) , false(使わない)
  #use_temt6000: true # true(使う) , false(使わない)
```

下は，上の例から，コメントアウトされていない行だけを抜き出したものである．
この例では，SHT31とBME280の2つがセンサ端末に接続されていると見なし，SHT2Xは``false``であるため，繋がっていないと見なされる．
```
sensor:
  sht31: true # true(使う) , false(使わない)
  sht2x: false # true(使う) , false(使わない)
  bme280: true # true(使う) , false(使わない)
```


## センサ端末の詳細定義ファイルの生成
詳細定義ファイルを生成するプログラムは，「genConfig.py」である．

![genConfig起動時画面](../images/genConfig起動時画面.png)

上は起動時画面で，「``hardware definition file``」ボタンと「``config file``」
を使って，先程作成したハードウェア定義ファイルと詳細定義を出力するyamlファイルを選択し，
「``Create Config File``」ボタンを押して，詳細定義を含むyamlファイルを生成する．

***
- [「センサ端末の詳細定義」に進む](TotalDefinition.md)
- [マニュアルトップに戻る](../Manual.md)



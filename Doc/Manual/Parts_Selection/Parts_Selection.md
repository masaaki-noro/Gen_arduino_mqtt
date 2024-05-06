# 部材の選択

本開発環境で作成するセンサ端末は，基本となるマイコンにセンサを取り付けて動作させるが，
基本となる部分として必要なものは，Arduino(もしくは互換機)以外に下表の3つのモジュールである．

|種類|用途|
|---|---|
|フルカラーLED|動作状況を見た目で判断できるようにするため|
|RTC|ログや送信する測定結果に時刻を含めるために利用|
|マイクロSD|ログを残すため|

ここでは，各部材の機能から必要性を判断していただきたい．
ただし，Arduinoにセンサを取り付けて，ソフトウェアを生成した上で，動作確認するまでの
ドキュメントについては，RTCやLEDなどが取り付けられていることを前提としたものとなっている．

学生の実習などを想定すると，PCとセンサ端末をUSBを繋いだままでログの監視やエラーの有無も確認できるため，
LEDやマイクロSDはなくても済むが，PCとの接続無しで動作させることを考えると，LEDとマイクロSDは必要になる．

また，RTC無しだとセンサ端末が測定した時刻がサーバ側に送られるデータに含まれなくなるため，
時刻を気にする必要がある用途では重要となる．RTC無しで時刻情報を取得することもできるが，
センサ端末が毎回の測定時にNTP (Network Time Protocol)通信を行うことになるため，
センサネットワーク上にNTPのサーバの準備が必要になるためお勧めしない．


## 1. フルカラーLED
現在利用可能なLEDは以下のもののみ．
- https://wiki.seeedstudio.com/Grove-Chainable_RGB_LED/

これを選択した理由はフルカラーでGrove対応がこれしかなかったため．
LEDのサイズが大きすぎるとか，本来5V専用で3.3Vマイコンで駆動するのに心配があるなど，問題は多いものの，
Grove対応の基板を使って新規にLEDモジュールを作成するよりはマシという判断からこのLEDを採用している．

## 2. RTC
本開発環境では，時計として使うRTCは7種類サポートしているものの，
電子工作の素人でも簡単に組み立てできることが重要であるため，
推奨品を選択することを強く勧める．

### 2.1. 推奨品
以下のRTCは電池ボックス付きのモジュール(Breakoutモジュール)がAdafruitから発売されており，電池もCR1220(国内メーカー品あり)が利用できること，
下記モジュールは[Grove用の変換ケーブル](https://www.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html)で簡単にGroveのシールドに接続できることから推奨する．

- DS3231 (Analog Devices) https://www.adafruit.com/product/3013

### 2.2. あまり勧めない
下のRTCは電池ボックス付きのモジュール(Breakoutモジュール)がAdafruitから発売されており，電池もCR1220(国内メーカー品あり)が利用できるものの，電池ボックスに
ボタン電池を入れても電源の抜き差し後に時刻情報が失われる確率が非常に高く，電池の挿し直しや異なるモジュールを用いて試験を行っても，安定して動作しない．
また，Adafruitの製品ページにも記載があるように，RTCのIC自体の時刻の精度もあまり良くない(毎日2秒程度の変動が発生する)ことから推奨しない．
ただし，推奨品(DS3231)と比べてモジュールの値段が安い(約1/3)ため，実験目的等では有用かもしれない．

- PCF8523 (NXP Semiconductors) https://www.adafruit.com/product/3295 , https://www.adafruit.com/product/5189

以下のモジュールは，Groveにそのまま接続でき，便利に思われるが，対応している電池がCR1225と日本メーカーが既に製造していない型式の電池が必要になる
上，電池ボックスのプラスチックが脆弱で，入れた電池を取り外すそうとすると割れてしまい，電池ボックスが2度と使えなくなる可能性が高いため推奨しない．

- DS1307 (Analog Devices) https://wiki.seeedstudio.com/Grove-RTC/

RV8803は，電池ボックス付きのモジュールとしては以下のものがあるが，モジュールの生産が中止されており，電池もCR1225を要求するため非推奨品．
- RV8803 (Micro Crystal AG) https://www.sparkfun.com/products/16281

以上のことから，``PCF8523``と``DS1307(Grove-RTC)``は電池無しの場合は利用可能．``DS1307(Grove-RTC)``は配線に特別なケーブルが必要ないため，
電池無しで運用するならお勧め．

### 2.3. 工作(基板の作成)が必要
以下の3つのRTC(全てエプソン)は，電池ボックス付きでモジュール化されたものが存在しないため，電子部品の調達，基板工作(はんだ付け)が必要になることから非推奨品．
- RTC-8564NB
- RX8025
- RX8900

ただし，自分で工作できる人は上記RTCはエプソンから技術資料が日本語で入手できること，RTC-8564NBは秋月電子で
工作が簡単なモジュールが発売されているため，入手も難しくない上に，電池ボックスだけの拡張で済む点は有利．

### 2.4. 電池の必要性
本開発環境で生成されるArduinoのスケッチでは，RTCに電池が挿入されていない場合に，電源投入時にそれを検出して，デフォルトの時刻(2001年1月1日0時0分0秒)を
設定するプログラムになっている．

そのため，動作確認や簡単な実験目的なら問題無いが，実際にセンサ端末を配備して，データを収集する場合は
電池無しの運用は勧めない．

もし，デフォルトの時刻を変更したい場合は，カスタマイズに関する資料を参照していただきたい．

## 3. マイクロSD
マイクロSDとArduinoの接続は，Classicファミリのうち5Vで動作する機種とMKRファミリの全機種はシールドが存在するため利用を推奨できる．

また，マイクロSDそのものについても制限があり，Arduinoと接続するためには，ソフトウェア，ハードウェアの制約上(対応する規格の問題)から容量が16GB以下のものに限定される．

### 3.1. Arduino Classicファミリ
Classic用のシールドは本体が5V駆動のものにしか対応していないものが多く，それを利用する場合は機種が限定される．ただし，以下の「SparkFun microSD Shield」は本体が3.3Vでも
動作することが確認できている．


- [Arduino Ethernet Shield 2](https://store-usa.arduino.cc/products/arduino-ethernet-shield-2)

<div style="text-align: center;">
<img src="../images/Classic_Ethernet.png" width="70%">
</div>




- [SD Card Shield](https://www.seeedstudio.com/SD-Card-Shield-V4-p-1381.html)


- [SparkFun microSD Shield](https://www.sparkfun.com/products/12761)


- ピンヘッダ : [Adafruit](https://www.adafruit.com/product/85), [秋月電子1](https://akizukidenshi.com/catalog/g/gC-17103/), [秋月電子2](https://akizukidenshi.com/catalog/g/gC-17102/)





### 3.2. Arduino MKRファミリ
MKRファミリのうち，MKR ZeroはマイクロSDのスロットが存在しているため，準備は不要．

それ以外のMKRファミリのArduinoを使う場合は以下のシールドを用意してください．

- MKR SD Proto Shield https://store-usa.arduino.cc/products/mkr-sd-proto-shield

### 3.3. Arduino Nanoファミリ
Arduino Nanoはジャンパケーブル等を使って，SDの回路を外部に用意する必要があるため，SDの利用は勧められないが，
ArduinoのNanoにマイクロSDをつなげる場合は，以下のモジュールの利用を推奨する．

- MicroSD card breakout board+ (Adafruit) https://www.adafruit.com/product/254

### 3.4. Arduino Megaファミリ
Megaファミリのうち，センサ端末として動作するのはGigaのみである．
また，Gigaは3.3V動作であることや，Megaファミリの3.3V用Groveシールドが存在しないため，
Uno R4でも使える以下のSparcfunのマイクロSDシールドが適している．

- [SparkFun microSD Shield](https://www.sparkfun.com/products/12761)

## 4. マイコン本体+ネットワークI/F
本開発環境で生成するセンサ端末用のスケッチはメモリが少ないMCUでは動作しないことなどから，選択できる機種に制限がある．
最近発売された機種については，検証ができていないため，動作の可否は不明である．

また，Arduino本体については互換機は含めない．

### 4.1. 動作確認済み
|機種名|MCU|動作周波数|プログラム容量(flash)|メモリ容量(SRAM)|
|---|---|---|---|---|
|MKR ZERO+イーサネットシールド|SAMD21|48MHz|256KB|32KB|
|MKR WiFi 1010|SAMD21|48MHz|256KB|32KB|
|Nano 33 IoT|SAMD21|48MHz|256KB|32KB|


### 4.2. 機能制限あり

最近リリースされたUnoのR4はMCUが新採用のルネサスのものであるため，
WDTとスリープ(低電力モード)を利用することができない．Giga R1 WiFiのSTマイクロ製チップも同様である．
そのため，WDTとスリープを無効にする設定で以下の機種は動作が確認できている．

|機種名|MCU|動作周波数|プログラム容量(flash)|メモリ容量(SRAM)|
|---|---|---|---|---|
|Uno R4 Minima+イーサネットシールド|RA4M1|48MHz|256KB|32KB|
|Uno R4 WiFi|RA4M1|48MHz|256KB|32KB|
|Giga R1 WiFi|STM32H7|480MHz(240MHz)|2M|1M|

なお，GigaのMCUは不均等なデュアルコアで，メインコアがARM M7，サブコアがARM M4であり，
メインコアが480MHz動作，サブコアが240MHz動作となっている．

### 4.3. 問題あり

#### 4.3.1 ESP32
各種ESP32搭載ボードは，マイクロSDとの通信速度が非常に低速であり，
センサ端末として動作させるには問題がある．
WDTの動作に不審な点があり，時々再起動してしまう問題もある．

追加で1点注意事項として，低電力モード(sleep)のうち，最も消費電力が低いモード(``MODE_PWR_DOWN``)を選択すると，
ESP32は復帰時には再起動になる．

- ESPr One 32 https://www.switch-science.com/products/3555
- Arduino Nano ESP32 https://store-usa.arduino.cc/products/nano-esp32?selectedStore=us

Groveに接続して利用することを想定すると，上の2機種ならGroveのシールドが接続できる．ただし，nanoのGroveシールド(基板)は2023年7月末頃にリリースされたv1.3の
シールドのみがNano ESP32に対応しているものの，2023年11月現在，国内では手に入らないこととに注意が必要．
Seeed systemから直輸入すれば購入できるかもしれないが未確認．

そのため，現状nano esp32を使う場合，ブレッドボードで配線することになる．

<div style="text-align: center;">
<img src="../images/nano_esp32_ブレッドボード.JPG" width="70%">
</div>

#### 4.3.2 Arduino Nano RP2040
Raspberry Pi Picoと同じMCUを搭載したこの機種は，Watch Dogや低電力モードが使えない．
また，Groveシールドが存在しないため，ESP32と同じく，自分でGrove用のシールドを作成するか，ブレッドボードで配線する
必要がある．


### 4.4. 動作しない
Uno R3, Mega等のAVR系統のMCUを搭載したプラットフォームはそもそもプログラム容量やSRAMの容量不足により動作しない．

|機種名|MCU|動作周波数|プログラム容量(flash)|メモリ容量(SRAM)|
|---|---|---|---|---|
|Uno R3|ATmega328P|16MHz|32KB|2KB|
|Mega2560|ATmega2560|16MHz|256KB|8KB|



***
- [「Arduinoの機種別のパーツリスト」に進む](Parts_List.md)
- [マニュアルトップに戻る](../Manual.md)


# センサの選択

本開発環境で生成されるセンサ端末用スケッチ(プログラム)では，1台のセンサ端末に搭載可能なセンサは1つに限られない．
ただし，同一種類(LSI/モジュール)のセンサは1つに限られる．もし，温湿度センサを複数搭載するような場合，異なるセンサチップ(IC/LSI)のもの
を用いる必要がある．

また，温湿度センサや照度センサ等そもそも異なる種類のセンサであれば，1台のセンサ端末に搭載可能．
ただし，接続コネクタ(ピン)数やArduino本体の電源容量の制限に注意が必要．

以下は現状利用可能なセンサの一覧である．下のセンサの中から1つ以上のセンサを選択し，準備されている(配布された)基本システムに接続する．
この時，接続したコネクタの種類(名前)と接続したコネクタの番号はメモしておく(I2Cのセンサは名前のみ)．

各センサの配線/接続方法はセンサ名のリンクを開いた先の資料に記述されているため，そちらを参照．
なお，表のGroveコネクタ列が「✕」のものは独自の配線が必要になるため要注意．

## 1. センサ選択における注意事項

全てのセンサが全ての機種のArduinoで使えるわけではない．
Arduinoには動作電圧が5Vのものと3.3Vのものがあり，また，CPUアーキテクチャも3種類以上ある．
そのため，センサの動作電圧の制限や，センサ用のソフトウェア(デバイスドライバ)の制限から
特定の機種でしか使えないものが存在するため，注意が必要．

確認するためには，IDEのセットアップの際に，同時にインストールしたセンサ用ライブラリ(デバイスドライバ)の
各センサ用ディレクトリ内のREADME.mdおよび，以下のセンサ表のセンサ名をクリックして，
説明資料を参照すること．


## 2. 環境測定系センサ

|センサ名|温度|湿度|気圧|インターフェース|Groveコネクタ|
|---|---|---|---|---|---|
|[BME280](sensors/BME280.md)|◯|◯|◯|I2C|△|
|[BMP180](sensors/BMP180.md)|✕|✕|◯|I2C|◯|
|[SHT31](sensors/SHT31.md)|◯|◯|✕|I2C|△|
|[SHT2X](sensors/SHT2x.md)|◯|◯|✕|I2C|△|
|[AM232X](sensors/AM232X.md)|◯|◯|✕|I2C|△|
|[DHT](sensors/DHT.md)|◯|◯|✕|デジタル✕1|◯|
|[Grove - Temperature Sensor](sensors/Grove_Thermistor.md)|◯|✕|✕|アナログ✕1|◯|
|[LPS22HB](sensors/LPS22HB.md)|✕|✕|◯|I2C|△|
|[HTS221](sensors/HTS221.md)|◯|◯|✕|I2C|△|

### Groveコネクタ列
- ◯ Grove用のケーブルで直接接続可能
- △ 変換ケーブルで接続する必要がある
- ✕ ジャンパケーブルで配線する必要がある

## 3. 振動・加速度等

|センサ名|加速度(軸数)|ジャイロ(軸数)|インターフェース|Groveコネクタ|
|---|---|---|---|---|
|[ITG3200](sensors/ITG3200.md)|✕|3|I2C|◯|
|[MMA7660](sensors/MMA7660.md)|3|✕|I2C|◯|
|[ADXL345](sensors/ADXL345.md)|3|✕|I2C|◯|
|[ADXL335](sensors/ADXL335.md)|3|✕|アナログ✕3|✕|
|[村田ENC03R](sensors/ENC03R.md)|✕|1|アナログ✕1|◯|

### Groveコネクタ列
- ◯ Grove用のケーブルで直接接続可能
- △ 変換ケーブルで接続する必要がある
- ✕ ジャンパケーブルで配線する必要がある

## 4. 対人

|センサ名|接触|人感(赤外線)|インターフェース|Groveコネクタ|
|---|---|---|---|---|
|[GROVE - I2C タッチセンサ(MPR121)](sensors/GroveI2cTouch.md)|12(最大)|✕|I2C|◯|
|[Grove - Touch Sensor](sensors/DigitalTouchSensor.md)|1|✕|デジタル✕1|◯|
|[Grove - PIR Motion Sensor](sensors/PIR_Sensor.md)|✕|◯|デジタル✕1|◯|
|[Grove - GSR Sensor](sensors/Grove_GSR.md)|体(手)の湿り気(汗)|✕|アナログ✕1|◯|

### Groveコネクタ列
- ◯ Grove用のケーブルで直接接続可能
- △ 変換ケーブルで接続する必要がある
- ✕ ジャンパケーブルで配線する必要がある

## 5. 視覚関連

|センサ名|照度|色彩|インターフェース|Groveコネクタ|
|---|---|---|---|---|
|[TCS34725](sensors/TCS34725.md)|✕|◯|I2C|△|
|[TSL2561](sensors/TSL2561.md)|◯|✕|I2C|△|
|[Grove - Light Sensor](sensors/Grove_Analog_Light.md)|光の強弱(照度ではない)|✕|アナログ✕1|◯|
|[TEMT6000](sensors/TEMT6000.md)|◯|✕|アナログ✕1|△|

### Groveコネクタ列
- ◯ Grove用のケーブルで直接接続可能
- △ 変換ケーブルで接続する必要がある
- ✕ ジャンパケーブルで配線する必要がある


## 6. その他

|センサ名|観測/測定対象|インターフェース|Groveコネクタ|
|---|---|---|---|
|[Grove - Switch](sensors/DigitalSwitch.md)|物理的な切り替え(スイッチ等)|デジタル✕1|◯|
|[Grove - Water Sensor](sensors/Grove_Water.md)|水の検知(端子間の短絡)|デジタル✕1|◯|
|[Grove - Line Finder](sensors/GroveLineFinder.md)|黒色の検出(赤外線反射)|デジタル✕1|◯|
|[Grove IR Distance Interrupter](sensors/Grove_IR_Distance_Interrupter.md)|物体検出(赤外線反射)|デジタル✕1|◯|
|[Grove - Infrared Reflective Sensor](sensors/Grove_IR_Refrective_Sensor.md)|物体検出(赤外線反射)|デジタル✕1|◯|
|[Grove - Rotary Angle Sensor](sensors/Rotary_Angle.md)|回転角度|アナログ✕1|◯|
|[Grove - Sound Sensor](sensors/Grove_Analog_Sound.md)|音の大小(デジタル値ではない)|アナログ✕1|◯|
|[Grove水分センサ](sensors/Grove_Moisture.md)|土の湿り気|アナログ✕1|◯|
|[Grove電流センサ](sensors/Grove_Current.md)|電流の強弱(正確な値ではない)|アナログ✕1|◯|

### Groveコネクタ列
- ◯ Grove用のケーブルで直接接続可能
- △ 変換ケーブルで接続する必要がある
- ✕ ジャンパケーブルで配線する必要がある


## 7. 特殊な接続のセンサ : Arduino MKR ENV Shield

[Arduino MKR ENV Shield](https://store-usa.arduino.cc/products/arduino-mkr-env-shield-rev2)は以下のセンサが搭載されたMKRファミリ用シールドである．

- 気圧センサ [LPS22HB](sensors/LPS22HB.md)
- 温湿度センサ [HTS221](sensors/HTS221.md)
- 照度センサ [TEMT6000](sensors/TEMT6000.md)

MKRファミリのArduinoにおいて，
[Arduino MKR ENV Shield](https://store-usa.arduino.cc/products/arduino-mkr-env-shield-rev2)と
[Arduino MKR Connector Carrier](https://store-usa.arduino.cc/products/arduino-mkr-connector-carrier-grove-compatible)を同時に使う場合，
LEDを接続する端子(D5D6端子)がシールドで占領されている(詳細は下の表)ため，LEDはジャンパケーブル等で接続する形式に変更した上で，
LEDを接続するピンを考える必要がある．

|Groveコネクタ番号|MKR ENV Shield|備考|
|---|---|---|
|D0|||
|D1|||
|D2|||
|D3|||
|D4|✕|SDのチップセレクト端子|
|D5D6|△|D6がセンサで使われている|
|A0|||
|A1|||
|A2|✕|TEMT6000の端子|
|A3|||
|A4|||
|A5A6||[Arduino MKR Connector Carrier](https://store-usa.arduino.cc/products/arduino-mkr-connector-carrier-grove-compatible)の配線の都合上，用途が限定される|

Grove端子抜きにした場合，[Arduino MKR ENV Shield](https://store-usa.arduino.cc/products/arduino-mkr-env-shield-rev2)で使用済みのピン番号以下の通り．

|インターフェース種別|番号|
|---|---|
|アナログ|2|
|デジタル|4,6,7,8,9,10,11,12|

なお，デジタル端子の13,14はArduinoのシリアルになっているため，実質的に利用できるピンA2以外のアナログ端子と0,1,2,3,5番の
デジタル端子となる．

この中から2つの信号端子を選択し，変換ケーブル等で接続する必要がある．

## 8. センサを繋ぐGroveコネクタの選択
本プロジェクトで利用可能なセンサのうち，「[ADXL335](sensors/ADXL335.md)」以外は1つのGroveコネクタに接続可能である．
インターフェースとしてI2Cのものは，複数の機器が1つのコネクタに繋がっていても大丈夫であるため，ピン番号(コネクタ番号)は気にする必要がない．
また，利用する装置では，I2C用に分岐HUBを使うことで，端子数不足は回避できる．

それに対して，デジタルもしくはアナログインターフェースを持つセンサは1つの端子に1つのセンサ(もしくは周辺機器)しか接続できないため，
センサを接続するベースのシステムで既に利用されている端子がどれであるかを意識する必要がある．

典型的なベースのシステム毎に，センサが接続可能なGroveのコネクタがどれであるかを下の表に示す．
この表を各センサを接続する端子の選択と，設定の際の参考にすること．

|Groveコネクタ番号|MKR Zero+Ethernet|MKR WiFi 1010|Uno R4 Minima + Ether|Uno R4 WiFi|Nano 33 IoT|
|---|---|---|---|---|---|
|D0|◯|◯|－|－|－|
|D1|◯|◯|－|－|－|
|D2|◯|◯|◯|◯|◯|
|D3|◯|◯|◯|◯|－|
|D4|✕|✕|✕|✕|✕|
|D5D6|✕|✕|－|－|－|
|D5|－|－|◯|◯|－|
|D6|－|－|✕|✕|◯|
|D7|－|－|✕|✕|－|
|D8|－|－|◯|◯|－|
|A0|◯|◯|◯|◯|◯|
|A1|◯|◯|◯|◯|－|
|A2|◯|◯|◯|◯|◯|
|A3|◯|◯|◯|◯|－|
|A4|◯|◯|－|－|－|
|A5A6|◯|◯|－|－|－|
|A6|－|－|－|－|◯|

- 「◯」 利用可能なコネクタ番号
- 「✕」 利用不可(既に利用済み)のコネクタ番号
- 「－」 存在しないコネクタ番号

表だけでは理解が難しいかもしれないため，以下に図で示す．

### 8.1. MKR Zero + MKR Ethernetシールド

センサ等を後に追加する場合に，I2C以外は既に使われている場所は利用できない．
Groveのコネクタのうち，D4,D5,D6とI2Cは既に使われている．
それを以下に示す．


<div style="text-align: center;">
<img src="../images/MKR_Zero_Grove_コネクタ.png" width="70%">
</div>


### 8.2. MKR WiFi1010 + マイクロSDシールド

センサ等を後に追加する場合に，I2C以外は既に使われている場所は利用できない．
それを以下に示す．

<div style="text-align: center;">
<img src="../images/MKR_WiFi1010_Grove_コネクタ.png" width="70%">
</div>



### 8.3. Arduino Uno R4 Minima + Ethernetシールド

センサ等を後に追加する場合に，I2C以外は既に使われている場所は利用できない．

I2Cコネクタ4つのうちの1つとLEDで6番7番端子を使っているため，下のバツ印のところは利用不可である．

<div style="text-align: center;">
<img src="../images/Minima_Grove_コネクタ.png" width="70%">
</div>



### 8.4. Arduino Uno R4 WiFi + マイクロSDシールド

センサ等を後に追加する場合に，I2C以外は既に使われている場所は利用できない．

I2Cコネクタ4つのうちの1つとLEDで6番7番端子を使っているため，下のバツ印のところは利用不可である．

<div style="text-align: center;">
<img src="../images/Minima_Grove_コネクタ.png" width="70%">
</div>


### 8.5. Arduino Nano 33 IoT

センサ等を後に追加する場合に，I2C以外は既に使われている場所は利用できない．

I2CコネクタとLEDで6番7番端子を使っている．また，SPIで4つのピンを使っているが，対応するGroveコネクタが存在しないため，SPIは気にしなくて良い．

以上から，Groveシールドのうち，下図のバツ印のところは利用不可である．

<div style="text-align: center;">
<img src="../images/Nano_Grove_コネクタ.png" width="70%">
</div>






***
- [マニュアルトップに戻る](../Manual.md)


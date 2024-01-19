# 基本システム組み立て
動作の確認が取れているArduinoの機種を使った推奨の構成を組み立てる方法を説明する．
なお，マイクロSD, LEDとRTCは用途によっては不要であるが，ここでは使うものとする．また，RTCはDS3231を例にとって説明する．

## MKR Zero + MKR Ethernetシールド

### パーツリスト
- Arduino MKR ZERO
![Arduino MKR ZERO](../images/MKR_Zero.png)
https://store-usa.arduino.cc/products/arduino-mkr-zero-i2s-bus-sd-for-sound-music-digital-audio-data

- Arduino MKR ETH Shield
![Arduino MKR ETH Shield](../images/MKR_Ethernet.png)
https://store-usa.arduino.cc/products/arduino-mkr-eth-shield

- Arduino MKR Connector Carrier
![Arduino MKR Connector Carrier](../images/MKR_Grove_Shield.png)
https://store-usa.arduino.cc/products/arduino-mkr-connector-carrier-grove-compatible

- マイクロSDメディア

- Grove – Chainable RGB LED
![Grove – Chainable RGB LED](../images/Grove_Chainable_RGB_LED.jpg)
https://www.seeedstudio.com/Grove-Chainable-RGB-Led-V2-0.html

- Grove - 4 pin Male Jumper
![Grove - 4 pin Male Jumper](../images/Grove_4pin_Male_Jumper.jpg)
https://www.seeedstudio.com/Grove-4-pin-Male-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-Pack.html

- Adafruit DS3231 Precision RTC Breakout
![Adafruit DS3231](../images/Adafruit_DS3231.jpg)
https://www.adafruit.com/product/3013

- Grove - 4 pin Female Jumper to Grove 4 pin Conversion Cable
![Grove - 4 pin Female Jumper](../images/Grove_4pin_Female_Jumper.jpg)
https://www.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html

- Grove - I2C Hub
![Grove - I2C Hub](../images/Grove_I2C_Hub.jpg)
https://www.seeedstudio.com/Grove-I2C-Hub.html


### 組み立て

本体とGrove対応基板，イーサネットシールドを下図のように組み立てる．この時，青い大きな端子(ターミナルブロック)とはUSBやイーサネットのコネクタが反対になるように組み上げる．

さらに，マイクロSDは本体側のスロットに挿入する．イーサネットシールドにもマイクロSDのスロットは存在するが，本体側が優先されるため，イーサネットシールド側にマイクロSDを挿入しても，認識されない．

![MKR_Zero_Base](../images/MKR_Zero_Base.jpg)


LEDはデジタル端子2つが1つのGroveコネクタに配線されている必要があるため，下図の「A5A6」もしくは「D5D6」コネクタのどちらかに接続する必要がある．
また，Arduinoの仕様上アナログ端子はデジタル端子として利用可能なため，「A5A6」への接続を想定してしまうが，Arduino MKR Connector Carrierの
回路の配線の都合上，アナログ端子をデジタル端子として利用できない．


![MKR_Grove_Shield](../images/MKR_Grove_Shield.png)

そのため，この[ケーブル](https://www.seeedstudio.com/Grove-4-pin-Male-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-Pack.html)を使って
配線する必要があるが，Groveのコネクタへの配線，I2CやSPIのピン配置を考えると，「D6,D7」に接続するのが望ましい．
「D6」に白ケーブル,「D7」に黄色ケーブル,「GND」に黒ケーブル「VCC」に赤ケーブルを接続する．


![MKR_Zero+LED](../images/MKR_Zero+LED.jpg)


RTCはI2C接続であるため，下図の「TWI」端子に接続する必要がある．

![MKR_Grove_Shield](../images/MKR_Grove_Shield.png)

ただし，コネクタが1つしか存在しないため，I2Cのセンサ等を後に接続する可能性があるため，I2C HUBを基板のTWIに接続し，I2C HUBにRTCを繋ぐ．


![MKR_ZERO+LED+RTC](../images/MKR_ZERO+LED+RTC.jpg)

RTC(DS3231)の配線は，VIN端子に赤色，GND端子に黒色，SCL端子に黄色，SDA端子に白色端子を接続する．
![DS3231](../images/DS3231.JPG)



## MKR WiFi1010 + マイクロSDシールド

### パーツリスト
- Arduino MKR WiFi 1010

![Arduino MKR WiFi 1010](../images/MKR_WiFi1010.png)

https://store-usa.arduino.cc/products/arduino-mkr-wifi-1010

- Arduino MKR Connector Carrier
![Arduino MKR Connector Carrier](../images/MKR_Grove_Shield.png)
https://store-usa.arduino.cc/products/arduino-mkr-connector-carrier-grove-compatible


- マイクロSDメディア

- MKR SD Proto Shield
![MKR SD Proto Shield](../images/MKR_SD.png)
https://store-usa.arduino.cc/products/mkr-sd-proto-shield

- Grove – Chainable RGB LED

![Grove – Chainable RGB LED](../images/Grove_Chainable_RGB_LED.jpg)
https://www.seeedstudio.com/Grove-Chainable-RGB-Led-V2-0.html


- Adafruit DS3231 Precision RTC Breakout
![Adafruit DS3231](../images/Adafruit_DS3231.jpg)
https://www.adafruit.com/product/3013


- Grove - 4 pin Female Jumper to Grove 4 pin Conversion Cable
![Grove - 4 pin Female Jumper](../images/Grove_4pin_Female_Jumper.jpg)
https://www.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html

- Grove - I2C Hub
![Grove - I2C Hub](../images/Grove_I2C_Hub.jpg)
https://www.seeedstudio.com/Grove-I2C-Hub.html



### 組み立て

本体とGrove対応基板，イーサネットシールドを下図のように組み立てる．この時，青い大きな端子(ターミナルブロック)とはUSBやイーサネットのコネクタが反対になるように組み上げる．

さらに，マイクロSDは本体側のスロットに挿入する．イーサネットシールドにもマイクロSDのスロットは存在するが，本体側が優先されるため，イーサネットシールド側にマイクロSDを挿入しても，認識されない．

![MKR_WiFi1010_Base](../images/MKR_WiFi1010_Base.png)


Arduinoのアナログ端子はデジタル端子としても利用できるが，
Arduino MKR Connector Carrierのアナログ端子の配線の関係で，「A5A6」コネクタをデジタル端子として利用することが
できないため，D5D6端子に接続する必要がある．

![MKR_Grove_Shield](../images/MKR_Grove_Shield.png)


RTCはI2C接続であるため，下図の「TWI」端子に接続する必要がある．

![MKR_Grove_Shield](../images/MKR_Grove_Shield.png)

ただし，コネクタが1つしか存在しないため，I2Cのセンサ等を後に接続する可能性があるため，I2C HUBを基板のTWIに接続し，I2C HUBにRTCを繋ぐ．


![MKR_WiFi1010+LED+RTC](../images/MKR_WiFi1010+LED+RTC.jpg)

RTC(DS3231)の配線は，VIN端子に赤色，GND端子に黒色，SCL端子に黄色，SDA端子に白色端子を接続する．
![DS3231](../images/DS3231.JPG)




## Arduino Uno R4 Minima + Ethernetシールド

### パーツリスト
- Arduino® UNO R4 Minima
![Arduino® UNO R4 Minima](../images/Uno_R4.png)
https://store-usa.arduino.cc/products/uno-r4-minima


- Arduino Ethernet Shield 2
![Arduino Ethernet Shield 2](../images/Classic_Ethernet.png)
https://store-usa.arduino.cc/products/arduino-ethernet-shield-2

- Arduino用 Groveベースシールド
![Arduino用 Groveベースシールド](../images/Groveシールド.jpg)
https://jp.seeedstudio.com/Base-Shield-V2.html


- マイクロSDメディア

- Grove – Chainable RGB LED
![Grove – Chainable RGB LED](../images/Grove_Chainable_RGB_LED.jpg)
https://www.seeedstudio.com/Grove-Chainable-RGB-Led-V2-0.html

- Adafruit DS3231 Precision RTC Breakout
![Adafruit DS3231](../images/Adafruit_DS3231.jpg)
https://www.adafruit.com/product/3013


- Grove - 4 pin Female Jumper to Grove 4 pin Conversion Cable
![Grove - 4 pin Female Jumper](../images/Grove_4pin_Female_Jumper.jpg)
https://www.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html



### 組み立て

イーサネットシールドの背が高いため，積み重ねる際には，本体，Groveシールド，イーサネットシールドの順で重ねる必要がある．

そのため，本体とシールドを重ねてしまうと，Groveを使った周辺回路の組み立てができなくなるため，先に，周辺回路を組み立てる．


イーサネットシールドに，マイクロSDを挿入する．

![イーサネットシールド+マイクロSD](../images/Ethernet_Shield+micro_SD.jpg)


GroveシールドのI2CコネクタにRTCを，デジタル端子にLEDを接続するが，後で接続するモジュール(回路)が増える可能性もあるので，シール基板の中央付近のコネクタを選択している．下図では，LEDはGrove D2コネクタ(D2端子とD3端子の2個組)を利用している

![Groveシールド+rtc+LED](../images/Grove_Shield+LED+RTC.jpg)

最後に，本体と重ねて組み上げれば終了である．

![Uno R4 Base system](../images/UNO+Shield+RTC+LED.jpg)


RTC(DS3231)の配線は，VIN端子に赤色，GND端子に黒色，SCL端子に黄色，SDA端子に白色端子を接続する．
![DS3231](../images/DS3231.JPG)


## Arduino Uno R4 WiFi + マイクロSDシールド
### パーツリスト
- Arduino® UNO R4 WiFi
![Arduino® UNO R4 WiFi](../images/Uno_R4_WiFi.png)
https://store-usa.arduino.cc/products/uno-r4-wifi


- Arduino用 Groveベースシールド

![Arduino用 Groveベースシールド](../images/Groveシールド.jpg)
https://jp.seeedstudio.com/Base-Shield-V2.html


- SD Card Shield
https://www.seeedstudio.com/SD-Card-Shield-V4-p-1381.html

- SparkFun microSD Shield
https://www.sparkfun.com/products/12761

- マイクロSDメディア

- Grove – Chainable RGB LED
![Grove – Chainable RGB LED](../images/Grove_Chainable_RGB_LED.jpg)
https://www.seeedstudio.com/Grove-Chainable-RGB-Led-V2-0.html

- Adafruit DS3231 Precision RTC Breakout
![Adafruit DS3231](../images/Adafruit_DS3231.jpg)
https://www.adafruit.com/product/3013


- Grove - 4 pin Female Jumper to Grove 4 pin Conversion Cable
![Grove - 4 pin Female Jumper](../images/Grove_4pin_Female_Jumper.jpg)
https://www.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html

### 組み立て

下の手順は，[SDシールド](https://www.seeedstudio.com/SD-Card-Shield-V4-p-1381.html)ではなく，[マイクロSDシールド](https://www.sparkfun.com/products/12761)を
用いたものであるが，手順は同じである．

まずはじめに，マイクロSDのシールドにメディアを挿しておく．
![Sparcfun_sd_shield](../images/Sparcfun_sd_shield.JPG)

マイクロSDのシールドは基板面に触ることがないので，本体とGroveのシールドで挟む形で組み立てる．
![Uno_R4_WiFi_Base](../images/Uno_R4_WiFi_Base.JPG)

RTC(DS3231)の配線は，VIN端子に赤色，GND端子に黒色，SCL端子に黄色，SDA端子に白色端子を接続する．
![DS3231](../images/DS3231.JPG)

最後に，RTCをGroveのI2C端子のいずれかに，また，LEDはGroveのD6コネクタ(D6ピンとD7ピンを使うもの)に挿す．

![Uno_R4_WiFi_Base_all](../images/Uno_R4_WiFi_Base_all.JPG)

## Arduino Nano 33 IoT
### パーツリスト
Arduino Nano 33 IoT
![Nano_33_IoT](../images/Nano_33_IoT.png)
https://store-usa.arduino.cc/products/arduino-nano-33-iot

Grove Shield for Arduino Nano
![Grove_nano_shield](../images/Grove_nano_shield.jpg)
https://www.seeedstudio.com/Grove-Shield-for-Arduino-Nano-p-4112.html

ピンソケット
![ピンソケット](../images/ピンソケット.jpg)
https://akizukidenshi.com/catalog/g/gC-10102/

マイクロSDモジュール
![マイクロSDモジュール](../images/マイクロSDモジュール.jpg)
https://www.adafruit.com/product/254


- ジャンパーワイヤ
|ケーブル色|販売元URL|
|---|---|
| 黒 | https://akizukidenshi.com/catalog/g/gC-08932/ |
| 赤 | https://akizukidenshi.com/catalog/g/gC-08933/ |
| 黄 | https://akizukidenshi.com/catalog/g/gC-08936/ |
| 青 | https://akizukidenshi.com/catalog/g/gC-08934/ |
| 白 | https://akizukidenshi.com/catalog/g/gC-08935/ |

![ジャンパーケーブル黒](../images/ジャンパーケーブル黒.jpg)


- マイクロSDメディア


- Grove – Chainable RGB LED
![Grove – Chainable RGB LED](../images/Grove_Chainable_RGB_LED.jpg)
https://www.seeedstudio.com/Grove-Chainable-RGB-Led-V2-0.html

- Adafruit DS3231 Precision RTC Breakout
![Adafruit DS3231](../images/Adafruit_DS3231.jpg)
https://www.adafruit.com/product/3013


- Grove - 4 pin Female Jumper to Grove 4 pin Conversion Cable
![Grove - 4 pin Female Jumper](../images/Grove_4pin_Female_Jumper.jpg)
https://www.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html


- Grove - I2C Hub
![Grove - I2C Hub](../images/Grove_I2C_Hub.jpg)
https://www.seeedstudio.com/Grove-I2C-Hub.html


### 組み立て


Arduino Nano 33 IoTの各ピンがどのような機能の端子に対応しているかを示す図が公式サイトの
[ここ](https://content.arduino.cc/assets/Pinout-NANO33IoT_latest.pdf)に記載されている．

上の図の中で，SPIに関係する端子は下図の赤点線で囲まれている端子(D11, D12, D13)となる．
![Nano_33_IoT_SPI](../images/Nano_33_IoT_SPI.png)

また，マイクロSDモジュールのピンは以下の図の通り．
![マイクロSDモジュール_Pin](../images/マイクロSDモジュール_Pin.jpg)

マイクロSDはSPI接続となるため，[マイクロSDモジュール](https://www.adafruit.com/product/254)の各端子とNano 33 IoTとの
ピンの対応関係は以下の表のようになる．

|SPI|Groveシールド端子|マイクロSDモジュール|
|---|---|---|
|電源|3V3|3V|
|GND|GND|GND|
|SCK(クロック)|D13|CLK|
|MISO|D12|DO|
|MOSI|D11|DI|
|チップセレクト|D10|CS|

チップセレクトは特に縛りは無いが，Arduinoの従来のシールドでチップセレクトとして良く使われる端子である上，Nano用Groveシールドで
Grove用のコネクタに割り当てられていないため，これを用いるのが望ましい．

また，Nano用Groveシールドにピンをはんだ付けし，Nanoを挿入すると端子番号はほぼ読めなくなるため，下に拡大図を示す．
![Nano_Grove_SPI](../images/Nano_Grove_SPI.png)

実際に配線すると以下のようになる．

![マイクロSDの接続](../images/Nano33_IoT+SD.png)

次に，LEDとRTC等のI2C機器の接続であるが，LEDは特に規制は無いが，既に使われている比率が高い数字の大きい方から選択し，D6コネクタ(D6とD7端子)とし，
I2Cは該当のコネクタがGroveシールド上にあるため，それを使う．

![Nano_Grove_LED等](../images/Nano_Grove_LED等.png)


また，RTC(DS3231)の配線は，VIN端子に赤色，GND端子に黒色，SCL端子に黄色，SDA端子に白色端子を接続する．
![DS3231](../images/DS3231.JPG)

全て配線すると以下の図のようになる．

![Nano33_IoT+周辺機器](../images/Nano33_IoT+SD+LED+RTC.png)


<!-- コメントアウトしたい内容 -->
<!-- 

## Arduino Nano ESP32

### パーツリスト

Arduino Nano ESP32
![Arduino_Nano_ESP32](../images/Arduino_Nano_ESP32.png)

https://store-usa.arduino.cc/products/nano-esp32


Grove Shield for Arduino Nano
![Grove_nano_shield](../images/Grove_nano_shield.jpg)
https://www.seeedstudio.com/Grove-Shield-for-Arduino-Nano-p-4112.html

ピンソケット
![ピンソケット](../images/ピンソケット.jpg)
https://akizukidenshi.com/catalog/g/gC-10102/

マイクロSDモジュール
![マイクロSDモジュール](../images/マイクロSDモジュール.jpg)
https://www.adafruit.com/product/254


- ジャンパーワイヤ
|ケーブル色|販売元URL|
|---|---|
| 黒 | https://akizukidenshi.com/catalog/g/gC-08932/ |
| 赤 | https://akizukidenshi.com/catalog/g/gC-08933/ |
| 黄 | https://akizukidenshi.com/catalog/g/gC-08936/ |
| 青 | https://akizukidenshi.com/catalog/g/gC-08934/ |
| 白 | https://akizukidenshi.com/catalog/g/gC-08935/ |

![ジャンパーケーブル黒](../images/ジャンパーケーブル黒.jpg)


- マイクロSDメディア


- Grove – Chainable RGB LED
![Grove – Chainable RGB LED](../images/Grove_Chainable_RGB_LED.jpg)
https://www.seeedstudio.com/Grove-Chainable-RGB-Led-V2-0.html

- Adafruit DS3231 Precision RTC Breakout
![Adafruit DS3231](../images/Adafruit_DS3231.jpg)
https://www.adafruit.com/product/3013


- Grove - 4 pin Female Jumper to Grove 4 pin Conversion Cable
![Grove - 4 pin Female Jumper](../images/Grove_4pin_Female_Jumper.jpg)
https://www.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html


- Grove - I2C Hub
![Grove - I2C Hub](../images/Grove_I2C_Hub.jpg)
https://www.seeedstudio.com/Grove-I2C-Hub.html

-->

***

- [マニュアルトップに戻る](../Manual.md)


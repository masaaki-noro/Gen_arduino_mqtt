# Arduinoの機種別のパーツリスト
ここでは，動作確認済みのArduino(推奨品)機種別に用意すべき部品等のリストを紹介する．


## 1. MKR Zero + MKR Ethernetシールド

- [Arduino MKR ZERO](https://store-usa.arduino.cc/products/arduino-mkr-zero-i2s-bus-sd-for-sound-music-digital-audio-data)

<div style="text-align: center;">
<img src="../images/MKR_Zero.png" width="50%">
</div>




- [Arduino MKR ETH Shield](https://store-usa.arduino.cc/products/arduino-mkr-eth-shield)

<div style="text-align: center;">
<img src="../images/MKR_Ethernet.png" width="53%">
</div>






- [Arduino MKR Connector Carrier](https://store-usa.arduino.cc/products/arduino-mkr-connector-carrier-grove-compatible)

<div style="text-align: center;">
<img src="../images/MKR_Grove_Shield.png" width="70%">
</div>





マイクロSD, LEDとRTCは用途によっては不要であるが，ここでは使うものとする．また，RTCは推奨品のDS3231を利用することとする．

- マイクロSDのメディア : 好きなものを購入すれば良い(ただし，16GB以下)．

- [Grove – Chainable RGB LED](https://www.seeedstudio.com/Grove-Chainable-RGB-Led-V2-0.html)

<div style="text-align: center;">
<img src="../images/Grove_Chainable_RGB_LED.jpg" width="30%">
</div>



- [Grove - 4 pin Male Jumper](https://www.seeedstudio.com/Grove-4-pin-Male-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-Pack.html)

<div style="text-align: center;">
<img src="../images/Grove_4pin_Male_Jumper.jpg" width="70%">
</div>




- [Adafruit DS3231 Precision RTC Breakout](https://www.adafruit.com/product/3013)

<div style="text-align: center;">
<img src="../images/Adafruit_DS3231.jpg" width="40%">
</div>



RTCにはピンヘッダが添付されているが，直線上のものが添付されているため，これを利用すると基板に印字されている端子の名称が読めなく
なるため，下のようなL型のピンヘッダを使うことを勧める．
- [ピンヘッダ　（オスＬ型）](https://akizukidenshi.com/catalog/g/gC-01627/)


- [Grove - 4 pin Female Jumper to Grove 4 pin Conversion Cable](https://www.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html)

<div style="text-align: center;">
<img src="../images/Grove_4pin_Female_Jumper.jpg" width="40%">
</div>



RTCに加えて，I2Cインターフェースを使うセンサを使う場合や，RTC無しでI2Cインターフェースを持つセンサを複数接続する場合のみ以下の物品は必要になるが，
センサとして，何を使うか明確で無い場合は用意しておく方が望ましい．

- [Grove - I2C Hub](https://www.seeedstudio.com/Grove-I2C-Hub.html)

<div style="text-align: center;">
<img src="../images/Grove_I2C_Hub.jpg" width="30%">
</div>



### イーサネットシールドのMACアドレス割当てとシールの貼り付け

PCやWiFi基地局，ルータ等はMACアドレスは機器に内蔵されたROMに記入されており，
プログラム上で記述する必要はないが，ArduinoはMACアドレスを持たないため，別途指定する必要がある．

Arduinoのイーサネットシールドのうち，Classicシリーズのシールドには，Arduinoの製造元が取得したMACアドレスが
記載されたシールが貼られているため，そのアドレスを利用すれば良い．一方，MKRのイーサネットシールドには
MACアドレスのシールがないため，自分でMACアドレスを決めて，そのアドレスを記入する必要がある．

イーサネットの国際規格では，ネットワーク機器の製造メーカーがルールに従って，1台に1つアドレスを自分のアドレスの在庫から割当て，
世界に1つのアドレスを発行することになっている．しかし，近年の仮想化技術の進展で，物理的な物が無いにもかかわらず，
MACアドレスを大量に使うシーンが増えたため，MACアドレス空間の中から，自由に使って良いアドレスを各自が適当に使う状況に
なっている．

自由に使って良いMACアドレス空間を利用し，MACアドレスを自動で生成するWebサービス([ここ](https://miniwebtool.com/ja/mac-address-generator/)とか[ここ](https://www.bungu-do.jp/tools/mac_address))も登場しており，
これを利用することで，MACアドレスの問題が発生する確率を非常に低く保ちながらも，勝手に発行したMACアドレスを使うことが可能になっている．

ここでは，MKRのイーサネットシールドを使うため，上記サービスを使って，MACアドレスを生成した上で，シールに記入して貼り付けておく．


<div style="text-align: center;">
<img src="../images/MACアドレスシールMKR.jpg" width="50%">
</div>



## 2. MKR WiFi1010 + マイクロSDシールド

- [Arduino MKR WiFi 1010](https://store-usa.arduino.cc/products/arduino-mkr-wifi-1010)

<div style="text-align: center;">
<img src="../images/MKR_WiFi1010.png" width="50%">
</div>



- [Arduino MKR Connector Carrier](https://store-usa.arduino.cc/products/arduino-mkr-connector-carrier-grove-compatible)

<div style="text-align: center;">
<img src="../images/MKR_Grove_Shield.png" width="70%">
</div>


マイクロSD, LEDとRTCは用途によっては不要であるが，ここでは使うものとする．また，RTCは推奨品のDS3231を利用することとする．

- マイクロSDのメディア : 好きなものを購入すれば良い(ただし，16GB以下)．

- [MKR SD Proto Shield](https://store-usa.arduino.cc/products/mkr-sd-proto-shield)

<div style="text-align: center;">
<img src="../images/MKR_SD.png" width="50%">
</div>


- [Grove – Chainable RGB LED](https://www.seeedstudio.com/Grove-Chainable-RGB-Led-V2-0.html)

<div style="text-align: center;">
<img src="../images/Grove_Chainable_RGB_LED.jpg" width="30%">
</div>



- [Adafruit DS3231 Precision RTC Breakout](https://www.adafruit.com/product/3013)

<div style="text-align: center;">
<img src="../images/Adafruit_DS3231.jpg" width="40%">
</div>




RTCにはピンヘッダが添付されているが，直線上のものが添付されているため，これを利用すると基板に印字されている端子の名称が読めなく
なるため，下のようなL型のピンヘッダを使うことを勧める．
- [ピンヘッダ　（オスＬ型）](https://akizukidenshi.com/catalog/g/gC-01627/)


- [Grove - 4 pin Female Jumper to Grove 4 pin Conversion Cable](https://www.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html)

<div style="text-align: center;">
<img src="../images/Grove_4pin_Female_Jumper.jpg" width="50%">
</div>





RTCに加えて，I2Cインターフェースを使うセンサを使う場合や，RTC無しでI2Cインターフェースを持つセンサを複数接続する場合のみ以下の物品は必要になるが，
センサとして，何を使うか明確で無い場合は用意しておく方が望ましい．

- [Grove - I2C Hub](https://www.seeedstudio.com/Grove-I2C-Hub.html)


<div style="text-align: center;">
<img src="../images/Grove_I2C_Hub.jpg" width="30%">
</div>





## 3. Arduino Uno R4 Minima + Ethernetシールド

- [Arduino UNO R4 Minima](https://store-usa.arduino.cc/products/uno-r4-minima)

<div style="text-align: center;">
<img src="../images/Uno_R4.png" width="50%">
</div>






- [Arduino Ethernet Shield 2](https://store-usa.arduino.cc/products/arduino-ethernet-shield-2)

<div style="text-align: center;">
<img src="../images/Classic_Ethernet.png" width="50%">
</div>





- [Arduino用 Groveベースシールド](https://jp.seeedstudio.com/Base-Shield-V2.html)

<div style="text-align: center;">
<img src="../images/Groveシールド.jpg" width="70%">
</div>





マイクロSD, LEDとRTCは用途によっては不要であるが，ここでは使うものとする．また，RTCは推奨品のDS3231を利用することとする．


- マイクロSDのメディア : 好きなものを購入すれば良い(ただし，16GB以下)．

- [Grove – Chainable RGB LED](https://www.seeedstudio.com/Grove-Chainable-RGB-Led-V2-0.html)

<div style="text-align: center;">
<img src="../images/Grove_Chainable_RGB_LED.jpg" width="30%">
</div>






- [Adafruit DS3231 Precision RTC Breakout](https://www.adafruit.com/product/3013)

<div style="text-align: center;">
<img src="../images/Adafruit_DS3231.jpg" width="40%">
</div>





RTCにはピンヘッダが添付されているが，直線上のものが添付されているため，これを利用すると基板に印字されている端子の名称が読めなく
なるため，下のようなL型のピンヘッダを使うことを勧める．
- [ピンヘッダ　（オスＬ型）](https://akizukidenshi.com/catalog/g/gC-01627/)


- [Grove - 4 pin Female Jumper to Grove 4 pin Conversion Cable](https://www.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html)

<div style="text-align: center;">
<img src="../images/Grove_4pin_Female_Jumper.jpg" width="50%">
</div>






## 4. Arduino Uno R4 WiFi + マイクロSDシールド

- [Arduino UNO R4 WiFi](https://store-usa.arduino.cc/products/uno-r4-wifi)

<div style="text-align: center;">
<img src="../images/Uno_R4_WiFi.png" width="50%">
</div>



- [Arduino用 Groveベースシールド](https://jp.seeedstudio.com/Base-Shield-V2.html)

<div style="text-align: center;">
<img src="../images/Groveシールド.jpg" width="70%">
</div>




- [SD Card Shield](https://www.seeedstudio.com/SD-Card-Shield-V4-p-1381.html)


- [SparkFun microSD Shield](https://www.sparkfun.com/products/12761)


- ピンヘッダ : [Adafruit](https://www.adafruit.com/product/85),  [秋月電子1](https://akizukidenshi.com/catalog/g/gC-17103/), [秋月電子2](https://akizukidenshi.com/catalog/g/gC-17102/)

ピンヘッダはAdafruit物を購入すれば，端子的には足りるものの，ピンに印刷してあったほうが便利なので，2x3ピンのものと秋月で売られているものの
組み合わせが便利．

- マイクロSDのメディア : 好きなものを購入すれば良い(ただし，16GB以下)．


- [Grove – Chainable RGB LED](https://www.seeedstudio.com/Grove-Chainable-RGB-Led-V2-0.html)

<div style="text-align: center;">
<img src="../images/Grove_Chainable_RGB_LED.jpg" width="30%">
</div>




- [Adafruit DS3231 Precision RTC Breakout](https://www.adafruit.com/product/3013)

<div style="text-align: center;">
<img src="../images/Adafruit_DS3231.jpg" width="40%">
</div>




RTCにはピンヘッダが添付されているが，直線上のものが添付されているため，これを利用すると基板に印字されている端子の名称が読めなく
なるため，下のようなL型のピンヘッダを使うことを勧める．
- [ピンヘッダ　（オスＬ型）](https://akizukidenshi.com/catalog/g/gC-01627/)

- [Grove - 4 pin Female Jumper to Grove 4 pin Conversion Cable](https://www.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html)

<div style="text-align: center;">
<img src="../images/Grove_4pin_Female_Jumper.jpg" width="50%">
</div>




## 5. Arduino Nano 33 IoT

- [Arduino Nano 33 IoT](https://store-usa.arduino.cc/products/arduino-nano-33-iot)

<div style="text-align: center;">
<img src="../images/Nano_33_IoT.png" width="50%">
</div>





- [Grove Shield for Arduino Nano](https://www.seeedstudio.com/Grove-Shield-for-Arduino-Nano-p-4112.html)

<div style="text-align: center;">
<img src="../images/Grove_nano_shield.jpg" width="70%">
</div>




- [ピンソケット](https://akizukidenshi.com/catalog/g/gC-10102/)

<div style="text-align: center;">
<img src="../images/ピンソケット.jpg" width="30%">
</div>





- [マイクロSDモジュール](https://www.adafruit.com/product/254)

<div style="text-align: center;">
<img src="../images/マイクロSDモジュール.jpg" width="40%">
</div>



上記モジュールにはピンヘッダが添付されているが，直線上のものが添付されているため，これを利用すると基板に印字されている端子の名称が読めなく
なるため，下のようなL型のピンヘッダを使うことを勧める．
- [ピンヘッダ　（オスＬ型）](https://akizukidenshi.com/catalog/g/gC-01627/)


- ジャンパーワイヤ
|ケーブル色|販売元URL|
|---|---|
| 黒 | https://akizukidenshi.com/catalog/g/gC-08932/ |
| 赤 | https://akizukidenshi.com/catalog/g/gC-08933/ |
| 黄 | https://akizukidenshi.com/catalog/g/gC-08936/ |
| 青 | https://akizukidenshi.com/catalog/g/gC-08934/ |
| 白 | https://akizukidenshi.com/catalog/g/gC-08935/ |

<div style="text-align: center;">
<img src="../images/ジャンパーケーブル黒.jpg" width="40%">
</div>




- マイクロSDのメディア : 好きなものを購入すれば良い(ただし，16GB以下)．

- [Grove – Chainable RGB LED](https://www.seeedstudio.com/Grove-Chainable-RGB-Led-V2-0.html)

<div style="text-align: center;">
<img src="../images/Grove_Chainable_RGB_LED.jpg" width="30%">
</div>





- [Adafruit DS3231 Precision RTC Breakout](https://www.adafruit.com/product/3013)

<div style="text-align: center;">
<img src="../images/Adafruit_DS3231.jpg" width="40%">
</div>




RTCにもピンヘッダが添付されているが，直線上のものが添付されているため，これを利用すると基板に印字されている端子の名称が読めなく
なるため，SDと同じく下のピンヘッダを使うことを勧める．
- [ピンヘッダ　（オスＬ型）](https://akizukidenshi.com/catalog/g/gC-01627/)

- [Grove - 4 pin Female Jumper to Grove 4 pin Conversion Cable](https://www.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html)

<div style="text-align: center;">
<img src="../images/Grove_4pin_Female_Jumper.jpg" width="50%">
</div>




RTCに加えて，I2Cインターフェースを使うセンサを使う場合や，RTC無しでI2Cインターフェースを持つセンサを複数接続する場合のみ以下の物品は必要になるが，
センサとして，何を使うか明確で無い場合は用意しておく方が望ましい．

- [Grove - I2C Hub](https://www.seeedstudio.com/Grove-I2C-Hub.html)


<div style="text-align: center;">
<img src="../images/Grove_I2C_Hub.jpg" width="30%">
</div>






<!-- コメントアウトしたい内容 -->
<!-- 

## 6. Arduino Nano ESP32



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


上記モジュールにはピンヘッダが添付されているが，直線上のものが添付されているため，これを利用すると基板に印字されている端子の名称が読めなく
なるため，下のようなL型のピンヘッダを使うことを勧める．
- ピンヘッダ　（オスＬ型）
https://akizukidenshi.com/catalog/g/gC-01627/

- ジャンパーワイヤ
|ケーブル色|販売元URL|
|---|---|
| 黒 | https://akizukidenshi.com/catalog/g/gC-08932/ |
| 赤 | https://akizukidenshi.com/catalog/g/gC-08933/ |
| 黄 | https://akizukidenshi.com/catalog/g/gC-08936/ |
| 青 | https://akizukidenshi.com/catalog/g/gC-08934/ |
| 白 | https://akizukidenshi.com/catalog/g/gC-08935/ |

![ジャンパーケーブル黒](../images/ジャンパーケーブル黒.jpg)


- マイクロSD : 好きなものを購入すれば良い(ただし，16GB以下)．


- Grove – Chainable RGB LED
![Grove – Chainable RGB LED](../images/Grove_Chainable_RGB_LED.jpg)
https://www.seeedstudio.com/Grove-Chainable-RGB-Led-V2-0.html

- Adafruit DS3231 Precision RTC Breakout
![Adafruit DS3231](../images/Adafruit_DS3231.jpg)
https://www.adafruit.com/product/3013

RTCにもピンヘッダが添付されているが，直線上のものが添付されているため，これを利用すると基板に印字されている端子の名称が読めなく
なるため，SDと同じく下のピンヘッダを使うことを勧める．
- ピンヘッダ　（オスＬ型）
https://akizukidenshi.com/catalog/g/gC-01627/


- Grove - 4 pin Female Jumper to Grove 4 pin Conversion Cable
![Grove - 4 pin Female Jumper](../images/Grove_4pin_Female_Jumper.jpg)
https://www.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html


- Grove - I2C Hub
![Grove - I2C Hub](../images/Grove_I2C_Hub.jpg)
https://www.seeedstudio.com/Grove-I2C-Hub.html

-->

***
- [「センサの手配」に進む](Sensor_List.md)
- [「部材の選択」に戻る](Parts_Selection.md)
- [マニュアルトップに戻る](../Manual.md)


# SHT31

SHT31は，SENSIRION社の温湿度センサでI2Cインターフェースで接続できます．

このセンサICを利用したセンサモジュールとしては，以下のようなものがある．

- 秋月電子 : https://akizukidenshi.com/catalog/g/gK-12125/


なお，ICの動作電圧は2.2Vから5.5Vである．


なお，このICのデータシートの日本語版を秋月電子が公開しているので，測定精度や動作条件などの詳細は確認していただきたい．
- https://akizukidenshi.com/download/ds/sensirion/Sensirion_Humidity_Sensors_SHT3x_DIS_Datasheet_V3_J.pdf

## Arduinoとの接続例

上記，秋月電子製のモジュールをarduinoに接続する場合，groveの基板と以下のケーブルを用いて接続するのが一番容易である．

- https://jp.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html?queryID=e8c3de5285fc84978b0660186520d221&objectID=2221&indexName=bazaar_jp_products

![Groveメスピンケーブル](../../images/Groveメスピンケーブル.jpg)

Grove用のケーブルの配線接続は以下の通り．
|ケーブルの色|接続先端子|
|---|---|
|黄|SCL|
|白|SDA|
|黒|GND|
|赤|+V|

![SHT31接続](../../images/SHT31接続.jpg)

Arduino側(Groveの基板)側はMKRのGrove基板では，TWIコネクタに接続する．
![MKR_carrier](../../images/MKR_carrier.png)

Grove用Shieldの場合は，「I2C」コネクタに接続する．

![Grove_Shield](../../images/Groveシールド.jpg)

## ``ADR``端子
先程の説明では，``ADR``端子は何も接続していない．SHT31はこの端子の配線で，I2Cのアドレスが変化する．
本開発環境では，デフォルト(配線しない)場合のアドレスを前提にしているため，
配線してはいけない．


## 接続先の情報

I2Cで接続する機器は特に情報をメモしておく必要はない．

***

- [「センサ端末の詳細定義」に戻る](../SensorSelection.md)



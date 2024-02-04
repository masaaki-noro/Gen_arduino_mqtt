# SHT2x

SENSIRION社の温湿度センサでI2Cインターフェースで接続できます．
SHT2xシリーズのセンサICは3種類存在し，低価格版のSHT20系，標準的な性能のSHT21系，高精度のSHT25系になります．

- 製品ページ https://www.sensirion.com/search/products?q=SHT2x

このセンサICを利用したセンサモジュールとしては，以下のようなものがある．

- [ストロベリーリナックス SHT21](https://strawberry-linux.com/catalog/items?code=80021)

<div style="text-align: center;">
<img src="../../images/SHT21.jpg" width="50%">
</div>


なお，ICの動作電圧はSHT21の場合，2.1Vから3.6Vであるため，3V系のマイコンに利用は限られる．

また，現在センサICのデバイスドライバはSHT21しか動作確認できていない．

## Arduinoとの接続例

上記，ストロベリーリナックス製のモジュールをGroveのシールドなどに接続するために作成した拡張基板の実例が以下の写真となる．

<div style="text-align: center;">
<img src="../../images/SHT21モジュール.jpg" width="70%">
</div>

もし，ストロベリーリナックス製のモジュールを，そのままarduinoのGroveシールドに接続する場合，
センサ基板の各端子にピンをはんだ付けした上で，
groveの基板と以下のケーブルを用いて接続するのが一番容易である．

- [Grove 4 ピン変換ゲーブル（メス-Grove ）](https://jp.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html?queryID=e8c3de5285fc84978b0660186520d221&objectID=2221&indexName=bazaar_jp_products)


<div style="text-align: center;">
<img src="../../images/Groveメスピンケーブル.jpg" width="50%">
</div>



Grove用のケーブルの配線接続は以下の通り．
|ケーブルの色|接続先端子|センサ側端子記号|
|---|---|---|
|黄|SCL|C|
|白|SDA|D|
|黒|GND|G|
|赤|+V|V|




Arduino側(Groveの基板)側はMKRのGrove基板では，TWIコネクタに接続する．

<div style="text-align: center;">
<img src="../../images/MKR_carrier.png" width="50%">
</div>


Grove用Shieldの場合は，「I2C」コネクタに接続する．

<div style="text-align: center;">
<img src="../../images/Groveシールド.jpg" width="70%">
</div>


ストロベリーリナックスのモジュールをGrove端子に合わせたセンサ基板をGroveシールドに接続した例が以下のイメージになる．

<div style="text-align: center;">
<img src="../../images/SHT21_example.jpg" width="90%">
</div>




## 接続先の情報

I2Cで接続する機器は接続したコネクタ(ピン番号)情報をメモしておく必要はない．

***

- [「センサ端末の詳細定義」に戻る](../SensorSelection.md)




# Grove Line Finder

1つのデジタル端子を使い，紙や地面に描いた黒線を検出するような目的で用いる．


Groveとしてモジュール化されたものも存在する．

- Grove - Line Finder https://wiki.seeedstudio.com/Grove-Line_Finder/

このモジュールは5V限定である．


下の写真はこのモジュールの基板部分の拡大であるが，赤外線のLEDと赤外線センサを組み合わせて，
LEDが発した赤外線を地面等で反射したものが赤外線センサで検知できるか否かでセンサの出力が変化する．

そのため，黒い地面などでは赤外線が検出できなくなることを利用して，判定を行う．


[写真出典](https://wiki.seeedstudio.com/Grove-Line_Finder/)

<div style="text-align: center;">
<img src="../../images/Grovelinefinder.jpg" width="70%">
</div>



## Arduinoとの接続例
デジタル端子1つに接続する必要があるため，Groveの端子に接続できるモジュールを用いる場合は，ケーブル1本で何れかのデジタル端子に接続すれば良い．


[写真出典](https://wiki.seeedstudio.com/Grove-Line_Finder/)

<div style="text-align: center;">
<img src="../../images/seeeduino_line_finder.jpg" width="90%">
</div>


## 接続先の情報

スイッチをどのピン(D0,D1など)に接続したかをメモしておく．

***

- [「センサ端末の詳細定義」に戻る](../SensorSelection.md)

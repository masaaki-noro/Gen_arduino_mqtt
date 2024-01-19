# LPS22HB

STマイクロ社の[LPS22HB](https://www.st.com/ja/mems-and-sensors/lps22hb.html)という気圧センサICである．

このセンサICを利用したセンサモジュールとしては，以下のようなものがある．

- Adafruit  https://www.adafruit.com/product/4633
- ストロベリーリナックス https://www.switch-science.com/products/2236
- Arduino MKR ENV Shield rev2 https://store.arduino.cc/products/arduino-mkr-env-shield-rev2

なお，動作電圧は1.7Vから3.6Vであるため，5Vで動作するArduino Uno等では使えません．

## 設定項目
設定すべき項目は2つ存在し，以下は設定ファイルのデフォルトを表している．

```
#
# LPS22HB
#
lps22hb:
  use_lps22hb: true # true(使う) , false(使わない)
  sensor_id: -1
```

## 利用のスイッチ
このセンサを使う場合は，この項目にtrueを設定する．
```
use_lps22hb: true # true(使う) , false(使わない)
```


## センサID
この数字を変更することで，多数のセンサが交じる環境で，このセンサのデータを特定することが可能．
```
sensor_id: -1
```

***

- [「センサの定義」に戻る](../SensorDefinition.md)


# RTCに設定されている時刻を確認するプログラム


## 本プログラムの機能

RTCの状態を見て，設定されている時刻が正しい(意図的に設定されたものか否か)を判定する．

もし，RTCの電源電圧低下が発生した
ことを示す値をRTCのレジスタが保持していれば，RTCの時刻は初期値に
戻っているはずなので，間違っているとみなす．



## 設定
「``config.h``」を編集して，以下の項目を利用する環境に合わせて変更




### 利用するRTCの選択
利用するRTCの種類に関する定義のみ有効化する．
```
//#define USE_RTC_4543
//#define USE_RTC8564NB
//#define USE_DS1307
//#define USE_DS3231
//#define USE_DS3234
//#define USE_PCF8523
//#define USE_RV8803
//#define USE_RX8025
//#define USE_RX8900
```

### RTCのインターフェース
I2Cではないインターフェースを持つ，RTCを使う場合は，Arduinoと接続する際のピン番号を以下の項目に定義(編集)する．
```
// 独自I/F : EPSON 4543
#define DATA_PIN 5
#define CLK_PIN 4
#define WR_PIN 12
#define CE_PIN 11
#define FSEL_PIN 13
// SPI : DS3234
#define CS_PIN 53 // 5 esp32  53 mega
#define SPI_IF SPI
// I2C : 各種
#define I2C_IF Wire
```

***
- [「README_RTC」に戻る](../README_RTC.md)

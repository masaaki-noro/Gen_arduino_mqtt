# プログラムテンプレートのカスタマイズ
本開発環境(下図)では，カスタマイズが頻繁に発生する部分については，仕様定義ファイルからの生成で対応しているが，
一部プログラムのテンプレートを修正する必要がある部分も存在する．

代表的な2つの項目についてプログラムのテンプレートを修正する方法を紹介する．

![システムイメージ](../images/System_Image.png)

## RTCの時刻
RTCのモジュールに電池が入っていない場合，電源投入直後はデフォルトの時刻(2001年元旦)になるが，
このデフォルトの時刻を変更する場合は以下のファイルを変更する必要がある．

- ``ルートディレクトリ/parts/util/RTC.cpp``

関数``void setupRTC(void)``の実装の中で以下のようにデフォルトの時刻を設定している．

```
  if (flag < 0) {
    outputBootlog(F("Error: fail to get power flag"));
    reboot();
  } else if (flag == TIME_IS_INVALID) {
    outputBootlog(F("Time of RTC setting is invalid."));
#ifdef USE_WDT
    Watchdog.reset();
#endif /* USE_WDT */
    date_t date;
    date.year=2001;
    date.month=1;
    date.mday=1;
    date.wday=MON;
    date.hour=0;
    date.minute=0;
    date.second=0;
    date.millisecond=0;
    outputBootlog(F("setting time."));
    if (!rtc.setTime(&date)) {
      outputBootlog(F("set time to RTC fail."));     // 初期化失敗
      reboot();
    } else {
      outputBootlog(F("set time to RTC success.")); // 初期化成功
    }
  } else {
    outputBootlog(F("Time of RTC setting is valid."));
  }
```

上の``date.メンバ``に代入している各値を変更すれば良い．
ただし，暦として有効な値であることと，RTCの内部時刻の関係上，
世紀をまたぐ(2000年問題や2100年)とか，UNIXのepoch time (1970年1月1日からの経過時間)の
問題に引っかかるような時刻の設定も動作は保証できません．

## 時刻情報の取得に使うNTPサーバとタイムゾーンの指定
本開発環境が生成するArduinoのスケッチでは，RTCへの時刻設定や，RTCを搭載していない場合にNTPで毎回時刻を
取得する場合がある．

このような場合のアクセス先のNTPサーバのカスタマイズは，プログラムのテンプレートを
編集する必要がある．

編集すべきテンプレートは以下のファイルである．
- ``ルートディレクトリ/parts/sketch/AusEx_MqttClient.ino``

このファイルに以下のようなNTPの定義が存在する．
```
#if defined(USE_NTP) || defined(UPDATE_RTC_BY_NTP)
#ifdef USE_ETHERNET
EthernetUDP ntpUDP;
#endif /* USE_ETHERNET */
#ifdef USE_WIFI
WiFiUDP ntpUDP;
#endif                                      /* USE_WIFI */
NTPClient timeClient(ntpUDP, 9 * 60 * 60);  // JST
#endif   /* USE_NTP or UPDATE_RTC_BY_NTP */
```
上のプログラム中の``NTPClient timeClient(ntpUDP, 9 * 60 * 60)``は，ArduinoのNTPライブラリのデフォルトのサーバを
使い，タイムゾーンは日本を使うことを宣言している．

### タイムゾーンの変更
``NTPClient timeClient(ntpUDP, 9 * 60 * 60)``の「``9*60*60``」の部分を変更先タイムゾーンの値に
合わせて変更すれば良い．

### NTPサーバの変更


デフォルトのNTPサーバは``pool.ntp.org``であるため，インターネットと直接通信できない場合は
変更する必要がある．

これを実現するために，NTPのライブラリは以下のようなAPIを提供している．
```
    NTPClient(UDP& udp, const char* poolServerName);
    NTPClient(UDP& udp, const char* poolServerName, long timeOffset);
    NTPClient(UDP& udp, const char* poolServerName, long timeOffset, unsigned long updateInterval);
    NTPClient(UDP& udp, IPAddress poolServerIP);
    NTPClient(UDP& udp, IPAddress poolServerIP, long timeOffset);
    NTPClient(UDP& udp, IPAddress poolServerIP, long timeOffset, unsigned long updateInterval);
```
上の6つのAPIのうちの1つを使うように変更すれば良い．

スケッチ(``ルートディレクトリ/parts/sketch/AusEx_MqttClient.ino``)のNTPクライアントの定義部分は以下のようになっている．
```
NTPClient timeClient(ntpUDP, 9 * 60 * 60)
```

これを下のように修正する．
```
NTPClient timeClient(ntpUDP, 指定したいサーバ名 or IPアドレス ,9 * 60 * 60)
```


***
- [マニュアルトップに戻る](../Manual.md)

# センサ端末の詳細定義

以下は，詳細定義ファイル(config.yaml)の事例であるが，前項の「genConfig.ipynb」で生成したものである．これに基づいて説明する．
```
platform:
  network_hardware:
    network_type: wifi # wifi , ethernet , none
    ethernet_chip_select: 10 # イーサネットのチップセレクトピン番号
  rtc:
    rtc_type: PCF8523 # RTC8564NB , DS1307 , DS3231 , PCF8523 , RV8803 , RX8025 , RX8900 , none
    rtc_int_pin: 4  # ピン番号
  color_led: 
    use_led: true # true(使う) , false(使わない)
    led_data_pin: 21 # ピン番号
    led_clk_pin: 20 # ピン番号
    led_duration: 3000 # 時間(単位:ミリ秒)
    led_short_duration: 1000 # 時間(単位:ミリ秒)
  sd:
    use_sd: true # true(使う) , false(使わない)
    sd_chip_select: 4 # ピン番号
  wdt:
    wdt_duration: 20000 # 時間(単位:ミリ秒)
    wdt_short_duration: 500 # 時間(単位:ミリ秒)

common:
  serial:
    speed: 9600 # コンソールのシリアル速度(bps)
  log:
    host_name: "MKR_WiFi1010" # ホスト名(文字列)
    app_name: "AusEx_mqtt_client" # アプリ名(文字列)
    use_logfile: true # true(使う) , false(使わない)
    use_serial_log: true # true(使う) , false(使わない)
    logfile_name_hdr: "/syslog" # ログファイル名
    logfile_size_max: 10000000 # ログファイルの最大値(バイト)
    log_rotate: false # true(使う) , false(使わない) 現在未対応
  clock:
    use_ntp : false # true(使う) , false(使わない)
    update_rtc_by_ntp : false # true(使う) , false(使わない)

network:
  wifi:
    ssid: "wifi_ssid" # ssid名
    wifi_pass: "wifi_password" # wifiパスワード
  ethernet:
    mac_addr: [ '0xaa', '0xbb', '0xcc', '0xdd', '0xee', '0xff']  # macアドレス
  ip:
    use_dhcp: true # true(使う) , false(使わない)
    ip_addr: [192, 168, 1, 111] # ipアドレス
    dns_server:  [192, 168, 1, 254] # DNSサーバ
    gateway: [192, 168, 1, 254] # gateway
    netmask: [255, 255, 255, 0] # マスク
  mqtt:
    mqtt_format: plain # plain, json, syslog
    mqtt_auth: false # true(使う) , false(使わない)
    mqtt_user: "foo" # ユーザ名(文字列)
    mqtt_pass: "bar" # パスワード(文字列)
    mqtt_topic: "arduino/echo" # MQTTトピック (文字列)
    mqtt_server: "192.168.1.254" # mqttサーバIPアドレス
    mqtt_port: 1883 # mqttポート番号

safety:
  use_wdt: true # true(使う) , false(使わない)

sensor:
  sensor_interval: 15000 # 測定間の待ち時間 (単位:ミリ秒)
  low_power:
    use_sleep: false # 待機中のsleep true(使う) , false(使わない)
    sleep_mode: power_down # idle, adc, power_save, standby, power_down

#
# SHT31
#
sht31:
  use_sht31: true # true(使う) , false(使わない)
  temperature_sensor_id: -1
  humidity_sensor_id: -1


#
# BME280
#
bme280:
  use_bme280: true # true(使う) , false(使わない)
  temperature_sensor_id: -1
  humidity_sensor_id: -1
  pressure_sensor_id: -1

```


## プラットフォーム定義
ここでは，ネットワークのメディアとして何を用いるか，RTC，LED，マイクロSD，WDT(Watchdogタイマ)の詳細を定義する．

```
platform:
  network_hardware:
    network_type: wifi # wifi , ethernet
    ethernet_chip_select: 10 # イーサネットのチップセレクトピン番号
  rtc:
    rtc_type: PCF8523 # RTC8564NB , DS1307 , DS3231 , PCF8523 , RV8803 , RX8025 , RX8900 , none
    rtc_int_pin: 4  # ピン番号
  color_led: 
    use_led: true # true(使う) , false(使わない)
    led_data_pin: 21 # ピン番号
    led_clk_pin: 20 # ピン番号
    led_duration: 3000 # 時間(単位:ミリ秒)
    led_short_duration: 1000 # 時間(単位:ミリ秒)
  sd:
    use_sd: true # true(使う) , false(使わない)
    sd_chip_select: 4 # ピン番号
  wdt:
    wdt_duration: 20000 # 時間(単位:ミリ秒)
    wdt_short_duration: 500 # 時間(単位:ミリ秒)
```

### ``network_hardware``
この部分では，ネットワークインターフェースの定義を行う．

``network_type``は，hardware.yamlの内容を引き継いでいることを確認し，同じであればそのままで良い．

``ethernet_chip_select``は，イーサネットを用いる基本システムであった場合に定義が必要になる．イーサネットは公式から発売されているシールドを用いているはずなので，そのシールドのチップセレクト端子の番号を記入する．WiFi接続の場合は，ここは無視されるので，適当な正の整数を入れておけば良い．


### ``rtc``
``rtc_type``は，hardware.yamlの内容を引き継いでいることを確認し，同じであればそのままで良い．
``rtc_int_pin``は現在使われていない項目なので，適当な正の整数を入れておけば良い．

### ``color_led``
``use_led``は，hardware.yamlの内容を引き継いでいることを確認し，同じであればそのままで良い．
他の項目として，ピン番号を指定しているが，ピン番号は``20``はデジタル端子の番号を示している．MKR WiFi1010では，下の図を見てわかるように，アナログ端子はすべてデジタル端子としても利用でき，デジタルの20番がアナログの5番，デジタルの21番がアナログの6番端子に相当する．
そのため，この定義の場合は，LEDをA5A6のコネクタに接続することを表している．
```
led_data_pin: 21 # ピン番号
led_clk_pin: 20 # ピン番号
```
[画像出典](https://docs.arduino.cc/hardware/mkr-wifi-1010)
![MKR_WiFi1010_pinout](../images/MKR_WiFi1010_pinout.png)

下の2つの項目は，LEDを点滅させる場合の点灯時間を記入する．
デフォルトは長い点灯が3秒，短い点灯が1秒にしている．
```
led_duration: 3000 # 時間(単位:ミリ秒)
led_short_duration: 1000 # 時間(単位:ミリ秒)
```

### SD/マイクロSD関係定義(``sd``)
最初の項目は，hardware.yamlの内容を引き継いでいることを確認し，同じであればそのままで良い．2つ目の項目は，マイクロSDのチップセレクト端子が配線されている端子番号を記入する．
基本的にシールドを用いているはずなので，配線図からピン番号を読取る．
```
use_sd: true # true(使う) , false(使わない)
sd_chip_select: 4 # ピン番号
```


### WatchDogタイマ ``wdt``
WatchDogタイマは一種のタイマで，この機能を有効にすると，一定時間以内にタイマを再起動しないと，システム全体がリブートする．この「一定時間」に相当する項目が以下の2つであり，
通常のアプリケーション動作中のタイマの有効期限が``wdt_duration``である．それに対して，``wdt_short_duration``はArduino自体をわざと再起動する場合に，``wdt_duration``と
同じ時間を待つのは，待ち時間が長すぎるため，短い時間を設定する．

この機能はプログラムがフリーズしてしまい，何もできなくなることを回避する目的で利用される．

現在のデフォルトの時間は，各種のセンサの観測時間の最大値を取っており，センサの種類によってはより短い時間にすることも可能であるが，無理に縮める必要はない．

```
wdt_duration: 20000 # 時間(単位:ミリ秒)
wdt_short_duration: 500 # 時間(単位:ミリ秒)
```

## ``common``定義
```
common:
  serial:
    speed: 9600 # コンソールのシリアル速度(bps)
  log:
    host_name: "MKR_WiFi1010" # ホスト名(文字列)
    app_name: "AusEx_mqtt_client" # アプリ名(文字列)
    use_logfile: true # true(使う) , false(使わない)
    use_serial_log: true # true(使う) , false(使わない)
    logfile_name_hdr: "/syslog" # ログファイル名
    logfile_size_max: 10000000 # ログファイルの最大値(バイト)
    log_rotate: false # true(使う) , false(使わない) 現在未対応
  clock:
    use_ntp : false # true(使う) , false(使わない)
    update_rtc_by_ntp : false # true(使う) , false(使わない)
```

### ``serial``

```
speed: 9600 # コンソールのシリアル速度(bps)
```
動作確認のために，センサ端末とPCをUSB接続する場合に，動作の監視はシリアルポートを監視することで実施する．
この時のシリアル通信の速度を指定する．この値は，Arduinoのシリアル機能がサポートしている速度を
入力する必要があるが，Arduino IDEのシリアルモニタがサポートしている通信速度から選ぶ．

これについては，Arduino IDEのシリアルモニタについて調べること．

### ``log``
以下の項目は，マイクロSDに保存されるログファイルや，シリアルに出力されるログに関連する設定項目である．
```
host_name: "MKR_WiFi1010" # ホスト名(文字列)
app_name: "AusEx_mqtt_client" # アプリ名(文字列)
use_logfile: true # true(使う) , false(使わない)
use_serial_log: true # true(使う) , false(使わない)
logfile_name_hdr: "/syslog" # ログファイル名
logfile_size_max: 10000000 # ログファイルの最大値(バイト)
log_rotate: false # true(使う) , false(使わない) 現在未対応
```

最初の2項目は，ログに追加されるホスト名やアプリ名である．
ログの各行のフォーマットは，Unix(Linux等)のsyslogに似たものに
なっているため，詳細は「syslog」で調べること．
```
host_name: "MKR_WiFi1010" # ホスト名(文字列)
app_name: "AusEx_mqtt_client" # アプリ名(文字列)
```

次の2行は，マイクロSDにログファイルを保存するか否かと，シリアルにログを出力するか否かを決める項目．
```
use_logfile: true # true(使う) , false(使わない)
use_serial_log: true # true(使う) , false(使わない)
```

最後の3行は，ログファイルを使う場合のオプションで，``logfile_name_hdr``はログファイル名(末尾に".txt"が付く)を決めるオプション．
次が，ログファイルの最大サイズで，これを超えると一度消される．最後は未サポート機能のフラグであるため無視．
```
logfile_name_hdr: "/syslog" # ログファイル名
logfile_size_max: 10000000 # ログファイルの最大値(バイト)
log_rotate: false # true(使う) , false(使わない) 現在未対応
```

### ``clock``
これは，時計に関する設定項目で，最初は時刻情報を把握するのに，インターネットのNTPプロトコルを使うか否か．
次が，RTCを使う場合に，NTPで時刻を保守するか否かを決めるもの．
```
use_ntp : false # true(使う) , false(使わない)
update_rtc_by_ntp : false # true(使う) , false(使わない)
```

NTP (Network Time Protocol)とは，ネットワーク上のNTPサーバに時刻情報を要求する
パケットを複数回送信し，サーバからは現在時刻が返される．

この時のパケットの往復に必要な時間とパケットの中に書き込まれている現在時刻から
本当の現在時刻をミリ秒単位で求める技術．

NTPを使うためには，センサ端末からインターネットのNTPサーバにアクセスできる必要があるため，
利用可能なシーンは限られる．

## ``network``定義

```
network:
  wifi:
    ssid: "wifi_ssid" # ssid名
    wifi_pass: "wifi_password" # wifiパスワード
  ethernet:
    mac_addr: [ '0xaa', '0xbb', '0xcc', '0xdd', '0xee', '0xff']  # macアドレス
  ip:
    use_dhcp: true # true(使う) , false(使わない)
    ip_addr: [192, 168, 1, 111] # ipアドレス
    dns_server:  [192, 168, 1, 254] # DNSサーバ
    gateway: [192, 168, 1, 254] # gateway
    netmask: [255, 255, 255, 0] # マスク
  mqtt:
    mqtt_format: plain # plain, json, syslog
    mqtt_auth: false # true(使う) , false(使わない)
    mqtt_user: "foo" # ユーザ名(文字列)
    mqtt_pass: "bar" # パスワード(文字列)
    mqtt_topic: "arduino/echo" # MQTTトピック (文字列)
    mqtt_server: "192.168.1.254" # mqttサーバIPアドレス
    mqtt_port: 1883 # mqttポート番号
```

### ``wifi``
ここでは，WiFiのSSIDとパスワードを記載する．この時，パスワードは平文で記入する．
```
ssid: "wifi_ssid" # ssid名
wifi_pass: "wifi_password" # wifiパスワード
```


### ``ethernet``
```
mac_addr: [ '0xaa', '0xbb', '0xcc', '0xdd', '0xee', '0xff']  # macアドレス
```

ここでは，イーサネットのMACアドレスを記入する．

Arduinoのイーサネットシールドのうち，Classicシリーズのシールドには，Arduinoの製造元が取得したMACアドレスが
記載されたシールが貼られているため，そのアドレスを転記すれば良い．

一方，MKRのイーサネットシールドにはMACアドレスのシールがないため，自分でMACアドレスを決めて，そのアドレスを記入する必要があるため，
既に割り当ててある場合はそれを利用し，もし，割り当てられていない場合は，
自由に使って良いMACアドレス空間を利用し，MACアドレスを自動で生成するWebサービス([ここ](https://miniwebtool.com/ja/mac-address-generator/)とか[ここ](https://www.bungu-do.jp/tools/mac_address))を
利用してMACアドレス空間の中のローカルアドレスから作り出してそれを利用する．

### ``ip``
ここでは，IPプロトコルに関する設定を行う．
```
use_dhcp: true # true(使う) , false(使わない)
ip_addr: [192, 168, 1, 111] # ipアドレス
dns_server:  [192, 168, 1, 254] # DNSサーバ
gateway: [192, 168, 1, 254] # gateway
netmask: [255, 255, 255, 0] # マスク
```

最初の``use_dhcp``はDHCP(アドレス自動設定)を使うか否かで，それ以下は，アドレスを手動設定する場合に必要な項目．
もし，自動設定を行う場合は内容は変更せず，そのまま残しておくこと．

### ``mqtt``
ここでは，MQTTプロトコルに関連した設定を行う．
```
mqtt_format: plain # plain, json, syslog
mqtt_auth: false # true(使う) , false(使わない)
mqtt_user: "foo" # ユーザ名(文字列)
mqtt_pass: "bar" # パスワード(文字列)
mqtt_topic: "arduino/echo" # MQTTトピック (文字列)
mqtt_server: "192.168.1.254" # mqttサーバ(ブローカ)IPアドレス
mqtt_port: 1883 # mqttポート番号
```

``mqtt_format``これは，MQTTで送信するメッセージのフォーマットの定義である．``plain``が平文，``syslog``はsyslog準拠のフォーマット，``json``はJSONフォーマットと呼ばれる
計算機の取り扱いは容易だが，人が読むのには適していないフォーマットである．そのため，最初の動作確認レベルまでは，``plain``か``syslog``で動作確認を行い，
実際にIoTサーバ上にアプリケーションを作る際には，センサからMQTTで送信するデータの形式は``json``に変更する方が良い．

``mqtt_auth``はmqttのプロトコルで通信する際に，認証を行うか否かのスイッチである．これも，試作の初期段階や，学生の実習などでは無しでも構わない．
実際にネットワークを運用する際には，``true``にすることが求められる．

```
mqtt_user: "foo" # ユーザ名(文字列)
mqtt_pass: "bar" # パスワード(文字列)
```
上の2つの項目は認証を使う場合のユーザ名とパスワードになる．認証を使わない場合は，変更しないまま置いておくこと．もし，認証を行う場合は，
適切な値に書き換える．ここのパスワードもWiFiと同じく平文で記入する必要がある．


``mqtt_topic``はセンサ端末となるArduinoがMQTTでデータを送信する際に，自分のメッセージが容易に識別できるようにするために付与するタグである．
複数のセンサ端末を配置する場合は，区別が容易になるように，端末毎に異なる``topic``を決めて，その文字列を記入する．

```
mqtt_server: "192.168.1.254" # mqttサーバ(ブローカ)IPアドレス
mqtt_port: 1883 # mqttポート番号
```
最後の2つの項目は，IoTゲートウェイで動作させるMQTTブローカの情報である．
最初のIPアドレスは，IoTゲートウェイのIPアドレスで，2番目のポート番号は
MQTTブローカが送信を待ち受けるポート番号である．
デフォルトの値は，MQTTで広く用いられているポート番号であり，
ブローカ側で特に設定を変えていなければ，こちらも変更する必要はない．

## ``safety``定義
ここでは，Watch Dogタイマを使うか否かを定義する．
```
use_wdt: true # true(使う) , false(使わない)
```

``platform``でも，WDTに関する設定項目があったが，最終的に生成されるArduinoのプログラムでは，WDTを
単純な再起動目的と，WDTの本来の目的である，フリーズからの復帰の2つの目的で活用している．

ここでの定義は，WDT本来の目的である，フリーズからの復帰としてのWDTを有効に
するか否かを切り替えることができる．


## ``sensor``共通定義
ここでは，センサの動作全般に共通する設定を行う．
```
sensor:
  sensor_interval: 15000 # 測定間の待ち時間 (単位:ミリ秒)
  low_power:
    use_sleep: false # 待機中のsleep true(使う) , false(使わない)
    sleep_mode: power_down # idle, adc, power_save, standby, power_down
```

### ``sensor_interval``
```
sensor_interval: 15000 # 測定間の待ち時間 (単位:ミリ秒)
```
この項目は，センサによる測定(観測)を行った後，次の測定までの待ち時間をミリ秒単位で指定する．
デフォルト値は15秒に一回測定とデータ送信を行う設定になっている．

注意が必要な点として，次で説明する省電力モード(下記の``use_sleep``)と組み合わせる場合である．

センサ端末全体の消費電力を削減するために，ここで指定する待機時間の間省電力モードになるが，
この設定項目で指定した時間が経過すると，動作が再開する．

この時に，周辺機器の状態を元に戻すなどの処理に時間が必要になるため，省電力設定を行った場合は，
測定間隔とここでの設定時間は一致しない．

特に，測定周期と待機時間の差が大きくなるのは，MCUにESP32を使った機種を用いている場合である．
ESP32で消費電力が少ない状態に設定すると，復帰は元に戻るのではなく，再起動になる．
そのため，測定周期は，ここで指定した時間と起動から測定までの総所要時間を加える必要がある．


### ``low_power``(省電力)設定
ここでは，センサ端末の省電力を抑制する機能に関する設定を行う．
```
use_sleep: false # 待機中のsleep true(使う) , false(使わない)
sleep_mode: power_down # idle, adc, power_save, standby, power_down
```

``use_sleep``は観測しないで待つ際に，低消費電力モードに移行するか否かを定義する．

モード(``sleep_mode``)については，MCUと周辺回路のどこまでを止めるかを指定する項目である．
これは，MCUの種類によって消費電力の差もどこを止めるかも変わってくるため，
ここでは，詳しくは解説しないが，消費電力は``idle > adc > power_save > standby > power_down``となる．

ESP32に関しては，``idle``以外を指定すると，ESP32の使用上スリープからの復帰が必ず再起動になってしまうため，
起動に時間がかかり，短い周期で測定を行う場合には，実際にデータを測定したい周期の時間より，再起動に必要な
時間が長くなる．

さらに，スリープからの復帰時は通常の動作時より消費電力が多くなることは珍しくないため，スリープのモードに何を使うべきかは
消費電力とスリープからの復帰に必要な時間や消費電力を考慮して決めるのが望ましい．

また，MCUにSAMDを用いているMKRファミリの機種などは，PCとUSB接続をしていると，idleではUSBからの信号で
省電力モードから抜け出してしまい，測定後の待機時間がほぼ0になる．



***

- [「センサの定義」に進む](SensorDefinition.md)
- [「ハードウェアの定義」に戻る](HardwareDefinition.md)
- [「README」に戻る](../README.md)

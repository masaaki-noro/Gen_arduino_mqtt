# Pythonのインストールと関連作業

本プロジェクトで，Arduinoにインストールするためのプログラム(Arduinoではスケッチと呼ぶ)を生成する機能はPythonのスクリプトで実現されている．

PythonのインストールはOSによって異なるため，インストール方法は
説明しない．

また，Python用のライブラリの管理も必要になるため，
``pip``もしくは``Anaconda``を同時にインストールしてください．

初めての人には``pip``を勧めます．

windowsの場合は，下のURLからインストール用バイナリをダウンロードできます．

- [https://www.python.org/downloads/windows/](https://www.python.org/downloads/windows/)

## 1. Python用ライブラリ

GUI用とyaml用のライブラリとして3つのライブラリをインストールする必要があります．

- PyYaml https://pypi.org/project/PyYAML/
- flet https://pypi.org/project/flet/
- flet_multi_page https://github.com/SKbarbon/flet_multi_page

``pip``を利用している人は，各ライブラリのURLを見てインストールしてください．




## 2. 注意事項 : 各プログラムの実行可能バイナリ化
Pythonには，「``pyinstaller``」と呼ばれるプログラムで，Pythonのプログラム(スクリプト)を
実行可能なバイナリに変換することができます．

ただし，本開発環境のプログラムでは，ヘルプ画面の出力に利用しているPythonライブラリ「``flet_multi_page``」が実行可能なバイナリに
変換できない(変換すると動作がおかしくなる)ため，``pyinstaller``で実行可能なバイナリに変換することはできません．


***

- [「Arduinoのプログラム(スケッチ)のインストール」に戻る](スケッチのコンパイルとインストール.md)
- [マニュアルトップに戻る](../Manual.md)


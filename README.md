# project Themis

## これはなに?
他のライブラリやアプリケーションを實裝するときに
使ひ廻すであらう基礎的なコードを、
ライブラリに纏めておかうと企圖したもの。

## Themisとは?
[女神テミス][https://ja.wikipedia.org/wiki/%E3%83%86%E3%83%9F%E3%82%B9]の名前を拜借した。

## 内容
* 整數の別名 <themis/inttype.h>
* 基底となり得る例外クラス <themis/except.h>

整數の別名については、今から新しく書くコードで使ふやうなものではないと我ながら思ふ。&lt;cstdint&gt;で定義された名前を使ふ方があらゆる意味で宜しからう。

## 使ひ方
CMakeLists.txtを提供してゐるので、それを用ゐてインストールしてもよいし、
(今のところ)全てがヘッダファイルで實裝されてゐるので、
ヘッダファイルを適當なところにコピーしてincludeして使つてもよい。

cmakeを用ゐてインストールした場合、
libthemisを利用するプログラムをcmakeを使つてbuildするのであれば、
CMakeLists.txtに
    find_package(themis REQUIRED)
    # ...
    target_link_libraries(targetname themis ...)
のやうに書けば、include pathを適宜設定してくれる、はず。
この場合、ソースコードからは、
    #include <themis/except.h>
のやうにincludeする。

## ライセンス
[二條項BSDライセンス][https://opensource.org/licenses/BSD-2-Clause]とする。

## 作者
oZ/acy (名賀月晃嗣)
* <acy@hiemalis.org>
* <http://www.hiemalis.org>


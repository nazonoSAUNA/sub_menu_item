# sub_menu_item
AviUtlのプラグインメニューを設定で無効にする
[ダウンロードはこちら](../../releases/)


## 動作要件
- Visual C++ 再頒布可能パッケージの2022 x86(32bit)対応の物がインストールされている必要があります【Microsoft Visual C++ 2015-2022 Redistributable(x86)】→ 導入方法:< https://scrapbox.io/nazosauna/Visual_C++_再頒布可能パッケージをインストールする >

- AviUtlバージョン1.10のみ対応しています


## このプラグインの目的
プラグインによるメニュー追加（ショートカット項目追加）の数には255個までという上限があります。

![image](https://github.com/nazonoSAUNA/sub_menu_item/assets/99536641/103f393a-6532-4814-a6fc-fdea51711e18)

最近の便利なプラグインが増ええている環境において上限に達してしまうことがあるため、厳選するためのプラグインが必要となったため作りました。

あとは単純に明らかに不要なメニューを消して見やすくするということにも使えます

## 説明
このプラグインを導入してAviUtlを起動することで、aviutl.iniに以下のような項目が追加されます。
初めは全て`=1`となっており有効の状態です。`=0`とすることで次の起動時からメニューを無効化します。
```
[sub_menu_item]
拡張編集_新規プロジェクトの作成=1
拡張編集_選択オブジェクトを分割=1
拡張編集_選択オブジェクトを切り取り=0
拡張編集_選択オブジェクトを複製=1
拡張編集_選択オブジェクトに中間点を追加=1
拡張編集_選択オブジェクトの中間点を時間で均等配置=1
拡張編集_選択オブジェクトの中間点を距離で均等配置=1
拡張編集_選択オブジェクトにフィルタ効果を追加=0
拡張編集_選択オブジェクトの長さを変更=1
拡張編集_選択オブジェクトがあるレイヤーの表示/非表示=1
拡張編集_現在のフレームのオブジェクトへ移動=1
拡張編集_次のオブジェクトへ移動=1
拡張編集_前のオブジェクトへ移動=1
拡張編集_グリッドの表示/非表示=0
拡張編集_グリッドの設定=0
拡張編集_フレーム領域外の表示=0
拡張編集_カメラ視点GUIの表示=0
拡張編集_画像処理の間引きON/OFF=0
拡張編集_タイムラインの拡大=0
拡張編集_タイムラインの縮小=0
拡張編集_キャッシュを破棄=1
拡張編集_現在のフレームからプレビュー再生=1
拡張編集_現在のフレーム以降に空フレームを挿入=0
拡張編集_最後のオブジェクト位置を最終フレーム=1
拡張編集_現在位置を最終フレーム=1
拡張編集_オブジェクトのコピー(メインウィンドウ)=1
拡張編集_オブジェクトのペースト(メインウィンドウ)=1
拡張編集_オブジェクトの削除(メインウィンドウ)=1
```


これにより以下の項目で対象のメニューが使えなくなります

- ショートカットの設定

![image](https://github.com/nazonoSAUNA/sub_menu_item/assets/99536641/103f393a-6532-4814-a6fc-fdea51711e18)

- 上部メニューの編集の部分

![image](https://github.com/nazonoSAUNA/sub_menu_item/assets/99536641/cfa44a8b-cbca-43e9-97b8-d50b9b080ce3)


- それ以外でメニューを選択する手段がある場合は問題なく使える可能性が高いですが、プラグインによっては問題が起こる可能性は否定できません。例として拡張編集の以下の項目は問題なさそうでした

![image](https://github.com/nazonoSAUNA/sub_menu_item/assets/99536641/2fc32172-b5b5-4215-83a9-84b139fef575)


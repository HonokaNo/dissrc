# dissrc

dissrcは、discord用botのオープンソース化を推進したいために勝手に作った、
トークンのないソースコードからトークンを追加したソースコード及び.gitignoreを生成するソフトです。

ざっくりとした使い方
1.client.runのないソースコードを作る(例としてbotmain0.pyとしておく)
2.トークンを記述したファイルを作成する(例としてtoken.txtとしておく)
3.このアプリを使ってソースを生成する(例:dissrc botmain0.py token.txt botmain.py)
4.トークンを追加した起動可能なソースコードができる(今回の場合botmain.py)
5.また、.gitignoreがあるためgithubにそのままpushできる!

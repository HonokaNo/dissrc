# dissrc

dissrcは、discord用botのオープンソース化を推進したいために勝手に作った、<br>
トークンのないソースコードからトークンを追加したソースコード及び.gitignoreを生成するソフトです。<br>
<br>
ざっくりとした使い方<br>
1.client.runのないソースコードを作る(例としてbotmain0.pyとしておく)<br>
2.トークンを記述したファイルを作成する(例としてtoken.txtとしておく)<br>
3.このアプリを使ってソースを生成する(例:dissrc botmain0.py token.txt botmain.py)<br>
4.トークンを追加した起動可能なソースコードができる(今回の場合botmain.py)<br>
5.また、.gitignoreがあるためgithubにそのままpushできる!<br>

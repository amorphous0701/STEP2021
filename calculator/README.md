## 第3回課題の説明 (modularized_calculator_parenthesis.py)
### 各関数の説明
#### out_parenthesis
括弧("("と")")を括弧内を計算して外す。
#### new_line
out_parenthesisの中で用いられている。
式を引数に取り、括弧を外した新たな式を返す。
#### tokenize
式を+,-,数字に分解したリストを返す。
#### evaluate
+,-,数値からなるリストを計算する。
#### read_number
tokenize中で用いられている。
掛け算割り算のみからなる式を計算し、答えを返す
#### read_plus
tokenize中で用いられている。
+符号を表すペアを返す。
#### read_minus
tokenize中で用いられている。
-符号を表すペアを返す。
#### test
計算式を代入することで、上記の関数を実行し、計算結果を返す。
プログラムを用いるときに使う関数はことtest関数のみ。

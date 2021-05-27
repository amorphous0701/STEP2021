## 第3回課題の説明 (modularized_calculator_parenthesis.py)
### 各関数の説明
#### out_parenthesis(line)
line内で最も範囲が狭い括弧("("と")")を括弧内を計算して外す。
#### new_line(line,max_p,check)
out_parenthesisの中で用いられている。
引数に取った式lineの括弧を外し、新たな式を返す。
#### tokenize(line)
式lineを+,-,数字に分解し、トークン化したリストを返す。
#### evaluate(tokens)
tokenizeで作った+,-,数値トークンからなるリストを計算する。
#### read_number(line,index)
tokenize中で用いられている。
掛け算・割り算を含む式を計算し、答えを返す。
#### read_plus(line,index)
tokenize中で用いられている。
+符号を表すトークンを返す。
#### read_minus(line,index)
tokenize中で用いられている。
-符号を表すトークンを返す。
#### test(line)
計算式を代入することで、上記の関数たちを実行し、計算結果を返す。
実際計算する際に用いる関数はこのtest関数のみ。

# Google STEP Class 4 Homework

## 課題内容

### 1. Wikipediaのグラフを使ってなにか面白いことをしてみよう

- "Google"から"渋谷"までを（最短で）たどる方法:
BFSで実装しました。2回移動しましたが、(今は)Googleのwikipediaのページから1回で飛べます。
- その他なんでも
せっかくなのでGoogleとジャグリングまでたどれるか調べようと思いましたが、時間がかかりすぎて結局わかりませんでしたorz

### 2. 他の人の書いたコードを自分の環境で実行してレビューする
近々やります！

### 3. 各関数の説明
#### void read_pages(map<string, string>& pages, string path)
pathにあるデータをpagesに収納する関数。今回の場合pagesには,{ページの名前,ページのID}の状態で収納されている。
#### void read_links(map<string, set<string>>& links, string path)
pathにあるデータをlinksに収納する関数。今回の場合linksには{ページのID,{行ける先のID}}が収納されている。
#### string name_to_number(string name, map<string, string> pages)
nameに対応するIDをpagesから見つけ、それを返す関数。
#### vector<string> find_route(string to, map<string, set<string>> links, vector<string> check, queue<Tuple> que)
BFSを用いてIDがtoと一致するノードを発見するまで探索。
toは数字の文字列でゴールのIDを示す。linksには{ページのID,{行ける先のID}}が収納されている。checkには既に訪れたところのIDが入っている。queは次にチェックするIDが収められている。
#### void show(vector<string> path)
vectorの中身を一つずつ表示するための関数。
今回はfind_routeで返された経路を表示するために用いている。

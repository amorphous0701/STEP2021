#include <bits/stdc++.h>
using namespace std;


string find_anagram(string s, vector<vector<string>> lis)
{
    for (int i = 0; i <lis.size(); i++) {
        string S=s;
        int count = 0;
        string lis_s = lis[i][1];
        for (int j = 0; j < lis_s.length(); j++) {
            if (S.find(lis_s[j]) != -1) {
                count++;
                S.erase(S.find(lis_s[j]),1);
            }
        }
        if (count == lis_s.length()) {
            return lis_s;
        }
    }
    return "";
}

int main()
{
    ifstream ifs("words2.txt"); //得点ー単語のリスト、得点降順にソート済み
    ifstream ifs_text("large.txt");//入力する単語リスト
    ofstream ofs("large_answer.txt");//出力する答え
    vector<vector<string>> lis;
    while (!ifs.eof()) {
        string ana, mot;
        ifs >> ana >> mot;
        if(ana.length()>0){
            lis.push_back({ana, mot});
        }
    }
    while(!ifs_text.eof()){
        string data;ifs_text>>data;
        if(data.length()>0){
            ofs<<find_anagram(data,lis)<<endl;
        }
    }
    ofs.close();
}
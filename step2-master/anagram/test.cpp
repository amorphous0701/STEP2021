#include <bits/stdc++.h>
using namespace std;


string change(string S)
{
    for (int i = 0; i < S.length(); i++) {
        for (int j = 0; j < S.length() - i - 1; j++) {
            if (S[j] > S[j + 1]) {
                char s = S[j];
                S[j] = S[j + 1];
                S[j + 1] = s;
            }
        }
    }
    return S;
}

int score(string s){
    int n = s.length();
    int count = 0;
    for(int i=0;i<n;i++){
        if(string("aehinorst").find(s.at(i))!=-1){
            count+=1;continue;
        }else if(string("cdlmu").find(s.at(i))!=-1){
            count+=2;continue;
        }else if(string("bfgpvmy").find(s.at(i))!=-1){
            count+=3;continue;
        }else if(string("jkqxz").find(s.at(i))!=-1){
            count+=4;continue;
        }
    }
    return count;
}


string binary_search(string s, vector<vector<string>> lis)
{
    for (int i = lis.size()-1; i >=0; i--) {
        string S=s;
        int count = 0;
        string lis_s = lis[i][1];
        cout<<lis_s<<endl;
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
}

int main()
{
    ifstream ifs("words2.txt");
    vector<vector<string>> lis;
    string ana, mot, kazu;
    while (!ifs.eof()) {
        ifs >> ana >> mot >> kazu;
        lis.push_back({ana, mot, kazu});
    }

        string text;
        cin>>text;
        cout<<binary_search(text,lis)<<endl;;
}
#include <bits/stdc++.h>
using namespace std;


string change(string S){
    for(int i=0;i<S.size();i++){
        for(int j=0;j<S.size()-i-1;j++){
            if(S[j]>S[j+1]){
                char s=S[j];
                S[j]=S[j+1];
                S[j+1]=s;
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
            count+=1;
        }else if(string("cdlmu").find(s.at(i))!=-1){
            count+=2;
        }else if(string("bfgpvwy").find(s.at(i))!=-1){
            count+=3;
        }else if(string("jkqxz").find(s.at(i))!=-1){
            count+=4;
        }
    }
    return count;
}

int main(){
    vector<pair<int,string>> S;
    ifstream ifs("words.txt");
    ofstream ofs("words2.txt");
    string data;
    while(!ifs.eof()){
        ifs>>data;
        S.push_back(pair(score(data),data));
    }
    sort(S.begin(),S.end());
    reverse(S.begin(),S.end());
    for(int i=0;i<S.size();i++){
        ofs<<S[i].first<<" "<<S[i].second<<endl;
    }
    ofs.close();
}
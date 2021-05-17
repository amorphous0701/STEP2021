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

int main(){
    vector<vector<string>> S;
    ifstream ifs("words.txt");
    ofstream ofs("words2.txt");
    string data;
    while(!ifs.eof()){
        ifs>>data;
        S.push_back({change(data),data});
    }
    sort(S.begin(),S.end());
    for(int i=0;i<S.size();i++){
        ofs<<S[i][0]<<endl;
        ofs<<S[i][1]<<endl;
    }
    ofs.close();
}
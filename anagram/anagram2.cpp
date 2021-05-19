#include <bits/stdc++.h>
using namespace std;


string change(string S){
    for(int i=0;i<S.length();i++){
        for(int j=0;j<S.length()-i-1;j++){
            if(S[j]>S[j+1]){
                char s=S[j];
                S[j]=S[j+1];
                S[j+1]=s;
            }
        }
    }
    return S;
}

void binary_search(string s,vector<vector<string>> lis,string &long_s,int &max){
    int right=0;int left=lis.size();
    int mid= (right + left )/2;
    int count=0;
    while(s!=lis[mid][0]){
        if(s>lis[mid][0]){
            right=mid;
            mid = (right + left )/2;
        }else{
            left=mid;
            mid = (right + left )/2;
        }
        count++;
        if(count==20){
            return ;
        }
    }
    if(stoi(lis[mid][2])>max){
        max=stoi(lis[mid][2]);
        long_s=lis[mid][1];
    }
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

void check(string s,vector<vector<string>> lis){
    int S=s.size();
    int score=0;
    string long_s="";
    for(int i=0;i<(1<<S);i++){
        string check="";
        for(int j=0;j<S;j++){
            if(i&(1<<j)){
                check.push_back(s.at(j));
            }
        }
        binary_search(check,lis,long_s,score);
    }
    cout<<long_s<<endl;
}

int main(){
    string s;cin>>s;
    s=change(s);
    ifstream ifs("words3.txt");
    vector<vector<string>> lis;
    string ana,mot,kazu;
    while(!ifs.eof()){
        ifs>>ana>>mot>>kazu;
        lis.push_back({ana,mot,kazu});
    }
    cout<<"GO"<<endl;
    check(s,lis);
}
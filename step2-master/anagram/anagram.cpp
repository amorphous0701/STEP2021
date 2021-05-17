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

int binary_search(string s,vector<vector<string>> lis){
    int right=0;int left=lis.size();
    int mid= (right + left )/2;
    while(s!=lis[mid][0]){
        if(s>lis[mid][0]){
            right=mid;
            mid = (right + left )/2;
        }else{
            left=mid;
            mid = (right + left )/2;
        }
    }
    return mid;
}

void anagram_search(string s,int num,vector<vector<string>> lis){
    cout<<lis[num][1]<<endl;
    int num1=num;
    while(s==lis[num1+1][0]){
        num1++;
        cout<<lis[num1][1]<<endl;
    }
    int num2=num;
    while(s==lis[num2-1][0]){
        num2--;
        cout<<lis[num2][1]<<endl;
    }
}


int main(){
    string s;cin>>s;
    s=change(s);
    ifstream ifs("words.txt");
    vector<vector<string>> lis;
    string ana,mot;
    while(!ifs.eof()){
        ifs>>ana>>mot;
        lis.push_back({ana,mot});
    }
    anagram_search(s,binary_search(s,lis),lis);
}
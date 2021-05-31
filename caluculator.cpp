#include <bits/stdc++>
using namespace std;



vector<pair<string,string>> tokenize(string formula){
    vector<pair<string,string>> tokens;
    index=0;
    while(index<formula.length()){
        pair<string,string> token;
        if(isdigit(formula[index])){

        }else if(formula[index]=="+"){
            token = read_plus(formula,index);
        }else if(formula[index]=="-"){
            token = read_minus(formula,index);
        }else{

        }
        tokens.push_back(token);
    }
    return tokens;
}

double evaluate(vector<pair<string,string>> tokens){
    

}

int main(){
    string formula;
    cout<<">";
    cin>>formula;
    vector<pair<string,string>> tokens=tokenize(formula);
    double answer=evaluate(tokens);
    cout<<answer<<endl;
}
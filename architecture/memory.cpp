#include <bits/stdc++.h>
using namespace std;

int main(){
    int N=1024;

    vector<vector<int>> A(N,vector<int>(N)); 
    vector<vector<int>> B(N,vector<int>(N)); 
    vector<vector<int>> C(N,vector<int>(N)); 

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            A[i][j]=B[i][j]=i+j;
        }
    }

    clock_t start = clock(); 

    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }

    clock_t end = clock();   

    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

}
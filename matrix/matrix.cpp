#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));
    vector<vector<int>> C(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i * N + j;
            B[i][j] = j * N * i;
            C[i][j] = 0;
        }
    }
    clock_t start = clock();  //計測開始

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int l = 0; l < N; l++) {
                C[i][j] += A[i][l] * B[l][j];
            }
        }
    }

    clock_t end = clock();  //計測終了

    cout << end - start << endl;  //時間表示(ms)
}
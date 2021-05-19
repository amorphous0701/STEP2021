#include <bits/stdc++.h>
using namespace std;

string sort_string(string S)
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

int binary_search(string s, vector<vector<string>> lis)
{
    int right = 0;
    int left = lis.size() - 1;
    while (left>=right) {
        int mid = (right + left) / 2;
        if(lis[mid]==s) return mid;
        else if (s < lis[mid][0]) left=mid-1;
        else if(s>lis[mid][0])right = mid + 1;
    }
    return -1;
}

void anagram_search(string s, int num, vector<vector<string>> lis)
{
    cout << lis[num][1] << endl;
    int num1 = num;
    while (s == lis[num1 + 1][0]) {
        num1++;
        cout << lis[num1][1] << endl;
    }
    int num2 = num;
    while (s == lis[num2 - 1][0]) {
        num2--;
        cout << lis[num2][1] << endl;
    }
}


int main()
{
    string s;
    cin >> s;
    s = sort_string(s);
    ifstream ifs("words.txt");
    vector<vector<string>> dictionary;
    string word, o_word;
    while (!ifs.eof()) {
        ifs >> word >> o_word;
        dictionary.push_back({word, o_word});
    }
    anagram_search(s, binary_search(s, dictionary), dictionary);
}
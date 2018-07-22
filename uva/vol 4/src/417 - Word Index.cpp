//
// 417 - Word Index
//
// Created by Ridhwanul Haque on 03/03/2018
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> combinations(vector<string> S, int size) {
    vector<string> combs;
    if (size == 1) {
        for (string s : S) {
            combs.push_back(s);
        }
    } else {
        for (int i = 0; i < S.size(); i++) {
            vector<string> rem;
            for (int j = i+1; j < S.size(); j++) rem.push_back(S[j]);
            if (rem.size() != 0) {
                vector<string> sub_combs = combinations(rem, size-1);
                for (string sc : sub_combs) {
                    string k = S[i];
                    k += sc;
                    combs.push_back(k);
                }
            }
        }
    }
    return combs;
}

int main(){
    vector<string> letters;
    char c = 'a';
    for (int i = 0; i < 26; i++) {
        letters.push_back(string(1,c));
        c += 1;
    }
    vector<string> valid_words;
    for (int i = 1; i <= 5; i++) {
        vector<string> combs = combinations(letters, i);
        for (string comb : combs) {
            valid_words.push_back(comb);
        }
    }
    string word;
    string output;
    while (cin >> word) {
        vector<string>::iterator it = find(valid_words.begin(), valid_words.end(), word);
        if (it != valid_words.end()) output += to_string((it-valid_words.begin())+1) + "\n";
        else output += "0\n";
    }
    cout << output;
}

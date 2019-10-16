//
// 10252 - Common Permutation
//
// Created by Ridhwanul Haque on 14/03/2018
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string word1, word2;
    string output;
    while (true) {
        if (cin.eof()) break;
        getline(cin, word1);
        getline(cin, word2);
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());
        if (word1 == word2) {
            output += word1 + "\n";
            continue;
        }
        if (word1.size() == 0 && word2.size()==0) break;
        int pos = 0;
        string mut = "";
        for (int i = 0; i < word2.size() && pos < word1.size(); i++) {
            string c = string(1, word2[i]);
            if (mut.find(c) != string::npos) continue;
            int newp = word1.find(c);
            if (newp != string::npos) {
                int cc = count(word1.begin(), word1.end(), word2[i]);
                int cc2 = count(word2.begin(), word2.end(), word2[i]);
                cc = cc < cc2 ? cc : cc2;
                for (int j=0; j<cc; j++) mut.push_back(word2[i]);
            }
        }
        output += mut + "\n";
    }
    output.pop_back();
    cout << output;
    return 0;
}

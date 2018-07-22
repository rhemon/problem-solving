//
// 489 - Hangman Judge
//
//  Created by Ridhwanul Haque  on 2/19/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    vector<int> rounds;
    vector<string> results;
    int r, tries;
    size_t pos;
    string word, guess;
    while (true) {
        cin >> r;
        if (r == -1) break;
        rounds.push_back(r);
        cin >> word;
        cin >> guess;
        tries = 7;
        string q_str;
        string used_chars;
        for (char c : word) q_str.push_back('_');
        for (int i = 0; i < guess.size() && tries > 0; i++) {
            bool charFound = false;
            bool notUsed = false;
            pos = 0;
            do {
                pos = word.find(string(1, guess[i]), pos);
                if (pos != string::npos) {
                    if (!charFound) charFound = true;
                    q_str[pos] = guess[i];
                    pos++;
                }
            } while (pos != string::npos);
            if (!charFound) {
                size_t f = used_chars.find(string(1, guess[i]));
                if (f == string::npos) tries--;
                used_chars.push_back(guess[i]);
            }
        }
        string res;
        if (q_str == word) res = "You win.";
        else if (tries > 0) res = "You chickened out.";
        else res = "You lose.";
        results.push_back(res);
    }
    for (int i =0; i < results.size(); i++) {
        cout << "Round " << rounds[i] << endl;
        cout << results[i] << endl;
    }
}

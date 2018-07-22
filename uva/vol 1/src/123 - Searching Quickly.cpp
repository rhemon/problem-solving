//
// 123 - Searching Quickly
//
//  Created by Ridhwanul Haque  on 2/27/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

string to_upper(string str) {
    string res;
    for (char c : str) {
        res.push_back(toupper(c));
    }
    return res;
}

string to_lower(string str) {
    string res;
    for (char c : str) {
        res.push_back(tolower(c));
    }
    return res;
}

string till_word(string sent, int pos) {
    string res;
    for (int i = 0; i < pos; i++) res.push_back(tolower(sent[i]));
    return res;
}

string till_end(string sent, int pos) {
    string res;
    for (int i = pos; i < sent.size(); i++) res.push_back(tolower(sent[i]));
    return res;
}

int main(){
    vector<string> words_to_ignore;
    vector<string> words;
    map<string, vector<string>> words_sentence;
    string w;
    do {
        cin >> w;
        words_to_ignore.push_back(w);
    } while (w != "::");
    cin.ignore();
    while(!cin.eof()) {
        string sent;
        getline(cin, sent);
        string word;
        for (int i = 0; i < sent.size(); i++) {
            if (sent[i] != ' ' && i < sent.size()-1) word.push_back(sent[i]);
            else {
                if (i == sent.size()-1 && sent[i] != ' ') {
                    word.push_back(sent[i]);
                    i++;
                }
                int pos = i - word.size();
                word = to_lower(word);
                vector<string>::iterator it = find(words_to_ignore.begin(), words_to_ignore.end(), word);
                if (it == words_to_ignore.end()) {
                    string part1 = till_word(sent, pos);
                    string part2 = to_upper(word);
                    string part3 = till_end(sent, pos+word.size());
                    if (words_sentence.count(word) > 0) {
                        vector<string> v = words_sentence[word];
                        v.push_back(part1 + part2 + part3);
                        words_sentence[word] = v;
                    } else {
                        vector<string> p;
                        p.push_back(part1 + part2 + part3);
                        words_sentence[word] = p;
                    }
                    vector<string>::iterator vit = find(words.begin(), words.end(), word);
                    if (vit == words.end()) words.push_back(word);
                }
                word = "";
            }
        }
    }
    sort(words.begin(), words.end());
    for (string w : words) {
        vector<string> v = words_sentence[w];
        for (string s : v) {
            cout << s << endl;
        }
    }
}

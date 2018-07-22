//
// 10815 - Andy's First Dictionary
//
//  Created by Ridhwanul Haque  on 2/21/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string to_lower_str(string str){
    string res;
    for (char c : str) if (isalpha(c)) res.push_back(tolower(c));
    return res;
}


int main() {
    string s;
    vector<string> words;
    while(!cin.eof()) {
        getline(cin, s);
        if (s.size() == 0) continue;
        stringstream ss(s);
        string section;
        while (ss >> section){
            string word = "";
            for (char c : section) {
                if (isalpha(c)) word.push_back(c);
                else {
                    if (word != "") {
                        word = to_lower_str(word);
                        vector<string>::iterator it = find(words.begin(), words.end(), word);
                        if (it == words.end()) {
                            words.push_back(word);
                        }
                        word = "";
                    }
                }
            }
            if (word != "") {
                word = to_lower_str(word);
                vector<string>::iterator it = find(words.begin(), words.end(), word);
                if (it == words.end()) {
                    words.push_back(word);
                }
            }
        }
    }
    sort(words.begin(), words.end());
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << endl;
    }
    return 0;
}

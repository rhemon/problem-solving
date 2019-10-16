//
// 156 - Ananagrams
//
//  Created by Ridhwanul Haque  on 2/26/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef string str;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<int>::iterator vit;

string lowercase(string w) {
    str r;
    for (char c : w) {
        r.push_back(tolower(c));
    }
    return r;
}

int main(){
    vs words;
    str line;
    while(getline(cin, line)){
        if (line == "#") break;
        stringstream ss(line);
        str word;
        while(ss >> word) {
            words.push_back(word);
        }
    }
    vi as;
    for (str w : words) {
        int a = 0;
        for (char c : w) {
            a += tolower(c);
        }
        as.push_back(a);
    }
    vs ananagrams;
    for (int i = 0; i < as.size(); i++) {
        int c = count(as.begin(), as.end(), as[i]);
        int pos = 0;
        if (c == 1) ananagrams.push_back(words[i]);
        else {
            bool is_anagram;
            while(pos < as.size() && c > 0) {
                str w = words[i];
                string w2;
                vit it = find(as.begin()+pos, as.end(), as[i]);
                pos = it - as.begin();
                if (pos == i) {
                    pos++;
                    c--;
                    continue;
                } else w2 = words[pos];
                w = lowercase(w);
                w2 = lowercase(w2);
                is_anagram = true;
                for (char c : w) {
                    size_t p = w2.find(string(1, c));
                    if (p == str::npos) {
                        is_anagram = false;
                        break;
                    }
                }
                for (char c : w2) {
                    size_t p = w.find(string(1, c));
                    if (p == str::npos) {
                        is_anagram = false;
                        break;
                    }
                }
                if (is_anagram) break;

                pos++;
                c--;
            }
            if (!is_anagram) ananagrams.push_back(words[i]);
        }
    }
    sort(ananagrams.begin(), ananagrams.end());
    for (str w : ananagrams) {
        cout << w << endl;
    }
}

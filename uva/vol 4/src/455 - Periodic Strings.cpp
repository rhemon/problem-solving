//
// 455 - Periodic Strings
//
// Created by Ridhwanul Haque on 04/03/2018
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool ifarepeat(string str, string a) {
    string part;
    for (int i = 0; i < str.size(); i++) {
        part.push_back(str[i]);
        if (part.size() == a.size()) {
            if (part != a) return false;
            part = "";
        }
    }
    if (part.size()>0) return false;
    return true;
}
int main(){
    int t;
    cin >> t;
    string word;
    string out;
    while(t > 0) {
        cin >> word;
        int i;
        for (i = 0; i < word.size(); i++) {
            string a;
            for (int j = 0; j <= i; j++) a.push_back(word[j]);
            if (ifarepeat(word, a)) break;
        }
        out += to_string(i+1) + "\n\n";
        t--;
    }
    out.pop_back();
    cout << out;
}

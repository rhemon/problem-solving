//
// 401 - Palindromes
//
//  Created by Ridhwanul Haque  on 2/19/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverse(string word){
    string reversed_word;
    for (int i = word.size()-1; i >= 0; i--) {
        reversed_word.push_back(word[i]);
    }
    return reversed_word;
}

bool check_palindrome(string word){
    string reversed_word = reverse(word);
    if (reversed_word == word){
        return 1;
    }
    return 0;
}

bool check_mirror(string word) {
    string nonMirrorChars = "BCDFGKNPQR4679";
    string letterMirror = "E-3,J-L,L-J,S-2,Z-5,O-O";
    string digitMirror = "1-1,2-S,3-E,5-Z,8-8";
    string mirror;
    // replace 0 with O;
    size_t at = 0;
    do {
        at = word.find("0", at);
        if (at != string::npos){
            word[at] = 'O';
            at++;
        }

    } while(at != string::npos && at <word.size());
    for (char c: word) {
        size_t pos = nonMirrorChars.find(string(1,c));
        if (pos != string:: npos) return 0;
        if (isdigit(c)){
            size_t pos = digitMirror.find(string(1,c));
            if (pos == string::npos) mirror.push_back(c);
            else {
                c = digitMirror[pos+2];
                mirror.push_back(c);
            }
        } else if (isalpha(c)) {
            size_t pos = letterMirror.find(string(1,c));
            if (pos == string::npos) mirror.push_back(c);
            else {
                if (c != 'L') c = letterMirror[pos+2];
                else c = letterMirror[pos+4];
                mirror.push_back(c);
            }
        }
    }
    string reversed_word = reverse(mirror);
    return reversed_word == word;
}

int main() {
    vector<string> outputs;
    string word;
    while(getline(cin, word)) {
        if (word.size() == 0) break;
        bool palindrome = check_palindrome(word);
        bool mirror = check_mirror(word);
        if (palindrome && mirror) {
            outputs.push_back(word + " -- is a mirrored palindrome.");
        } else if (palindrome) {
            outputs.push_back(word + " -- is a regular palindrome.");
        } else if (mirror) {
            outputs.push_back(word + " -- is a mirrored string.");
        } else {
            outputs.push_back(word + " -- is not a palindrome.");
        }
    }
    for (int i = 0; i < outputs.size(); i++) {
        string out = outputs[i];
        cout << out << endl;
        cout << '\n';
    }
}

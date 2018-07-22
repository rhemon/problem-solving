//
// 10082 - WERTYU
//
// Created by Ridhwanul Haque on 07/03/2018
//

#include <iostream>

using namespace std;

int main() {
    string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    string output;
    string line;
    while (getline(cin, line)) {
        if (line.size() == 0) break;
        string decoded;
        for (char c : line) {
            if (c == ' ') decoded.push_back(' ');
            else {
                size_t pos = keyboard.find(string(1,c));
                decoded.push_back(keyboard[pos-1]);
            }
        }
        output += decoded +"\n";
    }
    cout << output;
    return 0;
}

//
// 11332 - Summing Digits
//
// Created by Ridhwanul Haque on 13/03/2018
//

#include <iostream>

using namespace std;

string sum(string num) {
    if (num.size() == 1) return num;
    int a = 0;
    for (char c : num) {
        a += atoi(&c);
    }
    return sum(to_string(a));
}

int main() {
    string t;
    string output;
    while (cin >> t) {
        if (t == "0") break;
        output += sum(t) + "\n";
    }
    cout << output;
    return 0;
}

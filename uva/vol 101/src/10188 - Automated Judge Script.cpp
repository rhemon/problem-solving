//
// 10188 - Automated Judge Script
//
// Created by Ridhwanul Haque on 17/03/2018
//

#include <iostream>

using namespace std;

int digit_match(string str1, string str2) {
    int digits1[str1.size()], digits2[str2.size()], n1 = 0, n2 = 0;
    for (char c : str1) {
        if (isdigit(c)) {
            digits1[n1] = c;
            n1++;
        }
    }
    for (char c : str2) {
        if (isdigit(c)) {
            digits2[n2] = c;
            n2++;
        }
    }
    if (n2 != n1) return 0;
    for (int i = 0; i < n2; i++) {
        if (digits1[i] != digits2[i]) return 0;
    }
    return 1;
}

int main () {
    int run = 0;
    string output;
    int jl, al, ml, which;
    string judgeline, userline;
    while (cin >> jl) {
        if (jl == 0) break;
        run++;
        cin.ignore();
        string judgeans;
        for (int i = 0; i < jl; i++) {
            getline(cin, judgeline);
            judgeans += judgeline + "\n";
        }
        cin >> al;
        cin.ignore();
        string userans;
        for (int i = 0; i < al; i++) {
            getline(cin, userline);
            userans += userline + "\n";
        }
        if (userans == judgeans) {
            output += "Run #" + to_string(run) + ": Accepted\n";
        } else if(digit_match(userans, judgeans)) {
            output += "Run #" + to_string(run) + ": Presentation Error\n";
        } else {
            output += "Run #" + to_string(run) + ": Wrong Answer\n";
        }


    }
    cout << output;
    return 0;
}

//
// 10696 - f91
//
// Created by Ridhwanul Haque on 08/03/2018
//

#include <iostream>

using namespace std;

int main() {
    int t;
    int f91,n;
    string output;
    while(cin >> n) {
        if (n == 0) break;
        if (n >= 101) f91 = n - 10;
        else f91 = 91;
        output += "f91(" + to_string(n) + ") = " + to_string(f91) +"\n";
    }
    cout << output;
    return 0;
}

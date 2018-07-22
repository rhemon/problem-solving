//
// 10783 - Odd Sum
//
// Created by Ridhwanul Haque on 07/03/2018
//

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    string output;
    for (int i = 0; i < t; i++) {
        int l, u;
        cin >> l >> u;
        if (l % 2 == 0) l++;
        int sum = 0;
        while (l <= u) {
            sum += l;
            l += 2;
        }
        output += "Case " + to_string(i+1) + ": " + to_string(sum) + "\n";
    }
    cout << output;
    return 0;
}

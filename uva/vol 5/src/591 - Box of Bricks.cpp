//
// 591 - Box of Bricks
//
// Created by Ridhwanul Haque on 07/03/2018
//

#include <iostream>

using namespace std;

int main() {
    int t;
    string output;
    int set = 1;
    while (cin >> t) {
        if (t==0) break;
        int boxes[t];
        int each = 0;
        for (int i = 0; i < t; i++) {
            int b;
            cin >> b;
            boxes[i] = b;
            each += b;
        }
        each /= t;
        int moves = 0;
        for (int b_n : boxes) {
            if (b_n > each) moves += b_n-each;
        }
        output += "Set #" + to_string(set) + "\n";
        output += "The minimum number of moves is " + to_string(moves) + ".\n\n";
        set++;
    }
    cout << output;
    return 0;
}

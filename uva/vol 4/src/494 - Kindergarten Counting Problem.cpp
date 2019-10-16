//
// 494 - Kindergarten Counting Game
//
// Created by Ridhwanul Haque on 18/02/2018
// Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> counts;
    string line;
    while (getline(cin, line)) {
        if (line.size() == 0){
            break;
        }
        int count = 0;
        bool isword = false;
        for (char c : line) {
            if (isalpha(c) && !isword) {
                isword = true;
                count++;
            }
            if ((!isalpha(c))) {
                isword = false;
            }
        }
        counts.push_back(count);
    }
    for (int count : counts) {
        cout << count << '\n';
    }

}

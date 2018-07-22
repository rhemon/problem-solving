//
// 490 - Rotating Sentences
//
// Created by Ridhwanul Haque on 18/02/2018
// Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> inputs;
    int max_size = 0;
    do {
        string inp;
        getline(cin, inp);
        if (inp.size() == 0) {
            break;
        }
        max_size = inp.size() > max_size ? inp.size() : max_size;
        inputs.push_back(inp);
    } while(true);
    vector<string> result;
    for (int i =0; i < max_size; i++) {
        string str;
        for (int j = inputs.size()-1; j >= 0; j--) {
            char c = ' ';
            if (inputs[j].size() > i) c = inputs[j][i];
            str.push_back(c);
        }
        result.push_back(str);
    }
    for (string out: result) {
        cout << out << endl;
    }
}

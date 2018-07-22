//
// 483 - Word Scramble
//
//  Created by Ridhwanul Haque  on 2/28/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string outputs;
    while(!cin.eof()) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string word;
        while (ss >> word) {
            for (int i = word.size()-1; i >= 0; i--) {
                outputs.push_back(word[i]);
            }
            outputs.push_back(' ');
        }
        outputs.pop_back();
        outputs.push_back('\n');
    }
    cout << outputs;
    return 0;
}

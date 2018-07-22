//
// 458 - The Decoder
//
//  Created by Ridhwanul Haque  on 2/16/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> strs;
    string line;
    while(getline(cin, line)) {
        if (line.size() == 0) {
            break;
        }
        string str;
        for (int i = 0; i < line.size(); i++) {
            char c = line[i]-7;
            str.push_back(c);
        }
        strs.push_back(str);
    }
    for (string out : strs) {
        cout << out << endl;
    }
}

//
// 272 - TEX Quotes
//
//  Created by Ridhwanul Haque  on 2/28/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string res;
    string line;
    int i = 1;
    while(!cin.eof()) {
        int pos;
        getline(cin, line);
        do {
            pos = line.find("\"");
            if (i == 1 && pos < line.size()) {
                line[pos] = '`';
                line.insert(pos+1, "`");
                i = -i;
            } else if (i == -1 && pos < line.size()) {
                line[pos] = '\'';
                line.insert(pos+1, "'");
                i = -i;
            }
        } while (pos != string::npos);
        res += line + "\n";
    }
    res.pop_back();
    cout << res;
}

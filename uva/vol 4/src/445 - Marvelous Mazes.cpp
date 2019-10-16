//
// 445 - Marvelous Mazes
//
//  Created by Ridhwanul Haque  on 2/16/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    bool newmaze = false;
    string out;
    string line;
    bool endofline = false;
    while(getline(cin, line)){
        if (line.size() == 0) {
            if (newmaze) break;
            newmaze = true;
        }
        if (line.size() > 0) {
            if (newmaze) out.push_back('\n');
            if (endofline) out.push_back('\n');
            newmaze = false;
            endofline = false;
        }

        int val = 0;
        bool entered = false;
        for (char c : line) {
            if (isdigit(c)){
                val += (c - '0');
            } else if (isalpha(c) || c == '*') {
                if (c == 'b') {
                    c = ' ';
                }
                while (val > 0){
                    out.push_back(c);
                    val--;
                }
            } else if (c == '!') {
                entered = true;
                if (val == 0) val = 1;
                c = '\n';
                while (val > 0){
                    out.push_back(c);
                    val--;
                }
            }
        }
        endofline = true;
    }
    if (endofline) out.push_back('\n');
    cout << out;
}

//
// 10878 - Decode the tape
//
//  Created by Ridhwanul Haque  on 2/20/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include<iostream>
#include<string>
#include <cmath>

using namespace std;

int main() {
    string output = "";
    while(true) {
        string val;
        getline(cin, val);
        if (val.size() == 0) break;
        unsigned ascii_sum = 0;
        int pos = 0;
        for (int i = val.size()-1; i>=0; i--) {
            if (val[i]=='.' || val[i]=='|') continue;
            if (val[i]=='o') ascii_sum += pow(2,pos);
            if (val[i]=='o' || val[i]==' ') pos++;
        }
        if (val[0] != '_') {
            char c = (char)ascii_sum;
            output.push_back(c);
        }
    }
    cout << output;
}

//
// 644 - Immediate Decodability
//
//  Created by Ridhwanul Haque  on 2/21/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> output;
    int i = 1;
    vector<string> bin_codes;
    bool decodable = true;
    while(!cin.eof()) {
        string code;
        getline(cin, code);
        if (code == "9") {
            if (decodable) {
                output.push_back("Set " + to_string(i) + " is immediately decodable");
            } else {
                output.push_back("Set " + to_string(i) + " is not immediately decodable");
                decodable = true;
            }
            i++;
            bin_codes.clear();
            continue;
        } else if (!decodable) continue;
        for (string val : bin_codes) {
            size_t pos = code.find(val);
            size_t pos_2 = val.find(code);
            if (pos == 0 || pos_2 == 0) {
                decodable = false;
                break;
            }
        }

        if (decodable) {
            bin_codes.push_back(code);
        }
    }
    for (string out : output) {
        cout << out << endl;
    }
}

//
// 444 - Encoder and Decoder
//
// Created by Ridhwanul Haque on 07/03/2018
//

#include <iostream>

using namespace std;

string reverse(string str) {
    string res;
    for (int i = str.size()-1; i>=0; i--) {
        res.push_back(str[i]);
    }
    return res;
}

string encode(string val) {
    string code;
    for (char c : val) {
        int c_ascii = c;
        // cout << c_ascii << endl;
        string res = reverse(to_string(c_ascii));
        // cout << res << endl;
        code = res + code;
    }
    return code;
}

string decode(string code) {
    int i = code.size()-1;
    string msg;
    while(i> 0) {
        string res;
        if (code[i] == '1') {
            for (int k = 0; k < 3; k++) {
                res.push_back(code[i-k]);
            }
            i -=3;
        } else {
            for (int k = 0; k < 2; k++) {
                res.push_back(code[i-k]);
            }
            i -= 2;
        }
        int c_ascii = atoi(res.c_str());
        char c = c_ascii;
        msg.push_back(c);
    }
    return msg;
}

int main() {
    string output;
    while (!cin.eof()) {
        string input;
        getline(cin, input);
        if (isdigit(input[0])) {
            string msg = decode(input);
            output += msg + "\n";
        } else {
            string code = encode(input);
            output += code + "\n";
        }
    }
    output.pop_back();
    cout << output;
    return 0;
}

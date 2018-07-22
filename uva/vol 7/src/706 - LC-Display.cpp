//
// 706 - LC-Display
//
// Created by Ridhwanul Haque on 09/03/2018
//

#include <iostream>

using namespace std;

string lc_num(string num_str, int s) {
    string lc_display;
    int r = 1;
    for (int j = 0; j < (2*s) + 3; j++) {
        for (int k = 0; k < num_str.size(); k++) {
            char n = num_str[k];
            switch (n) {
                case '0':
                    if (r == 1 || r == (2*s)+3) {
                        lc_display.push_back(' ');
                        for (int ii = 0; ii < s; ii++) lc_display.push_back('-');
                        lc_display.push_back(' ');
                    } else if (r == s+2) {
                        for (int ii = 0; ii < s+2; ii++) lc_display.push_back(' ');
                    } else {
                        lc_display.push_back('|');
                        for (int ii = 0; ii < s; ii++) lc_display.push_back(' ');
                        lc_display.push_back('|');
                    }
                    break;
                case '1':
                    if (r == 1 || r == s+2 || r == (2*s)+3) {
                        for (int ii = 0; ii < s+2; ii++) lc_display.push_back(' ');
                    } else {
                        for (int ii = 0; ii < s+1; ii++) lc_display.push_back(' ');
                        lc_display.push_back('|');
                    }
                    break;
                case '2':
                    if (r == 1 || r == (2*s)+3 || r == s+2) {
                        lc_display.push_back(' ');
                        for (int ii = 0; ii < s; ii++) lc_display.push_back('-');
                        lc_display.push_back(' ');
                    } else if (r < s+2){
                        for (int ii = 0; ii < s+1; ii++) lc_display.push_back(' ');
                        lc_display.push_back('|');
                    } else {
                        lc_display.push_back('|');
                        for (int ii = 0; ii < s+1; ii++) lc_display.push_back(' ');
                    }
                    break;
                case '3':
                    if (r == 1 || r == (2*s)+3 || r == s+2) {
                        lc_display.push_back(' ');
                        for (int ii = 0; ii < s; ii++) lc_display.push_back('-');
                        lc_display.push_back(' ');
                    } else {
                        for (int ii = 0; ii < s+1; ii++) lc_display.push_back(' ');
                        lc_display.push_back('|');
                    }
                    break;
                case '4':
                    if (r == 1 || r == (2*s)+3) {
                        for (int ii = 0; ii < s+2; ii++) lc_display.push_back(' ');
                    } else if (r == s+2) {
                        lc_display.push_back(' ');
                        for (int ii = 0; ii < s; ii++) lc_display.push_back('-');
                        lc_display.push_back(' ');
                    } else if (r < s+2) {
                        lc_display.push_back('|');
                        for (int ii = 0; ii < s; ii++) lc_display.push_back(' ');
                        lc_display.push_back('|');
                    } else {
                        for (int ii = 0; ii < s+1; ii++) lc_display.push_back(' ');
                        lc_display.push_back('|');
                    }
                    break;
                case '5':
                    if (r == 1 || r == (2*s)+3 || r == s+2) {
                        lc_display.push_back(' ');
                        for (int ii = 0; ii < s; ii++) lc_display.push_back('-');
                        lc_display.push_back(' ');
                    } else if (r < s+2){
                        lc_display.push_back('|');
                        for (int ii = 0; ii < s+1; ii++) lc_display.push_back(' ');
                    } else {
                        for (int ii = 0; ii < s+1; ii++) lc_display.push_back(' ');
                        lc_display.push_back('|');
                    }
                    break;
                case '6':
                    if (r == 1 || r == (2*s)+3 || r == s+2) {
                        lc_display.push_back(' ');
                        for (int ii = 0; ii < s; ii++) lc_display.push_back('-');
                        lc_display.push_back(' ');
                    } else if (r < s+2){
                        lc_display.push_back('|');
                        for (int ii = 0; ii < s+1; ii++) lc_display.push_back(' ');
                    } else {
                        lc_display.push_back('|');
                        for (int ii = 0; ii < s; ii++) lc_display.push_back(' ');
                        lc_display.push_back('|');
                    }
                    break;
                case '7':
                    if (r == 1) {
                        lc_display.push_back(' ');
                        for (int ii = 0; ii < s; ii++) lc_display.push_back('-');
                        lc_display.push_back(' ');
                    } else if (r == s+2 || r == (2*s)+3) {
                        for (int ii = 0; ii < s+2; ii++) lc_display.push_back(' ');
                    } else {
                        for (int ii = 0; ii < s+1; ii++) lc_display.push_back(' ');
                        lc_display.push_back('|');
                    }
                    break;
                case '8':
                    if (r == 1 || r == (2*s)+3 || r == s+2) {
                        lc_display.push_back(' ');
                        for (int ii = 0; ii < s; ii++) lc_display.push_back('-');
                        lc_display.push_back(' ');
                    } else {
                        lc_display.push_back('|');
                        for (int ii = 0; ii < s; ii++) lc_display.push_back(' ');
                        lc_display.push_back('|');
                    }
                    break;
                case '9':
                    if (r == 1 || r == (2*s)+3 || r == s+2) {
                        lc_display.push_back(' ');
                        for (int ii = 0; ii < s; ii++) lc_display.push_back('-');
                        lc_display.push_back(' ');
                    } else if (r < s+2) {
                        lc_display.push_back('|');
                        for (int ii = 0; ii < s; ii++) lc_display.push_back(' ');
                        lc_display.push_back('|');
                    } else {
                        for (int ii = 0; ii < s+1; ii++) lc_display.push_back(' ');
                        lc_display.push_back('|');
                    }
                    break;
            }
            if (k != num_str.size()-1) lc_display.push_back(' ');
        }
        r++;
        lc_display.push_back('\n');
    }
    return lc_display;
}

int main () {
    int s;
    string n;
    string output;
    while (cin >> s >> n) {
        if (s==0 && n == "0") break;
        string ld = lc_num(n, s);
        output += ld + "\n";
    }
    cout << output;
    return 0;
}

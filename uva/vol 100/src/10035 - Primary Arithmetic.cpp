//
// 10035 - Primary Arithmetic
//
// Created by Ridhwanul Haque on 07/03/2018
//

#include <iostream>

using namespace std;

int main() {
    string output;
    string num1, num2;
    while (cin >> num1 >> num2) {
        if (num1 == "0" && num2 == "0") break;
        int max_size = num1.size() > num2.size() ? num1.size() : num2.size();
        int carriers = 0;
        int carrying = 0;
        for (int i = 0; i < max_size; i++) {
            char n1, n2;
            int ni1 = num1.size()-1-i;
            int ni2 = num2.size()-1-i;
            if (ni1 < 0) n1 = '0';
            else n1 = num1[ni1];
            if (ni2 < 0) n2 = '0';
            else n2 = num2[ni2];
            int val = (n1 - '0') + (n2 - '0') + carrying;
            if (val > 9) {
                carriers++;
                carrying = val / 10;
            } else {
                carrying = 0;
            }
        }
        if (carriers == 0) output+= "No carry operation";
        else output += to_string(carriers) + " carry operation";
        if (carriers > 1) output += "s";
        output += ".\n";
    }
    cout << output;
    return 0;
}

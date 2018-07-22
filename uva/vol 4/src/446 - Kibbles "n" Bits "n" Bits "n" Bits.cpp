//
// 446 - Kibbles "n" Bits "n" Bits "n" Bits
//
// Created by Ridhwanul Haque 06/03/2018
//

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

unsigned Hex_to_Int(string hex) {
    int val = 0;
    for (int i = hex.size()-1, j = 0; i>= 0; i--, j++) {
        char s = hex[i];
        int num;
        if (isdigit(s)) num = atoi(&s);
        else num = 9 + (s-('A'-1));
        val += (num * pow(16, j));
    }
    return val;
}

string Int_to_Bin(unsigned num) {
    string bin = "0000000000000";
    int pos = 12;
    while (num != 0) {
        if (num % 2 == 1) bin[pos] = '1';
        num /= 2;
        pos--;
    }
    return bin;
}

int main() {
    int n;
    cin >> n;
    string output;
    while (n > 0) {
        string hex1, hex2;
        char op;
        cin >> hex1 >> op >> hex2;
        unsigned num1 = Hex_to_Int(hex1);
        unsigned num2 = Hex_to_Int(hex2);
        string bin1 = Int_to_Bin(num1);
        string bin2 = Int_to_Bin(num2);
        int res;
        if (op == '+') {
            res = num1 + num2;
        } else if (op == '-') {
            res = num1 - num2;
        }
        output += bin1 + " " + string(1, op) + " " + bin2 + " = " + to_string(res) + "\n";
        n--;
    }
    cout << output;
    return 0;
}

//
// 113 - Power of Cryptography
//
// Created by Ridhwanul Haque on 07/03/2018
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    long double power, value;
    vector<long double> bases;
    while (cin >> power >> value) {
        bases.push_back(exp(log(value)/power));
    }
    for (long double ld : bases) {
        string val = to_string(ld);
        string res;
        for (int i = 0; i < val.size(); i++) {
            if (val[i] == '.') break;
            res.push_back(val[i]);
        }
        cout << res << endl;
    }
    return 0;
}

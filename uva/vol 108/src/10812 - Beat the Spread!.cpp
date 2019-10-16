//
// 10812 - Beat the Spread!
//
// Created by Ridhwanul Haque on 16/03/2018
//

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    long long s, dd;
    string output;
    long long a,b,c,d;
    while (t > 0) {
        cin >> s >> dd;
        t--;
        if (dd > s) {
            output+= "impossible\n";
            continue;
        }
        if ((s-dd)%2 == 1) {
            output += "impossible\n";
            continue;
        }
        b = (s-dd)/2;
        a = s-b;
        c = a > b ? a : b;
        d = a < b ? a : b;
        if (a < 0 || b < 0) output+= "impossible\n";
        else output += to_string(c) + " " + to_string(d) + "\n";

    }
    cout << output;
    return 0;
}

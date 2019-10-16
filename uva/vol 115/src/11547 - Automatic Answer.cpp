//
// 11547 - Automatic Answer
//
// Created by Ridhwanul Haque on 14/03/2018
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double t;
    int n;
    cin >> n;
    string output;
    while (n > 0) {
        cin >> t;
        t = t*567;
        t = t/9;
        t = t+7492;
        t = t*235;
        t = t/47;
        t = t-498;
        n--;
        string str = to_string(int(t));
        output += string(1,str[str.size()-2]) + "\n";
    }
    cout << output;
    return 0;
}

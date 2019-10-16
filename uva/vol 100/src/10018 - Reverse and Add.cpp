//
// 10018 - Reverse and Add
//
// Created by Ridhwanul Haque on 07/03/2018
//

#include <iostream>

using namespace std;

string reverse(string str) {
    string res;
    for (int i = str.size()-1; i>=0; i--) res.push_back(str[i]);
    return res;
}

int main(){
    int t;
    cin >> t;
    string output;
    while (t > 0) {
        long long num;
        cin >> num;
        int steps = 0;
        do {
        string str = to_string(num);
        string r_str = reverse(str);
        if (str == r_str) break;
        steps++;
        num = num + atoll(r_str.c_str());
        } while (true);
        output += to_string(steps) + " " + to_string(num) + "\n";
        t--;
    }
    cout << output;
    return 0;
}

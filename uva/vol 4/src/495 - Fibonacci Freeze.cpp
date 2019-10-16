//
// 495 - Fibonacci Freeze
//
//  Created by Ridhwanul Haque  on 2/28/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, vector<string>> memory;

string reverse(string s1) {
    string r;
    for (int i = s1.size()-1; i >= 0; i--) {
        r.push_back(s1[i]);
    }
    return r;
}

string add(string s1, string s2) {
    // cout << "add call with " << s1 << " and " << s2 << endl;
    s1 = reverse(s1);
    s2 = reverse(s2);
    int on_hand = 0;
    int rem;
    int max_size = s1.size() > s2.size() ? s1.size() : s2.size();
    string res = "";
    char c1, c2;
    int p1, p2;
    for (int i = 0; i < max_size; i++) {

        c1 = i >= s1.size() ? '0' : s1[i];
        c2 = i >= s2.size() ? '0' : s2[i];
        p1 = c1 - '0';
        p2 = c2 - '0';
        int out = p1 + p2 + on_hand;
        if (out >= 10) {
            rem = out % 10;
            on_hand = out / 10;
        } else {
            on_hand = 0;
            rem = out;
        }
        res += to_string(rem);
    }
    if (on_hand > 0) {
        res += to_string(on_hand);
    }
    // cout << "res " << res << endl;
    int i;
    for (i = res.size()-1; i > 0; i--) {
        if (res[i] != '0') break;
    }
    string fin;
    for (int j = 0; j <= i; j++) {
        fin.push_back(res[j]);
    }
    return reverse(fin);
}

vector<string> fib(int k) {
    // cout << "fib call with " << k << endl;
    vector<string> r;
    if (k <= 1) {
        r.push_back(to_string(k));
        r.push_back("0");
    } else if (memory.count(k) > 0) {
        return memory[k];
    } else {
        vector<string> v = fib(k-1);
        r.push_back(add(v[0],v[1]));
        r.push_back(v[0]);
    }
    memory[k] = r;
    return r;
}

int main () {
    string res = "";
    int num;
    while (cin >> num) {
        vector<string> v = fib(num);
        string r = v[0];
        res += "The Fibonacci number for " + to_string(num) + " is " + r + "\n";
    }
    cout << res;
    return 0;
}

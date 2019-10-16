//
// 424 - Integer Inquiry
//
//  Created by Ridhwanul Haque  on 2/21/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverse(string s) {
    string r;
    for (int i = s.size()-1; i>=0; i--) {
        r.push_back(s[i]);
    }
    return r;
}

int main() {
    string s;
    vector<string> numbers;
    int max_size = 0;
    while(getline(cin, s)) {
        if (s == "0") break;
        numbers.push_back(reverse(s));
        if (s.size() > max_size) max_size = s.size();
    }
    string sum;
    int on_hand = 0;
    int rem;
    for (int index = 0; index < max_size; index++) {
        int u_sum = 0;
        for (int i = 0; i < numbers.size(); i++) {
            string num = numbers[i];
            int val;
            if (index >= num.size()) val = 0;
            else {
                string s(1, num[index]);
                val = atoi(&s[0]);
            }
            // cout << val << endl;
            u_sum += val;
        }
        u_sum += on_hand;
        if (u_sum >= 10) {
            rem = u_sum % 10;
            on_hand = u_sum/10;
        } else {
            rem = u_sum;
            on_hand = 0;
        }
        sum += to_string(rem);
    }
    if (on_hand > 0) {
        sum += reverse(to_string(on_hand));
    }
    cout << reverse(sum) << endl;
}

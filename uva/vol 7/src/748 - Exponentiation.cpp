//
// 748 - Exponentiation
//
//  Created by Ridhwanul Haque  on 2/21/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <sstream>
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

string sum_string(vector<string> to_sum, int max_size, int dot_to_enter) {
    string sum_val;
    int on_hand = 0;
    int rem = 0;
    for (int index = 0; index < max_size; index++) {
        int u_sum = 0;
        for (int i = 0; i < to_sum.size(); i++) {
            string num = to_sum[i];
            int val;
            if (index >= num.size()) val = 0;
            else {
                string s(1, num[index]);
                val = atoi(&s[0]);
            }
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
        sum_val += to_string(rem);
    }
    if (on_hand > 0) {
        sum_val += reverse(to_string(on_hand));
    }
    int i;
    bool to_trim = false;
    if (sum_val.size() > 1) {
        for (i = sum_val.size()-1; i>dot_to_enter-1; i--) {
            if (sum_val[i] == '0') to_trim = true;
            else break;
        }
        i++;
        if (to_trim) {
            int num_trim = sum_val.size()-i;
            while(num_trim > 0) {
                sum_val.pop_back();
                num_trim--;
            }
        }
    }
    return sum_val;
}

string prod_string(string num1, string num2) {
    num1 = reverse(num1);
    num2 = reverse(num2);
    vector<string> to_sum;
    int max_size = 0;
    int dot_to_enter = 0;
    bool num2_dot_added = false;
    for (int index = 0; index < num1.size(); index++) {
        if (num1[index] == '.') {
            dot_to_enter += index;
            continue;
        }
        string s(1, num1[index]);
        int val1 = atoi(&s[0]);
        string p;
        for (int j = index; j > 0; j--) {
            if (num1[j] != '.') p.push_back('0');
        }
        int on_hand = 0;
        int rem;
        for (int i = 0; i < num2.size(); i++) {
            if (num2[i] == '.') {
                if (!num2_dot_added) dot_to_enter += i;
                num2_dot_added = true;
                continue;
            }
            string s2(1, num2[i]);
            int val2 = atoi(&s2[0]);
            int x = val1 * val2;
            x += on_hand;
            if (x >= 10) {
                rem = x % 10;
                on_hand = x/10;
            } else {
                rem = x;
                on_hand = 0;
            }
            p += to_string(rem);
        }
        if (on_hand > 0) p += reverse(to_string(on_hand));
        if (p.size() > max_size) max_size = p.size();
        if (p.size() != 0) to_sum.push_back(p);
    }
    string s = sum_string(to_sum, max_size, dot_to_enter);
    if (dot_to_enter!=0) {
        s.insert(dot_to_enter, ".");
        s = reverse(s);
        bool to_trim = false;
        int i;
        for (i = s.size()-1; i > 0; i--) {
            if (s[i] == '0') to_trim = true;
            else break;
        }
        if (to_trim) {
            i++;
            int n = s.size()-i;
            while(n>0) {
                s.pop_back();
                n--;
            }
        }
    } else s = reverse(s);
    return s;
}

int main () {
    vector<string> outputs;
    while(!cin.eof()) {
        string number;
        int power;
        cin >> number >> power;
        string res = number;
        while (power > 1) {
            res = prod_string(res, number);
            power--;
        }
        res = prod_string(res, "1");
        outputs.push_back(res);
    }
    for (string out : outputs) {
        if (out.size() != 0) cout << out << endl;
    }
}

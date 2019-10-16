//
// 465 - Overflow
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

string sum_string(vector<string> to_sum, int max_size) {
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
        for (i = sum_val.size()-1; i>0; i--) {
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
    return reverse(sum_val);
}

string prod_string(string num1, string num2) {
    num1 = reverse(num1);
    num2 = reverse(num2);
    vector<string> to_sum;
    int max_size = 0;
    for (int index = 0; index < num1.size(); index++) {
        string s(1, num1[index]);
        int val1 = atoi(&s[0]);
        string p;
        for (int j = index; j > 0; j--) {
            p.push_back('0');
        }
        int on_hand = 0;
        int rem;
        for (int i = 0; i < num2.size(); i++) {
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
    return sum_string(to_sum, max_size);
}

int main() {
    vector<string> outputs;
    while(!cin.eof()) {
        string expression;
        getline(cin, expression);
        if (expression.size()==0)break;
        string snum1, snum2;
        char op;
        int inum1, inum2;
        stringstream ss(expression);
        ss >> snum1 >> op >> snum2;
        string output = expression + "\n";
        try {
            inum1 = stoi(snum1);
        } catch (...) {
            output += "first number too big\n";
        }
        try {
            inum2 = stoi(snum2);
        } catch (...) {
            output += "second number too big\n";
        }
        
        if (op == '*') {
            int prod = inum1 * inum2;
            string p = prod_string(snum1, snum2);
            if (to_string(prod) != p) {
                output += "result too big\n";
            }
        } else if (op == '+') {
            int prod = inum1 + inum2;
            vector<string> to_sum;
            to_sum.push_back(reverse(snum1));
            to_sum.push_back(reverse(snum2));
            int max_size = snum1.size() > snum2.size() ? snum1.size() : snum2.size();
            string p = sum_string(to_sum, max_size);
            if (to_string(prod) != p) {
                output += "result too big\n";
            }
        }
        outputs.push_back(output);
    }
    for(string out : outputs) {
        cout << out;
    }
}

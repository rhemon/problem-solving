//
// 673 - Parentheses Balance
//
// Created by Ridhwanul Haque on 08/03/2018
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    string output;
    string str;
    for (int i = 0; i < t; i++) {
        getline(cin, str);
        if (str.size() == 0) {
            output += "Yes\n";
            continue;
        }
        stack<char> brackets;
        bool incomp = false;
        for (char c : str) {
            if (c == '(' || c == '[') brackets.push(c);
            else if (c == ')' || c == ']'){
                if (brackets.empty()) {
                    incomp = true;
                    break;
                }
                if ((c == ')' && brackets.top()=='(') || (c == ']' && brackets.top() == '[')) {
                    brackets.pop();
                } else {
                    break;
                }
            }
        }
        if (brackets.empty() && !incomp) output += "Yes\n";
        else output += "No\n";
    }
    cout << output;
    return 0;
}

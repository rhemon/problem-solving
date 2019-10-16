//
// 414 - Machined Surfaces
//
// Created by Ridhwanul Haque on 18/02/2018
// Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int dig;
    vector<int> outs;
    while (true) {
        cin >> dig;
        if (dig == 0) {
            break;
        }
        cin.ignore();
        vector<int> no_x_vals;
        int max_x = 0;
        while (dig > 0){
            string data;
            getline(cin, data);
            int no_x = 0;
            for (int i = 0; i < data.size(); i++) {
                if (data[i] == 'X') {
                    no_x++;
                }
            }
            if (no_x > max_x) {
                max_x = no_x;
            }
            no_x_vals.push_back(no_x);
            dig--;
        }
        int spaces = 0;
        for (int val : no_x_vals) {
            spaces += (max_x - val);
        }
        outs.push_back(spaces);
    }
    for (int out : outs) {
        cout << out << endl;
    }
}

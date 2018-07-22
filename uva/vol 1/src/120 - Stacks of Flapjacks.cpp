//
// 120 - Stacks of Flapjacks
//
//  Created by Ridhwanul Haque  on 2/25/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool is_sorted(vector<int> s) {
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] > s[i+1]) {
            return false;
        }
    }
    return true;
}

vector<int> flip_stack(int n, vector<int> v) {
    vector<int> flipped;
    for (int i = n; i >=0; i--) {
        flipped.push_back(v[i]);
    }
    for (int i = n+1; i < v.size(); i++ ){
        flipped.push_back(v[i]);
    }
    return flipped;
}

void print_items(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size()-1) cout << ' ';
    }
    cout << '\n';
}

int find_max(vector<int> v, int l) {
    int i;
    int max = -1;
    int maxI;
    for (i = 0; i < l; i++) {
        if (v[i] > max) {
            max = v[i];
            maxI = i;
        }
    }
    return maxI;
}
vector<int> stack_sort(vector<int> s) {
    vector<int> flips;
    int i = 0;
    while(!is_sorted(s) && i < s.size()) {
        int pos = find_max(s, s.size()-i);
        if (pos != 0) {
            s = flip_stack(pos, s);
            flips.push_back(s.size()-pos);
        }
        s = flip_stack(s.size()-1-i, s);
        flips.push_back(i+1);
        i++;
    }
    flips.push_back(0);
    return flips;
}

int main(){
    vector<vector<int>> outputs;
    while(!cin.eof()) {
        string stack;
        getline(cin, stack);
        if (stack.size() == 0) break;
        int n;
        stringstream ss(stack);
        vector<int> s;
        while(ss >> n) {
            s.push_back(n);
        }
        outputs.push_back(s);
        vector<int> flips = stack_sort(s);
        outputs.push_back(flips);
    }
    for (vector<int> v: outputs) {
        print_items(v);
    }
}

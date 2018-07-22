//
// 103 - Stacking Boxes
//
// Created by Ridhwanul Haque on 13/03/2018
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<vector<int>, vector<vector<int>>> memory;

bool fits(vector<int> box1, vector<int> box2) {
    for (int i = 0; i < box1.size(); i++) {
        if (box1[i] <= box2[i]) return false;
    }
    return true;
}

vector<vector<int>> fit_boxes(vector<int> root_box, vector<vector<int>> remaining) {
    if (memory.count(root_box) > 0) return memory[root_box];
    vector<vector<int>> res;
    if (remaining.size() == 1) {
        if (fits(root_box, remaining[0])) res.push_back(remaining[0]);
    } else if (remaining.size() > 1){
        for (int i = remaining.size()-1; i >= 0; i--) {
            vector<int> b = remaining[i];
            if (!fits(root_box, b)) continue;
            vector<vector<int>> sub;
            sub.insert(sub.end(), remaining.begin(), remaining.begin()+i);
            vector<vector<int>> cur = fit_boxes(b, sub);
            if (cur.size() > res.size()) res = cur;
        }
    }
    res.insert(res.begin(), root_box);
    memory[root_box] = res;
    return res;
}

vector<vector<int>> chain(vector<vector<int>> boxes) {
    vector<vector<int>> max;
    for (int i = boxes.size()-1; i >= 0; i--) {
        vector<int> root_box = boxes[i];
        vector<vector<int>> remaining;
        remaining.insert(remaining.end(), boxes.begin(), boxes.begin()+i);
        vector<vector<int>> chains = fit_boxes(root_box, remaining);
        if (chains.size() >= max.size()) max = chains;
    }
    return max;
}

int main() {
    string output;
    int k, d;
    while (cin >> k >> d) {
        memory.erase(memory.begin(), memory.end());
        vector<vector<int>> boxes;
        for (int i = 0; i < k; i++) {
            vector<int> b;
            for (int j = 0; j < d; j++) {
                int x;
                cin >> x;
                b.push_back(x);
            }
            sort(b.begin(), b.end());
            boxes.push_back(b);
        }
        vector<vector<int>> copy_b = boxes;
        sort(copy_b.begin(), copy_b.end());

        vector<vector<int>> filled = chain(copy_b);
        output += to_string(filled.size()) + "\n";
        string line;
        for (int i = 0; i < filled.size(); i++) {
            vector<int> v  = filled[i];
            vector<vector<int>>::iterator it = find(boxes.begin(), boxes.end(), v);
            if (i < filled.size()-1) line = " " + to_string((it-boxes.begin())+1) + line;
            else line = to_string((it-boxes.begin())+1) + line;
        }
        output += line + "\n";
    }
    cout << output;
    return 0;
}

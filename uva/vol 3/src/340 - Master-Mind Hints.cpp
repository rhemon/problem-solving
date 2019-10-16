//
// 340 - Master-Mind Hints
//
//  Created by Ridhwanul Haque  on 2/23/18.
//  Copyright © 2018 rhemon. All rights reserved.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> gs;
typedef vector<int>::iterator vit;

vi find_hint(vi sets, vi guess) {
    int s = 0;
    int x = 0;
    vi out;
    for (int i = 0; i < sets.size(); i++){
        if (sets[i] == guess[i]) {
            s++;
            guess.at(i) = 0;
            sets.at(i) = -1;
        }
    }
    for (int i = 0; i < sets.size(); i++) {
        vit it = find(guess.begin(), guess.end(), sets[i]);
        if (it != guess.end()) {
            x++;
            guess.at(it - guess.begin()) = 0;
        }
    }
    out.push_back(s);
    out.push_back(x);
    return out;
}

int main() {
    int n;
    gs game_set;
    while(true) {
        cin >> n;
        vvi gs_hint;
        if (n == 0) {
            break;
        }
        vi set;
        for (int i = 0; i < n; i++){
            int p;
            cin >> p;
            set.push_back(p);
        }
        while (true){
            vi gues;
            bool stop =false;
            for (int i =0; i < n; i++) {
                int g;
                cin >> g;
                if (g == 0) stop = true;
                gues.push_back(g);
            }
            if (stop) break;
            vi hint = find_hint(set, gues);
            gs_hint.push_back(hint);
        }
        game_set.push_back(gs_hint);
    }

    for (int i = 0; i < game_set.size(); i++) {
        cout << "Game " << i+1 << ":" << endl;
        vvi hints = game_set[i];
        for (vi hint : hints) {
            cout << "    (" << hint[0] << "," << hint[1] << ")\n";
        }
    }
}

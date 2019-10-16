//
// 441 - Lotto
//
// Created by Ridhwanul Haque on 02/03/2018
//

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> combinations(vector<int> s, int size) {
    vector<vector<int>> combs;
    if (size == 1) {
        for (int i : s) {
            vector<int> c;
            c.push_back(i);
            combs.push_back(c);
        }
    } else {
        for (int i = 0; i < s.size(); i++) {
            vector<int> r;
            for (int j = i+1; j < s.size(); j++) r.push_back(s[j]);
            vector<vector<int>> c2 = combinations(r, size-1);
            for (vector<int> each : c2) {
                vector<int> c;
                c.push_back(s[i]);
                for (int e : each) c.push_back(e);
                combs.push_back(c);
            }
        }
    }
    return combs;
}
int main(){
    vector<vector<vector<int>>> game_sets;
    while(true) {
        int k;
        cin >> k;
        if (k==0) break;
        vector<int> s;
        int x;
        for (int i = 0; i < k; i++) {
            cin >> x;
            s.push_back(x);
        }
        vector<vector<int>> case_set;
        vector<int> initial_gs;
        for (int i = 0; i < 6; i++) initial_gs.push_back(s[i]);
        case_set.push_back(initial_gs);
        for (int i = 5; i >=0 ;i--){
            vector<int> gs = initial_gs;
            gs.erase(gs.begin()+i, gs.end());
            vector<int> u;
            for (int j = i+1; j < s.size(); j++) u.push_back(s[j]);
            int size = 6 - gs.size();
            vector<vector<int>> c = combinations(u, size);
            for (vector<int> p: c) {
                vector<int> sgs = gs;
                for (int x : p) sgs.push_back(x);
                case_set.push_back(sgs);
            }
        }
        game_sets.push_back(case_set);
    }
    for (int k = 0; k < game_sets.size(); k++) {
        vector<vector<int>> game_set = game_sets[k];
        for (vector<int> set : game_set) {
            for (int i = 0; i < 6; i++) {
                cout << set[i];
                if (i < 5) cout << ' ';
            }
            cout << '\n';
        }
        if (k != game_sets.size()-1) cout << '\n';
    }
}

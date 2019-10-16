//
// 10258 - Contest Scoreboard
//
// Created by Ridhwanul Haque on 13/03/2018
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
// #include <set>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    string line;
    getline(cin, line);
    string output;
    while (t > 0) {
        vector<vector<int>> users(101);
        vector<int> ids;
        map<int, map<int, int>> upd, upd_inc;
        while(getline(cin, line)) {
            if (line.size() == 0) break;
            stringstream ss(line);
            int id, prob, pt;
            char c;
            ss >> id >> prob >> pt >> c;
            vector<int> u = users[id];
            if (c != 'I' && c != 'C') {
                pt = 0;
            };

            int cc = count(ids.begin(), ids.end(), id);
            if (cc == 0) ids.push_back(id);
            if (u.size() == 0) {
                u.push_back(id);
                if (c == 'C') {
                    map <int, int> pd;
                    pd[prob] = pt;
                    u.push_back(1);
                    upd[id] = pd;
                } else if (c == 'I') {
                    u.push_back(0);
                    if (upd[id].count(prob) > 0) pt = 20;
                    else {
                        map <int, int> pd_i;
                        pd_i[prob] = 20;
                        pt = 0;
                        upd_inc[id] = pd_i;
                    }
                } else {
                    u.push_back(0);
                }
                u.push_back(pt);
            } else {
                if (c == 'C') {
                    map<int, int> pd;
                    if (upd.count(id) > 0) pd = upd[id];
                    if (pd.count(prob) > 0) {
                        if (pt < pd[prob]) {
                            int temp = pd[prob];
                            pd[prob] = pt;
                            pt = pt - temp;
                        } else pt = 0;
                    } else {
                        u[1] = u[1] + 1;
                        pd[prob] = pt;
                        if (upd_inc.count(id) > 0) {
                            if (upd_inc[id].count(prob) > 0) {
                                pt += upd_inc[id][prob];
                                upd_inc[id][prob] = 0;
                            }
                        }
                    }
                    upd[id] = pd;
                } else if (c == 'I') {
                    if (upd.count(id) > 0 && upd[id].count(prob) > 0) pt = 0;
                    else {
                        if (upd_inc.count(id) > 0) {
                            if (upd_inc[id].count(prob) > 0) {
                                upd_inc[id][prob] = upd_inc[id][prob] + 20;
                            } else {
                                upd_inc[id][prob] = 20;
                            }
                        } else {
                            map<int, int> pd_i;
                            pd_i[prob] = 20;
                            upd_inc[id] = pd_i;
                        }
                        pt = 0;
                    }
                } else pt = 0;
                u[2] = u[2] + pt;
            }
            users[id] = u;
        }
        vector<vector<int>> sorted(100);
        int n = 0;
        sort(ids.begin(), ids.end());
        reverse(ids.begin(), ids.end());
        for (int id : ids) {
            int i = 100;
            vector<int> u = users[id];
            vector<int> c;
            do {
                i--;
                c = sorted[i];
                if (c.size() == 0) break;
                if (c[1] < u[1]) break;
                if (c[1] == u[1]) {
                    if (c[2] >= u[2]) break;
                }
            } while (true);
            for (int k = 99-n; k <i; k++) {
                sorted[k] = sorted[k+1];
            }
            sorted[i] = u;
            n++;
        }
        for (int j = 99; j > 99-n; j--) {
            vector<int> u = sorted[j];
            output += to_string(u[0]) + " " + to_string(u[1]) + " " + to_string(u[2]) + "\n";
        }
        output += "\n";
        t--;
    }
    output.pop_back();
    cout << output;
    return 0;
}

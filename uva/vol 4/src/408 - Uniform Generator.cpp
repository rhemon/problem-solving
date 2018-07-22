//
// 408 - Uniform Generator
//
// Created by Ridhwanul Haque on 08/03/2018
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    vector<long> steps;
    vector<long> mods;
    vector<string> output;
    long s,m;
    while (cin >> s >> m) {
        vector<long> g;
        int i = 0;
        do {
            g.push_back(i);
            i =  (i + s) % m;
        } while (i != 0);
        sort(g.begin(), g.end());
        steps.push_back(s);
        mods.push_back(m);
        if (g[g.size()-1] == (m-1)) output.push_back("Good Choice");
        else output.push_back("Bad Choice");
    }
    for (int i = 0; i < output.size(); i++) {
        string s = to_string(steps[i]);
        string m = to_string(mods[i]);
        string s_g, m_g;
        for (int j = s.size(); j < 10; j++) {
            s_g.push_back(' ');
        }
        for (int j = m.size(); j < 10; j++) {
            m_g.push_back(' ');
        }
        cout << s_g << s << m_g << m << "    " << output[i] << endl;
        cout << endl;
    }
}

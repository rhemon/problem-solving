#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    string line;
    getline(cin, line);
    string output;
    for (int i = 0; i < t; i++) {
        vector<string> fragments;
        while (getline(cin, line)){
            if (line.size() == 0) break;
            fragments.push_back(line);
        }
        sort(fragments.begin(), fragments.end(), [](const string& l, const string& r) {
            return l.size() < r.size();
        });
        int maxSize = fragments[0].size() + fragments[fragments.size()-1].size();
        vector<string> solutions;
        for (int i = 0; i < fragments.size(); i++) {
            for (int j = 0; j < fragments.size(); j++) {
                if (i == j) continue;
                if (fragments[i].size() + fragments[j].size() != maxSize) continue;
                solutions.push_back(fragments[i]+fragments[j]);
            }
        }
        int mt = 0, cc;
        string soln;
        for (string str : solutions) {
            cc = count(solutions.begin(), solutions.end(), str);
            if (cc > mt) {
                mt = cc;
                soln = str;
            }
        }
        output += soln + "\n\n";

    }
    output.pop_back();
    cout << output;
    return 0;
}

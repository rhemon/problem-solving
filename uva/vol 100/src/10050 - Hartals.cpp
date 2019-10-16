//
// 10050 - Hartals
//
// Created by Ridhwanul Haque on 12/03/2018
//

#include <iostream>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    string output;
    while (t > 0) {
        int N, h;
        set<int> days;
        cin >> N >> h;
        int p, start;
        while (h > 0) {
            cin >> p;
            start = 0;
            for (int t=start+p; t <= N; t+=p) {
                // cout << " t " << t << endl;
                if (t%7 == 0 || t%7==6) continue;
                else if (days.count(t) == 0) {
                    days.insert(t);
                }
                // cout << "added" << endl;
            }
            h--;
        }
        output += to_string(days.size()) + "\n";
        t--;
    }
    cout << output;
    return 0;
}

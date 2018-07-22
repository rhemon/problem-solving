// https://codeforces.com/contest/598/problem/C

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int t;
    cin >> t;
    pair<long double, int> vecs[100001];
    long double x, y;
    for (int i = 0; i < t; i++) {
        cin >> x >> y;
        vecs[i].first= atan2(y,x);
        vecs[i].second = i+1;
    }
    sort(vecs, vecs+t);
    long double minang = 2*acos(-1) + 0.1;
    long double angle;
    int min_i, min_j;
    vecs[t] = vecs[0];
    for (int i = 1; i <= t; i++) {
        angle = vecs[i].first - vecs[i-1].first;
        angle = angle < 0 ? angle + 2*acos(-1) : angle;
        if (angle < minang) {
            minang = angle;
            min_i = vecs[i].second;
            min_j = vecs[i-1].second;
        }
    }
    cout << min_i << " " << min_j << endl;
    return 0;
}

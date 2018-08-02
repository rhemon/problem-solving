// http://codeforces.com/problemset/problem/141/A
#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    string a, b, c;
    cin >> a >> b >> c;
    sort(c.begin(), c.end());
    string d = a+b;
    sort(d.begin(), d.end());
    bool f = true;
    if (d.size() == c.size()) {
        for (int i = 0; i < d.size(); i++) {
            if (d[i] != c[i]) {
                f = false;
                break;
            }
        }
    } else {
        f = false;
    }
    if (f)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

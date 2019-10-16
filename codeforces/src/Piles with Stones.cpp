// http://codeforces.com/contest/1013/problem/A
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int t1 = 0, t2 = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        t1 += x;
    }
    for ( int i = 0; i < n; i++) {
        cin >> x;
        t2 += x;
    }
    if (t2 <= t1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
 }

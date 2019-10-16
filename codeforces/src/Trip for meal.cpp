// http://codeforces.com/problemset/problem/876/A
#include <iostream>
using namespace std;
int main() {
    int n, ro, re, oe;
    cin >> n >> ro >> re >> oe;
    if (oe < ro && oe < re && n > 1) {
        cout << min(ro, re) + oe*max(n-2,0) << endl;
    }
    else {
        cout << min(ro, re)*max(n-1,0) << endl;
    }
}

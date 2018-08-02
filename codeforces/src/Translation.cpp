// http://codeforces.com/problemset/problem/41/A
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    reverse(b.begin(), b.end());
    if (a == b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

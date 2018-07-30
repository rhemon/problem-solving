// http://codeforces.com/problemset/problem/69/A
#include <iostream>
using namespace std;
int main() {
    int n;
    int a, b, c;
    a = 0;
    b = 0;
    c = 0;
    cin >> n;
    int x, y, z;
    for (int i =0; i < n; i++) {
        cin >> x >> y >> z;
        a += x;
        b += y;
        c += z;
    }
    if (a == 0 && b == 0 && c == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

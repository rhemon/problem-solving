// http://codeforces.com/problemset/problem/467/A
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int p, q;
    int c = 0;
    for (int i = 0; i < n; i++) {
        cin >> p >> q;
        if (q-p > 1) {
            c++;
        }
    }
    cout << c << endl;
}

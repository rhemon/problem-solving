// http://codeforces.com/problemset/problem/96/A
#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    char p = '9';
    int count;
    for (char c : s) {
        if (c == p) {
            count++;
        } else {
            p = c;
            count = 1;
        }
        if (count >= 7) {
            cout << "YES" << endl;
            break;
        }
    }
    if (count < 7) cout << "NO" << endl;
}

// https://codeforces.com/contest/231/problem/A

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    int p = 0;
    int v;
    int c;
    for (int i = 0; i < t; i++) {
        c = 0;
        for (int j = 0; j < 3; j++) {
            cin >> v;
            c += v;
        }
        if (c>=2) p++;
    }
    cout << p << endl;
    return 0;
}

// http://codeforces.com/problemset/problem/615/A
#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int b[105] = {0};
    int o = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j< x; j++) {
            int f;
            cin >> f;
            if (b[f-1] == 0)
                o++;
            b[f-1] = 1;
        }
    }
    if (o == m)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}

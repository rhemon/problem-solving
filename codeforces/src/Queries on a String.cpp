// https://codeforces.com/contest/598/problem/B

#include <iostream>
using namespace std;
int main() {
    string str;
    cin >> str;
    int q, l, r, k;
    cin >> q;
    string t;
    for (int i = 0; i < q; i++) {
        cin >> l >> r >> k;
        if (r-l+1 < k) k = k%(r-l+1);
        t = str.substr(r-k, k);
        str.erase(r-k, k);
        str.insert(l-1, t);
    }
    cout << str << endl;
    return 0;
}

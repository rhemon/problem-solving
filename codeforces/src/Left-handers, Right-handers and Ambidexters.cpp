// https://codeforces.com/contest/950/problem/A

#include <iostream>
using namespace std;

int main() {
    int l, r, a;
    cin >> l >> r >> a;
    int mp = 0;
    if (a == 0) {
        if (l == r) mp = l+r;
        else{
            mp = l < r ? l*2 : r*2;
        }
    } else {
        if (l==r) {
            mp = l+r;
            if (a%2==0) mp+=a;
            else mp += a-1;
        } else if (l < r) {
            if (l+a == r) {
                mp = l+r+a;
            } else if (l+a < r) {
                mp = 2*(l+a);
            } else {
                mp = 2*r;
                if (((l+a)-r)%2 == 0) mp += ((l+a)-r);
                else mp += ((l+a)-r)-1;
            }
        } else {
            if (r+a == l) {
                mp = l+r+a;
            } else if (r+a < l) {
                mp = 2*(r+a);
            } else {
                mp = 2*l;
                if (((r+a)-l)%2 == 0) mp += ((r+a)-l);
                else mp += ((r+a)-l)-1;
            }
        }
    }
    cout << mp << endl;
    return 0;
}

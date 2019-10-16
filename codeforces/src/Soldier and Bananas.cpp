// http://codeforces.com/problemset/problem/546/A

#include <iostream>
using namespace std;
int main() {

    long long k, w, n;
    cin >> k >> w >> n;
    long long m = (n/2.0 * (2*k + (n-1) * k)) - w;
    if (m < 0) {
        m = 0;
    }
    cout << m << endl;

}

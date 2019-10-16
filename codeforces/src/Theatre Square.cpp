// https://codeforces.com/contest/1/problem/A

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double n, m, a;
    cin >> n >> m >> a;
    cout << (ceil(n/a) * ceil(m/a)) << endl;
    return 0;
}

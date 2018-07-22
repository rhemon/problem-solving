// https://codeforces.com/contest/158/problem/A

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, s;
    cin >> n >> k;
    int scores[n];
    for (int i = 0; i < n; i++) {
        cin >> s;
        scores[i] = s;
    }
    int c = 0;
    int t = scores[k-1];
    for (int i = 0; i < n; i++) {
        if (scores[i] >= t && scores[i] > 0) c++;
    }
    cout << c << endl;
    return 0;
}

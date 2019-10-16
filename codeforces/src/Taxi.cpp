// http://codeforces.com/problemset/problem/158/B
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a;
    int groups[4] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a;
        groups[a-1] += 1;
    }
    int count = groups[3];
    count += groups[2];
    groups[0] = max(groups[0]-groups[2], 0);
    count += groups[1]/2;
    if (groups[1] % 2 != 0) {
        count += 1;
        groups[1] -= (2*(groups[1]/2));
        groups[0] = max(groups[0]-(2*groups[1]), 0);
    }
    count += groups[0]/4;
    if (groups[0] % 4 != 0)
        count += 1;
    cout << count << endl;

}

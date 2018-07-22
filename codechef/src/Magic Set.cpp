// https://www.codechef.com/problems/MGCSET

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a;
        int n, m;
        int k = 0;
        cin >> n >> m;
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (a%m == 0) k++;
        }
        cout << (1 << k)-1 << endl;
    }
}

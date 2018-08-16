#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int a;
        bool y = false;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (a >= x)
                y = true;
        }
        if (y)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

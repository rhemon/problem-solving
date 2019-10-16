#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int t;
    cin >> t;
    unordered_map<int, int> pows;
    pows.reserve(32);
    for (int i = 0; i < 32; i++) {
        pows[i] = 1 << i;
    }
    while (t--) {
        int n;
        cin >> n;
        int x, y;
        x = 0;
        while (n - pows[x] > 0) {
            x++;
        }
        // cout << "x " << x << endl;
        int q = n - pows[x];
        if (q == 0) {
            if (x == 0) {
                cout << 2 << endl;
                continue;
            } else {
                cout << 1 << endl;
                continue;
            }
        }
        int p = n - pows[x-1];
        // cout << "p " << p << endl;
        if ((p & (p-1)) == 0){
            cout << 0 << endl;
            continue;
        } else {
            y = 0;
            while ((p - pows[y]) > 0) {
                y++;
            }
        }

        // cout << "p " << p << endl;
        // cout << "y " << y << endl;
        int z = p - pows[y];
        int u = p - pows[y-1];
        if (pows[y] == pows[x-1]) {
            z = u;
        } else if (pows[y-1] == pows[x-1]) {
            u = z;
        }
        // cout << "here" << endl;
        cout << min(abs(q)+1, min(abs(z), abs(u))) << endl;

    }
}

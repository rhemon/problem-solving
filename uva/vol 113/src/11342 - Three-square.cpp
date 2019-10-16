#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n > 0) {
        int x;

        n--;
        cin >> x;
        int r = sqrt(x);
        if (r*r == x) {
            cout << 0 << " " << 0 << " " << r << endl;
            continue;
        }
        if (x % 8 == '7') {
            cout << "-1" << endl;
            continue;
        }
        int i = 0, j = 0, k = 0;
        int found = 0, ai, aj, ak;
        for (i = 0; i*i<=x; i++) {
            if (found)
                break;
            for (j = 0; j*j <= x; j++) {
                if (found)
                    break;
                if ((i * i + j * j) >= x) {
                    if ((i*i + j*j) == x) {
                        ai = i;
                        aj = j;
                        ak = 0;
                        found = 1;
                    }
                    break;
                }
                int rem = x - (i*i + j*j);
                int rr = (int) sqrt((double)rem);
                if (rr* rr == rem) {
                    found = 1;
                    ai = i;
                    aj = j;
                    ak = rr;
                    break;

                }
            }
        }
        int arr[3] = {ai, aj, ak};
        sort(arr, arr+3);
        if (found) {
            cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
        } else {
            cout << "-1" << endl;
        }
    }
}

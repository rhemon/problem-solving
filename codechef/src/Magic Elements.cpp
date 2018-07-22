#include <iostream>
using namespace std;
int main() {
    int t, n,k, a;
    cin >> t;
    while (t > 0) {
        cin >> n >> k;
        int arr[n];
        int sum  = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            sum += a;
            arr[i] = a;
        }
        int valid = 0;
        for (int a : arr) {
            if (a+k > (sum-a)) valid++;
        }
        cout << valid << endl;
        t--;
    }
}

// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1428

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    int c = 1;
    while (cin >> n && n != 0) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        cin >> m;
        int q;
        cout << "Case " << c << ":" << endl;
        for (int i = 0; i < m; i++) {
            cin >> q;
            int L = 0;
            int U = n-1;
            int sum = 1e9;
            while (L < U) {
                if (arr[L] != arr[U] && abs(q - (arr[L]+arr[U])) < abs(q - sum)) {
                    sum = arr[L] + arr[U];
                }
                if (arr[L]+arr[U] == q) {
                    break;
                } else if (arr[L]+arr[U] < q) {
                    L++;
                } else {
                    U--;
                }
            }
            cout << "Closest sum to " << q << " is " << sum << "." << endl;
        }
        c++;

    }
}

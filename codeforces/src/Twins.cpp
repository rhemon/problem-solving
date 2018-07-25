// http://codeforces.com/problemset/problem/160/A

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ts = 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ts += arr[i];
    }
    sort(arr, arr+n);
    reverse(arr, arr+n);
    int s = 0;
    int i;
    for (i=0; i < n; i++) {
        s += arr[i];
        if (s> (ts-s)) {
            break;
        }
    }
    cout << i+1 << endl;
}

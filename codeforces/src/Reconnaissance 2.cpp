// http://codeforces.com/problemset/problem/34/A
#include <iostream>
#include <cmath>
using namespace std;
int main () {
    int n;
    cin >> n;
    int m = 1e9;
    int p1, p2, p;
    int arr[n];
    for (int i =0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i =0; i < n-1; i++) {
        if (abs(arr[i+1]-arr[i]) < m) {
            m = abs(arr[i+1]-arr[i]);
            p1 = i+1;
            p2 = i+2;
        }
    }
    if (abs(arr[n-1]-arr[0]) < m) {
        p1 = 1;
        p2 = n;
    }
    cout << p1 << " " << p2 << endl;
}

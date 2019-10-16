// http://codeforces.com/problemset/problem/38/A
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }
    int a, b;
    cin >> a >> b;
    int s = 0;
    for (int i = a; i < b; i++) {
        s += arr[i-1];
    }
    cout << s << endl;
}

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, k, x;
    cin >> n >> k >> x;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int t = 0;
    for (int i = 0; i < (n-k); i++) {
        t += arr[i];
    }
    t += k*x;
    cout << t << endl;
}

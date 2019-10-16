#include <iostream>
#include <algorithm>
using namespace std;
int bs(int arr[], int a, int low, int high) {
    if (arr[low] > a) {
        return 0;
    }
    if (arr[high] < a) {
        return high+1;
    }
    while (low < high) {
        int mid = (low+high)/2;
        if (arr[mid] <= a) {
            low = mid+1;
        } else {
            high = mid;
        }
    }
    if (arr[low] > a) {
        return low;
    }
    return low+1;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    int t;
    cin >> t;
    int q;
    for (int i = 0; i < t; i++) {
        cin >> q;
        cout << bs(arr, q, 0, n-1) << endl;
    }
}

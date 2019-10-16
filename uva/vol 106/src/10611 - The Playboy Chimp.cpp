#include <iostream>
using namespace std;
int bs(int arr[], int a, int low, int high) {
    if (arr[low] > a) {
        return 0;
    }
    if (arr[high] <= a) {
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
    return low;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    int j = 1;
    cin >> arr[0];
    int b;
    for (int i = 1; i < n; i++) {
        cin >> b;
        if (b != arr[j-1]) {
            arr[j] = b;
            j++;
        }
    }
    int t;
    cin >> t;
    int a;
    for (int i = 0; i < t; i++) {
        cin >> a;
        int cur =  bs(arr, a, 0, j-1)-1;
        if (cur == -1) {
            cout << "X " << arr[0] << endl;
            continue;
        }
        if (arr[cur] == a) {
            if (cur > 0) {
                cout << arr[cur-1] << " ";
            } else {
                cout << "X ";
            }
            if (cur < j-1) {
                cout << arr[cur+1] << endl;
            } else {
                cout << "X" << endl;
            }
        } else {
            if (cur >= 0) {
                cout << arr[cur] << " ";
            } else {
                cout << "X ";
            }
            if (cur < j-1) {
                cout << arr[cur+1] << endl;
            } else {
                cout << "X" << endl;
            }
        }
    }
}

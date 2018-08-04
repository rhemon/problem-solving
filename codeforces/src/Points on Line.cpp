#include <iostream>
using namespace std;

int bs(int arr[],int a, int low,int high,int d) {
    if ((arr[low]-a) > d) {
        return low-1;
    }
    if ((arr[high]-a) <= d) {
        return high;
    }
    while(low < high) {
        int mid = (low+high)/2;
        if ((arr[mid] - a) <= d) {
            low = mid+1;
        } else if ((arr[mid] - a) > d) {
            high = mid;
        }
    }
    if ((arr[low]-a) > d) {
        return low-1;
    }
    return low;
}

int main() {
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long count = 0;
    for (int i = 0; i <= n-3; i++) {
        int j = bs(arr, arr[i], i+2, n-1, d);
        long long n = (j-(i+1));
        count += (n * ((2*(n))+((n-1)*(-1))))/2;
    }
    cout << count << endl;
}

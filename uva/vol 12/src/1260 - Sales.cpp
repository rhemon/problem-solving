#include <iostream>
using namespace std;

int main() {
    int t;
    cin  >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        int x = 0;
        for (int k = 1; k < n; k++) {
            for (int j = 0; j < k; j++) {
                if (arr[j] <= arr[k]) {
                    x++;
                }
            }
        }
        cout << x << endl;
    }
}

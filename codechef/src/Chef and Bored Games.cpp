#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unsigned long long count = 0;
        for (int i = 1; i <= n; i+= 2) {
            count += ((n-(i-1))*(n-(i-1)));
        }
        cout << count << endl;
    }
}

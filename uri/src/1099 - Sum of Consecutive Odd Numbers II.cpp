#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i =0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int sum = 0;
        for (int j = min(a,b)+1; j < max(a,b); j++) {
            if (j%2==1)
                sum += j;
        }
        cout << sum << endl;
    }
}

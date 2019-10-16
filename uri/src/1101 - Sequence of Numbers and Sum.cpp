#include <iostream>
using namespace std;
int main() {
    int a, b;
    while(true) {
        cin >> a >> b;
        if (min(a,b) <= 0) {
            break;
        }
        int sum = 0;
        for (int i = min(a,b); i <= max(a,b); i++) {
            sum += i;
            cout << i << " ";
        }
        cout << "Sum=" << sum << endl;
    }
}

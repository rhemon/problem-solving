#include <iostream>
using namespace std;
int main() {
    int a, max, pos;
    max = 0;
    for (int i = 0; i < 100; i++) {
        cin >> a;
        if (a > max) {
            max = a;
            pos = i+1;
        }
    }
    cout << max << endl;
    cout << pos << endl;
}

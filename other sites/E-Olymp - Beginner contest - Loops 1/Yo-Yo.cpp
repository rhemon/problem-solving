#include <iostream>
using namespace std;
int main() {
    double l, k;
    cin >> l >> k;
    int steps = 0;

    l /= k;
    while (l > 1) {
        l /= k;
        steps++;
    }
    cout << steps << endl;
}

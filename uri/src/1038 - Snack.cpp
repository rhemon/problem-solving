#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    float price;
    if (x == 1) {
        price = 4.0 * y;
    } else if (x == 2) {
        price = 4.5 * y;
    } else if (x == 3) {
        price = 5.0 * y;
    } else if (x == 4) {
        price = 2.0 * y;
    } else if (x == 5) {
        price = 1.5 * y;
    }
    cout << fixed;
    cout << setprecision(2);
    cout << "Total: R$ " << price << endl;
}

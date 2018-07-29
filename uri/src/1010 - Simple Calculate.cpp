#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int a, b;
    float c;
    float sum = 0.0;
    for (int i = 0; i < 2; i++) {
        cin >> a >> b >> c;
        sum += (b*c);
    }
    cout << fixed;
    cout << setprecision(2);
    cout << "VALOR A PAGAR: R$ " << sum << endl;
}

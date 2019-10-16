#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float a, b, c;
    cin >> a >> b >> c;
    cout << fixed;
    cout << setprecision(1);
    if (min(a,b) + min(a, c) > max(max(a,b), c)) {
        cout << "Perimetro = " << a+b+c << endl;
    } else {
        cout << "Area = " << 1.0/2 * (a+b) * c << endl;
    }
}

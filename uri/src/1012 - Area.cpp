#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float a, b, c;
    cin >> a >> b >> c;
    cout << fixed;
    cout << setprecision(3);
    cout << "TRIANGULO: " << (1.0/2)*a*c << endl;
    cout << "CIRCULO: " << 3.14159 * c * c << endl;
    cout << "TRAPEZIO: " << (1.0/2)* (a+b) * c << endl;
    cout << "QUADRADO: " << b*b << endl;
    cout << "RETANGULO: " << a*b << endl;
}

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    float a, b, c;
    cin >> a >> b >> c;
    float x = (b*b)-(4*a*c);
    if (x < 0 || a == 0) {
        cout << "Impossivel calcular" << endl;
    } else {
        float rootA = ((-b)+sqrt(x))/(2*a);
        float rootB = ((-b)-sqrt(x))/(2*a);
        cout << fixed;
        cout << setprecision(5);
        cout << "R1 = " << rootA << endl;
        cout << "R2 = " << rootB << endl;
    }
}

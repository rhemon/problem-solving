#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float s;
    cin >> s;
    float p;
    if (s <= 400.0) {
        p = .15;
    } else if (s <= 800.0) {
        p = .12;
    } else if (s <= 1200.0) {
        p = .1;
    } else if (s <= 2000.0) {
        p = .07;
    } else {
        p = .04;
    }
    cout << fixed;
    cout << setprecision(2);
    cout << "Novo salario: " << s*(1+p) << endl;
    cout << "Reajuste ganho: " << p * s << endl;
    cout << setprecision(0);
    cout << "Em percentual: " << p * 100 << " \%" << endl;
}

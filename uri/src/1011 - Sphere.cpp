#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double r;
    cin >> r;
    cout << fixed;
    cout << setprecision(3);
    long double v = (4.0/3.0)*3.14159*(r*r*r);
    cout << "VOLUME = " << v << endl;
}

#include <iostream>
#include <iomanip>
using namespace std;

int main () {
    float a, b;
    cin >> a >> b;
    cout << fixed;
    cout << setprecision(5);
    cout << "MEDIA = " << ((3.5*a)+(7.5*b))/11 << endl;
}

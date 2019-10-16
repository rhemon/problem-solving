#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, h;
    float p;
    cin >> n >> h >> p;
    cout << "NUMBER = " << n << endl;
    cout << fixed;
    cout << setprecision(2);
    cout << "SALARY = U$ " << p * h << endl;
}

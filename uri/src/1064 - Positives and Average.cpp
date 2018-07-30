#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int count = 0;
    double a;
    double sum = 0;
    for (int i = 0; i < 6; i++) {
        cin >> a;
        if (a > 0) {
            count++;
            sum += a;
        }
    }
    cout << count << " valores positivos" << endl;
    cout << fixed;
    cout << setprecision(1);
    cout << sum/count << endl;
}

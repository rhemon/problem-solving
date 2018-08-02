#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float r = 0.0;
    float a;
    char o;
    cin >> o;
    for (int i=0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> a;
            if (j > i) {
                r += a;
            }
        }
    }
    if (o == 'M')
        r /= ((144-12)/2);
    cout << fixed;
    cout << setprecision(1);
    cout << r << endl;
}

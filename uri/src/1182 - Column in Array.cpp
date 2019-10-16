#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float r = 0.0;
    float a;
    int c;
    char o;
    cin >> c;
    cin >> o;
    for (int i=0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> a;
            if (j == c) {
                r += a;
            }
        }
    }
    if (o == 'M')
        r /= 12;
    cout << fixed;
    cout << setprecision(1);
    cout << r << endl;
}

#include <iostream>
using namespace std;
int main() {
    int lights[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> lights[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int a = 0;
            a += lights[i][j];
            if (i > 0) {
                a += lights[i-1][j];
            }
            if (i < 2) {
                a += lights[i+1][j];
            }
            if (j > 0) {
                a += lights[i][j-1];
            }
            if (j < 2) {
                a += lights[i][j+1];
            }
            cout << ((a % 2) == 0);
        }
        cout << endl;
    }
}

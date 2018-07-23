// https://www.codechef.com/COOK96B/problems/ORMATRIX

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int r, c;
        cin >> r >> c;
        char mat[r][c];
        int row[1000] = {0};
        int col[1000] = {0};
        char b;
        int zeroCounts = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> mat[i][j];
                if (mat[i][j] == '0') {
                    zeroCounts++;
                } else {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        if (zeroCounts == r*c) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    cout << "-1 ";
                }
                cout << endl;
            }
        } else {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (mat[i][j] == '1') {
                        cout << "0 ";
                    } else if (row[i] || col[j]) {
                        cout << "1 ";
                    } else {
                        cout << "2 ";
                    }
                }
                cout << endl;
            }
        }
        t--;
    }
}

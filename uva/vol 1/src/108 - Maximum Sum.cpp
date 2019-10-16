//
// 108 - Maximum Sum
//
// Created by Ridhwanul Haque on 08/03/2018
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string output;
    int n;
    while(cin >> n) {
        int vals_cc[n][n];
        int vals_cr[n][n];
        int vals[n][n];
        int k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> k;
                // cout << "i " << i << endl;
                // cout << "j " << j << endl;
                vals[i][j] = k;
                if (j == 0) vals_cc[i][j] = k;
                else vals_cc[i][j] = k + vals_cc[i][j-1];
                if (i == 0) vals_cr[i][j] = k;
                else vals_cr[i][j] = k + vals_cr[i-1][j];
            }
        }

        int max_global = vals_cc[0][0];
        for (int k = 0; k < n; k++) {
            if (k > 0) {
                for (int s = 0; s < n; s++) {
                    for (int m = k; m < n; m++) {
                        vals_cc[s][m] -= vals_cc[s][k-1];
                        vals_cr[m][s] -= vals_cr[k-1][s];
                    }
                }
            }
            int max_cur_cc, max_cur_cr;
            for (int i = 0; i < n; i++) {
                max_cur_cr = vals_cr[i][0];
                max_cur_cc = vals_cc[0][i];
                for (int j = 1; j < n; j++) {
                    max_cur_cc = max(vals_cc[j][i], vals_cc[j][i]+max_cur_cc);
                    max_cur_cr = max(vals_cr[i][j], vals_cr[i][j]+max_cur_cr);

                    max_global = max(max(max_cur_cr, max_cur_cc), max_global);
                }
            }
        }
        output += to_string(max_global) + "\n";
    }
    cout << output;
    return 0;
}

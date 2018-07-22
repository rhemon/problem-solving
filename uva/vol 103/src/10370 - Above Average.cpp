//
// 10370 - Above Average
//
// Created by Ridhwanul Haque 08/03/2018
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int t;
    cin >> t;
    double p[t];
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        double v[n];
        double avg = 0;
        for (int j = 0; j < n; j++) {
            double x;
            cin >> x;
            avg += x;
            v[j] = x;
        }
        avg /= n;
        double above = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] > avg) above++;
        }
        p[i] = (above/n)*100;
    }
    for (double per : p) {
        cout << setprecision(3) << fixed << per << "\%" << endl;
    }
    return 0;
}

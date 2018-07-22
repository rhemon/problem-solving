//
// 10137 - The Trip
//
// Created by Ridhwanul Haque on 09/03/2018
//

#include <iostream>
#include <list>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;
    list<double> outputs;
    while (cin >> n) {
        if (n == 0) break;
        double avg = 0, k, vals[n];
        for (int i = 0; i < n; i++) {
            cin >> k;
            vals[i] = k;
            avg += k;
        }
        avg /= n;
        avg = round(avg*100)/100;
        double negdiff = 0, posdiff = 0;
        for (int i = 0; i < n; i++) {
            if (vals[i] <= avg) negdiff += (avg - vals[i]);
            else posdiff += (vals[i] - avg);
        }
        outputs.push_back(min(negdiff, posdiff));
    }
    for (list<double>::iterator i = outputs.begin(); i != outputs.end(); i++) {
        cout << "$";
        cout << setprecision(2) << fixed << *i << endl;
    }
    return 0;
}

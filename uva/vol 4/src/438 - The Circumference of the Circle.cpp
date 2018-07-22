//
// 438 - The Circumference of the Circle
//
// Created by Ridhwanul Haque on 03/03/2018
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    vector<double> cs;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        double eq1_theta = (x1 * x1) - (x2 * x2) + (y1*y1)-(y2*y2);
        double eq2_theta = (x1 * x1) - (x3 * x3) + (y1*y1)-(y3*y3);
        double eq1_acoeff = (2*x1)-(2*x2);
        double eq1_bcoeff = (2*y1)-(2*y2);
        double eq2_acoeff = (2*x1)-(2*x3);
        double eq2_bcoeff = (2*y1)-(2*y3);
        double a, b;
        if (eq1_bcoeff != 0) {
            double X = eq2_theta - ((eq2_bcoeff*eq1_theta)/eq1_bcoeff);
            a = X / (eq2_acoeff - ((eq2_bcoeff*eq1_acoeff)/eq1_bcoeff));
            b = (eq1_theta - (eq1_acoeff*a))/eq1_bcoeff;
        } else {
            double X = eq1_theta - ((eq1_bcoeff*eq2_theta)/eq2_bcoeff);
            a = X / (eq1_acoeff - ((eq1_bcoeff*eq2_acoeff)/eq2_bcoeff));
            b = (eq2_theta - (eq2_acoeff*a))/eq2_bcoeff;
        }
        double r = sqrt((((x1-a)*(x1-a))+((y1-b)*(y1-b))));
        double d = 2*r;

        double pi =  3.141592653589793;
        double circ = pi*d;
        cs.push_back(circ);
    }
    for (double c : cs) {
        cout << setprecision(2) << fixed <<  c << '\n';
    }
    return 0;
}

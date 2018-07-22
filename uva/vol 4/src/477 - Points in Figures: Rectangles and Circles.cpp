//
// 477 - Points in Figures: Rectangles and Circles
//
// Created by Ridhwanul Haque on 06/03/2018
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Figure {
    char fig_type;
    vector<double> points;
protected:
    bool in_circ(double p1, double p2);
    bool in_rect(double p1, double p2);
public:
    Figure(char t, double x1, double x2, double y1, double y2);
    Figure(char t, double x1, double y1, double r);
    bool in_figure(double p1, double p2);
};

Figure::Figure(char t, double x1, double x2, double y1, double y2) {
    fig_type = t;
    double xx1, xx2, yy1, yy2;
    xx1 = x1 < x2 ? x1 : x2;
    xx2 = x2 > x1 ? x2 : x1;
    yy1 = y1 < y2 ? y1 : y2;
    yy2 = y1 > y2 ? y1 : y2;
    points.push_back(xx1);
    points.push_back(yy1);
    points.push_back(xx2);
    points.push_back(yy2);
}

Figure::Figure(char t, double x1, double y1, double r) {
    fig_type = t;
    points.push_back(x1);
    points.push_back(y1);
    points.push_back(r);
}

bool Figure::in_circ(double p1, double p2) {
    double x1, y1, r;
    x1 = points[0];
    y1 = points[1];
    r = points[2];
    double p_r = sqrt(((p1-x1)*(p1-x1))+((p2-y1)*(p2-y1)));
    if (p_r < r) return true;
    return false;
}

bool Figure::in_rect(double p1, double p2) {
    double x1, x2, y1, y2;
    x1 = points[0];
    y1 = points[1];
    x2 = points[2];
    y2 = points[3];
    if (p1 <= x1) return false;
    if (p1 >= x2) return false;
    if (p2 <= y1) return false;
    if (p2 >= y2) return false;
    return true;
}

bool Figure::in_figure(double p1, double p2) {
    if (fig_type == 'c') return in_circ(p1, p2);
    else return in_rect(p1, p2);
}

int main() {
    char type;
    vector<Figure> figures;
    while (true) {
        cin >> type;
        if (type == '*') break;
        if (type == 'r') {
            double x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            Figure r(type, x1, x2, y1, y2);
            figures.push_back(r);
        } else if (type == 'c') {
            double x1, y1, r;
            cin >> x1 >> y1 >> r;
            Figure c(type, x1, y1, r);
            figures.push_back(c);
        }
    }
    double p1, p2;
    string output;
    int point = 1;
    while (cin >> p1 >> p2) {
        if (p1 == 9999.9 && p2==9999.9) break;
        bool no_f = true;
        for (int i = 0; i < figures.size(); i++) {
            Figure f = figures[i];
            if (f.in_figure(p1, p2)) {
                output += "Point " + to_string(point) + " is contained in figure " + to_string(i+1) + "\n";
                no_f = false;
            }
        }
        if (no_f) output += "Point " + to_string(point) + " is not contained in any figure\n";
        point++;
    }
    cout << output;
}

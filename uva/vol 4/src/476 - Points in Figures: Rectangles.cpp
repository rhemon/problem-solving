//
// 476 - Points in Figures: Rectangles
//
// Created by Ridhwanul Haque on 03/03/2018
//

#include <iostream>
#include <vector>
using namespace std;

class Rectangle {
    double x1;
    double x2;
    double y1;
    double y2;
public:
    Rectangle(double xr1, double xr2, double yr1, double yr2);
    bool is_in(double x, double y);
};
Rectangle::Rectangle(double xr1, double xr2, double yr1, double yr2){
    x1 = xr1;
    x2 = xr2;
    y1 = yr1;
    y2 = yr2;
}
bool Rectangle::is_in(double x, double y) {
    if (x <= x1) return false;
    if (x >= x2) return false;
    if (y <= y1) return false;
    if (y >= y2) return false;
    return true;
}

int main() {
    char c;
    double x1, x2, y1, y2;
    vector<Rectangle> rs;
    while (cin >> c) {
        if (c == '*') break;
        cin >> x1 >> y1 >> x2 >> y2;
        double xr1 = x1 < x2 ? x1 : x2;
        double xr2 = x2 > x1 ? x2 : x1;
        double yr1 = y1 < y2 ? y1 : y2;
        double yr2 = y2 > y1 ? y2 : y1;
        Rectangle r(xr1, xr2, yr1, yr2);
        rs.push_back(r);
    }
    double x, y;
    string output;
    int point = 1;
    while (cin >> x >> y) {
        if (x == 9999.9 && y == 9999.9) break;
        bool none = true;
        int fig = 0;
        for (Rectangle r : rs) {
            fig++;
            if (!r.is_in(x,y)) continue;
            output += "Point " + to_string(point) + " is contained in figure " + to_string(fig) + "\n";
            none = false;
        }
        if (none) output += "Point " + to_string(point) + " is not contained in any figure\n";
        point++;
    }
    cout << output;
}

// https://www.urionlinejudge.com.br/judge/en/problems/view/1002

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double r;

    cout << setprecision(2);
    cin >> r;
    double area = 3.14159*(r*r);
    cout << fixed;
    cout << setprecision(4);
    cout << "A=";
    cout << area << endl;
}

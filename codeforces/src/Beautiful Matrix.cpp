// http://codeforces.com/problemset/problem/263/A
#include <iostream>
using namespace std;
int main() {
    int in1, in2, a;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a;
            if (a == 1) {
                in1 = i+1;
                in2 = j+1;
            }
        }
    }
    cout << abs(3-in1) + abs(3-in2) << endl;
}

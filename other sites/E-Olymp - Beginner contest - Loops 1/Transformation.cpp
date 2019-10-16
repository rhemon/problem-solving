#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int steps = 0;
    while (n != 1) {
        n = n%2 == 0 ? n/2 : n+1;
        steps++;
    }
    cout << steps << endl;
}

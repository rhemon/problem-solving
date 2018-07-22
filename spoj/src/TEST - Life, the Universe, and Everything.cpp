// https://www.spoj.com/problems/TEST/

#include <iostream>

using namespace std;

int main() {
    int n;
    string out;
    while (true) {
        cin >> n;
        if (n == 42) break;
        out += to_string(n) + "\n";
    }
    cout << out;
}

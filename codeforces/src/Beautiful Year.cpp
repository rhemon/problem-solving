// http://codeforces.com/problemset/problem/271/A
#include <iostream>
#include <string>
using namespace std;

bool is_distinct(int year) {
    int vals[10] = {0};
    string y = to_string(year);
    for (char c : y) {
        if (vals[c-'0'] == 1)
            return false;
        vals[c - '0'] = 1;
    }
    return true;
}

int main() {
    int year;
    cin >> year;
    year++;
    while (!is_distinct(year)) {
        year++;
    }
    cout << year << endl;
}

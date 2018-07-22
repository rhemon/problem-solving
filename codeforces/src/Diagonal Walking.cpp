// https://codeforces.com/contest/954/problem/A

#include <iostream>
using namespace std;
int main() {
    int steps, count = 0;
    cin >> steps;
    string str;
    cin >> str;
    int i, j;
    for (i =0, j = 1; i < steps-1 && j < steps;) {
        if ((str[i] == 'U' && str[j] == 'R') || (str[i] == 'R' && str[j] == 'U')) {
            i += 2;
            j += 2;
        } else {
            i++;
            j++;
        }
        count++;
    }
    if (i==steps-1 && j==steps) count++;
    cout << count << endl;
    return 0;
}

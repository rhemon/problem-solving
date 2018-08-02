// http://codeforces.com/problemset/problem/131/A
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char reverseCase(char a) {
    if (islower(a)) {
        a = toupper(a);
        return a;
    }
    a = tolower(a);
    return a;
}
int main() {
    string a;
    cin >> a;
    bool format = true;
    for (int i = 1; i < a.size(); i++) {
        if (!isupper(a[i])) {
            format = false;
            break;
        }
    }
    if (format)
        transform(a.begin(), a.end(), a.begin(), reverseCase);
    cout << a << endl;
}

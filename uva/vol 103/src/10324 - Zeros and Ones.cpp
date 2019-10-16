#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    int c = 1;
    while (true) {
        string str;
        getline(cin, str);
        if (str.empty()) break;
        int n;
        cin >> n;
        cout << "Case " << c << ":" << endl;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            char k = str[min(a,b)];
            bool s = true;
            for (int j = min(a,b)+1; j <= max(a,b); j++) {
                if (str[j] != k) {
                    s = false;
                    break;
                }
            }
            if (s) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
        c++;
        cin.ignore();
    }
}

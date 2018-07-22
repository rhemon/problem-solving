// https://www.codechef.com/COOK96B/problems/ENCMSG

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n;
        cin >> n;
        char word[n];
        char c;
        for (int i = 0; i < n; i+=2) {
            cin >> c;
            if ((i+1) == n) {
                word[i] = ('z'-(c-'a'));
                break;
            } else {
                word[i+1] = ('z'-(c-'a'));
            }
            cin >> c;
            word[i] = ('z'-(c-'a'));
        }
        for (int i = 0; i < n;i++) cout << word[i];
        cout << endl;
        t--;
    }
}

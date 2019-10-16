// http://codeforces.com/contest/80/problem/A
#include <iostream>
using namespace std;

int prime[55] = {0};
void sieve() {
    prime[1] = 1;
    for (int i = 1; i < 55; i++) {
        if (prime[i] == 0) {
            for (int j = i*2; j < 55; j+= i) {
                prime[j] = 1;
            }
        }
    }
}
void check(int n, int m) {
    for (int i=n+1; i <= m; i++) {
        if (prime[i]==0 && i == m) {
            cout << "YES" << endl;
            return;
        } else if (prime[i]==0 && i != m) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}
int main() {
    sieve();
    int n, m;
    cin >> n >> m;
    check(n, m);
}

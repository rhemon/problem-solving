#include <iostream>
using namespace std;


int memo[50];

int fib(int n) {
    if (memo[n] == -1)
        memo[n] = fib(max(n-1,0)) + fib(max(n-2,0));
    return memo[n];
}

int main() {
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i < 50; i++) {
        memo[i] = -1;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << fib(i);
        if (i < n-1)
            cout << " ";
    }
    cout << endl;
}

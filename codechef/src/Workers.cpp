#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int costs[N];
    int m1 = 1000004, m2 = 1000004, m3 = 1000004;
    int n;
    for (int i = 0; i < N; i++) cin >> costs[i];
    for (int i = 0; i < N; i++) {
        cin >> n;
        if (n==1) {
            if (costs[i] < m1) m1 = costs[i];
        }
        if (n==2) {
            if (costs[i] < m2) m2 = costs[i];
        }
        if (n==3) {
            if (costs[i] < m3) m3 = costs[i];
        }
    }
    if ((m1+m2) < m3) cout << m1+m2 << endl;
    else cout << m3 << endl;
    return 0;
}

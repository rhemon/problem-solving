// https://codeforces.com/contest/950/problem/B

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    int l, q;
    for (int i = 0; i < n; i++) {
        cin >> l;
        a[i] = l;
    }
    for (int i = 0; i < m; i++) {
        cin >> q;
        b[i] = q;
    }
    int count = 0;
    int suma = a[0], sumb = b[0];
    for (int i = 1, j = 1; (i < n || j < m);){
         if (suma == sumb) {
             count++;
             suma = a[i];
             sumb = b[j];
             i++;
             j++;
         } else if (suma > sumb) {
             sumb += b[j];
             j++;
         } else if (suma < sumb) {
             suma += a[i];
             i++;
         }
    }
    if (suma == sumb) count++;
    cout << count << endl;
    return 0;
}

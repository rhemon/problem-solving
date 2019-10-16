#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int x =  n-(i*a + b*j);
            if (x < 0 || x % c != 0) continue;
            ans = max(ans, i+j+(x/c));
        }
    }
    cout << ans << endl;
}

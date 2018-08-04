#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> cnt;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if(cnt.find(a) == cnt.end()) {
            cnt[a] = 1;
        } else {
            cnt[a] += 1;
        }
    }
    map<int, int>::iterator it;
    long long count = 0;
    for (it=cnt.begin(); it != cnt.end(); it++) {
        int cur = it->first;
        long long q = it->second;
        // cout << q << endl;
        // cout
        for (int i = 1; i < 32; i++) {
            int p2 = 1 << i;
            // cout << p2 << endl;
            if (cnt.find(abs(p2-cur)) != cnt.end()) {
                if (p2 - cur == cur) {
                    long long n = q-1;
                    count += (n*(n+1))/2;
                } else {
                    count += q * cnt.at(abs(p2-cur));
                }
            }
        }
        it->second = 0;
    }
    cout << count << endl;
}

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    unordered_map<int, int> Y;
    Y.reserve(4000*4000);
    int n;
    cin >> n;
    int A[n], B[n], C[n], D[n];
    for(int i = 0;i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Y[C[i]+D[j]]++;
        }
    }
    int count = 0;
    for (int i =0; i <n; i++) {
        for (int j = 0; j< n; j++) {
            int t = -(A[i] + B[j]);
            if (Y.find(t) != Y.end()) {
                count += Y[t];
            }
        }
    }
    cout << count << endl;

}

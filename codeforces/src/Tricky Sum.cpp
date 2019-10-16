// https://codeforces.com/contest/598/problem/A

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    long long n;
    cin >> t;
    long long output[t];
    for (int i = 0; i < t; i++) {
        cin >> n;
        long long apsum = ((n*(2+(n-1)))/2);
        long long e = floor(log2(n));
        long long gpsum = (pow(2,e+1) - 1);
        output[i] = apsum - (2*gpsum);
     }
     for (long long d : output) {
         cout << d << endl;
     }
    return 0;
}

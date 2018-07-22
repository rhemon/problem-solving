// https://codeforces.com/contest/1006/problem/A

#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	string a = "";

	for (int i  = 0; i < t; i++) {
		long long x;
		cin >> x;
//		cout << x - !(x & 1) << " ";
		if (x%2 == 0) {
			a += to_string(x-1);
		} else {
			a += to_string(x);
		}
		if (i != t-1) {
			a += " ";
		}
	}
	cout << a << endl;
	return 0;
}

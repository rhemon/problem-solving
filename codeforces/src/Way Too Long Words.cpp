// https://codeforces.com/contest/71/problem/A

#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    string output, in;
    for (int i = 0; i < t; i++) {
        cin >> in;
        if (in.size() <= 10) output+= in +"\n";
        else {
            output += string(1,in[0]) + to_string(in.size()-2) + string(1,in[in.size()-1]) + "\n";
        }
    }
    cout << output;
    return 0;
}

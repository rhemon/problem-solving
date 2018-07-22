// https://www.spoj.com/problems/ADDREV/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n > 0) {
        string a, b;
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int ia = stoi(a);
        int ib = stoi(b);
        int ans = ia + ib;
        string answer = to_string(ans);
        reverse(answer.begin(), answer.end());
        int i = 0;
        for (;i<answer.size();i++) {
            if (answer[i] == '0') continue;
            else break;
        }
        if (i == answer.size()) { cout << 0 << endl; }
        else {
            for(int j = i; j < answer.size(); j++) {
                cout << answer[j];
            }
            cout << endl;
        }
        n--;
    }

}

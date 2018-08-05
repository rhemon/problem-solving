#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    cin.ignore();
    int c = 1;
    while (t>0) {
        t--;
        string str;
        getline(cin, str);
        int cnt = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '1')
                cnt += 2;
            else
                cnt -= 1;
            if (cnt < 0)
                break;
        }
        cout << "Case " << c;
        if (cnt == 0)
            cout << ": yes" << endl;
        else
            cout << ": no" << endl;
        c++;
    }
}

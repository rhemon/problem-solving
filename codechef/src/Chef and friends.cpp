#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int count = 0;
    int t;
    cin >> t;
    string name;
    while (t>0) {
        cin >> name;
        t--;
        if (name.find("ch") != string::npos) {
            count++;
            continue;
        }
        if (name.find("he") != string::npos) {
            count++;
            continue;
        }
        if (name.find("ef") != string::npos) {
            count++;
            continue;
        }

    }
    cout << count << endl;
    return 0;
}

// https://www.codechef.com/AUG18B/problems/SPELLBOB
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        int b=0, o=0, ob=0;
        for (int i = 0; i<3;i++) {
            if ((s1[i] == 'b' && s2[i] == 'o') || (s1[i] == 'o' && s2[i] == 'b')) {
                ob++;
            } else if (s1[i]=='b'||s2[i]=='b') {
                b++;
            } else if (s1[i]=='o' || s2[i] == 'o') {
                o++;
            }
        }
        if (ob == 3 || (ob == 2 && (o == 1 || b == 1)) || (b==2 && o==1) || (ob==1 && ((o==1 && b==1) || b==2))) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}

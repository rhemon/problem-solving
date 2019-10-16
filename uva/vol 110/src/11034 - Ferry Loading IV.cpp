#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n > 0) {
        n--;
        int l, m;
        cin >> l >> m;
        queue<int> LEFT, RIGHT;
        string side;
        int length;
        for (int i = 0; i < m; i++) {
            cin >> length >> side;
            if (side == "left") {
                RIGHT.push(length);
            } else {
                LEFT.push(length);
            }
        }
        string cur = "left";
        int carrying;
        int cross = 0;
        while (!LEFT.empty() || !RIGHT.empty()) {
            carrying = 0;
            if (cur == "left" ) {
                if (!RIGHT.empty()) {
                    while (RIGHT.front()+carrying < (l*100)) {
                        carrying += RIGHT.front();
                        RIGHT.pop();
                        if (RIGHT.empty())
                            break;
                    }
                }
                // cout << "carrying to right " << carrying << endl;
                cur = "right";
            } else {
                if (!LEFT.empty()) {
                    while (LEFT.front()+carrying < (l*100)) {
                        carrying += LEFT.front();
                        LEFT.pop();
                        if (LEFT.empty())
                            break;
                    }
                }
                // cout << "carrying to left " << carrying << endl;
                cur = "left";
            }
            cross++;
        }
        cout << cross << endl;
    }
}

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << "Lumberjacks:" << endl;
    for (int i = 0; i < n; i++) {
        int px, x;
        bool g, l;
        cin >> px;
        cin >> x;
        if (x > px) {
            g = true;
            l = false;
        } else {
            g = false;
            l = true;
        }
        px = x;
        for (int j = 2; j < 10; j++) {
            cin >> x;
            if (x < px && g) {
                g = false;
            }
            if (x > px && l) {
                l = false;
            }
            px = x;
        }
        if (g || l) {
            cout << "Ordered" << endl;
        } else {
            cout << "Unordered" << endl;
        }
    }
}

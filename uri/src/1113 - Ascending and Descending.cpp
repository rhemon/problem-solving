#include <iostream>
using namespace std;
int main() {
    while (true) {
        int a, b;
        cin >> a >> b;
        if ( a > b) {
            cout << "Decrescente" << endl;
        } else if ( a < b) {
            cout << "Crescente" << endl;
        } else {
            break;
        }
    }
}

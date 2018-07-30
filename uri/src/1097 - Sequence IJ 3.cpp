#include <iostream>
using namespace std;
int main() {
    int j=7;
    for (int i = 1; i < 10; i+=2) {
        for (int k=j; k > (j-3); k--) {
            cout << "I=" << i << " J=" << k << endl;
        }
        j += 2;
    }
}

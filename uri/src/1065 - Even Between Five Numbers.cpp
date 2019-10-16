#include <iostream>
using namespace std;
int main() {
    int a;
    int count = 0;
    for (int i = 0; i < 5; i++){
        cin >> a;
        if (a%2 == 0)
            count++;
    }
    cout << count << " valores pares" << endl;
}

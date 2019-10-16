#include <iostream>
using namespace std;
int main() {
    int a;
    int pc = 0, nc = 0, oc = 0, ec = 0;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        if (a > 0)
            pc++;
        if (a < 0)
            nc++;
        if (a % 2 == 0)
            ec++;
        else
            oc++;
    }
    cout << ec << " valor(es) par(es)" << endl;
    cout << oc << " valor(es) impar(es)" << endl;
    cout << pc << " valor(es) positivo(s)" << endl;
    cout << nc << " valor(es) negativo(s)" << endl;
}

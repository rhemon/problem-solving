#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n;
    cin >> n;
    float c = 0;
    float r = 0;
    float s = 0;
    int q;
    char type;
    for (int i = 0; i < n; i++) {
        cin >> q >> type;
        if (type == 'C')
            c += q;
        if (type == 'R')
            r += q;
        if (type == 'S')
            s += q;
    }
    cout << "Total: " << c+r+s << " cobaias" << endl;
    cout << "Total de coelhos: " << c << endl;
    cout << "Total de ratos: " << r << endl;
    cout << "Total de sapos: " << s << endl;
    cout << fixed;
    cout << setprecision(2);
    cout << "Percentual de coelhos: " << (c/(c+r+s))*100 << " \%" << endl;
    cout << "Percentual de ratos: " << (r/(r+c+s))* 100 << " \%" << endl;
    cout << "Percentual de sapos: " << (s/(r+c+s)) * 100 << " \%" << endl;
}

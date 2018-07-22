#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    int a, b, c;
    int steps;
    int midway, bma, cmb;
    while (t > 0) {
        t--;
        cin >> a >> b >> c;
        midway = ((b-a)+(c-b))/2;
        steps = min(abs((b-a)-midway), abs((c-b)-midway));
        bma = b-a;
        cmb = c-b;
        int extra = 0;
        if (bma > midway) bma -= steps;
        else if (bma < midway) bma += steps;
        if (cmb > midway) cmb -= steps;
        else if (cmb < midway) cmb += steps;
        extra += abs(midway - bma) + abs(midway - cmb);
        steps += extra;
        cout << steps << endl;
    }
    return 0;
}

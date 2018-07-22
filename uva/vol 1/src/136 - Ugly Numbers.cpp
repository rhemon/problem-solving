//
// 136 - Ugly Numbers
//
// Created by Ridhwanul Haque on 07/03/2018
//

#include <iostream>


using namespace std;

long long UN[1500];

void generateUN(void) {
    UN[0] = 1;
    int t2 = 0, t3 = 0, t5 = 0;
    for (int i = 1; i < 1500; i++) {
        UN[i] = min(min(UN[t2]*2, UN[t3]*3), UN[t5]*5);
        if (UN[i] == 2*UN[t2]) t2++;
        if (UN[i] == 3*UN[t3]) t3++;
        if (UN[i] == 5*UN[t5]) t5++;
    }
}

int main() {
    generateUN();
    cout << "The 1500'th ugly number is " << UN[1499] << ".\n";
    return 0;
}

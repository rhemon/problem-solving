// https://www.spoj.com/problems/DIVSUM/

#include <iostream>
using namespace std;

unsigned long long divsum(unsigned int num) {
    if (num == 1) return 0;
    unsigned long long sum = 1;
    for (unsigned int i = 2; i <= num/2; i++) {
        if (num % i == 0) sum += i;
    }
    return sum;
}

int main() {
    int cases;
    cin >> cases;
    string output;
    unsigned int num;
    while (cases > 0) {
        cin >> num;
        output += to_string(divsum(num)) + "\n";
        cases--;
    }
    cout << output;
}

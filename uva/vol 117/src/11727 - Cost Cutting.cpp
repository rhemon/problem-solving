//
// 11727 - Cost Cutting
//
// Created by Ridhwanul Haque on 07/03/2018
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    string output;
    for (int i = 0; i < t; i++) {
        int salaries[3];
        for (int j = 0; j< 3; j++) {
            int sal;
            cin >> sal;
            salaries[j] = sal;
        }
        sort(salaries, salaries+3);
        output += "Case " + to_string(i+1) + ": " + to_string(salaries[1]) +"\n";
    }
    cout << output;
    return 0;
}

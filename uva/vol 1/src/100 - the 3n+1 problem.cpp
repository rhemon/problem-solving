//  100 - 3n + 1 Problem Solution
//
//  Created by Ridhwanul Haque  on 2/8/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    unsigned int i, j, i2, k, n, cycle, max_cycle;
    while (cin >> i >> j){


        if (j<i) {
            k = i;
            i2 = j;
        } else {
            k = j;
            i2 = i;
        }

        cycle = 0;
        max_cycle = 0;
        while (k >= i2) {
            n = k;
            while (n != 1) {
                cycle++;
                if (n % 2 == 0) {
                    n /= 2;
                } else if (n != 1) {
                    n = (3*n) + 1;
                }
            };
            cycle++;
            if (cycle >= max_cycle) {
                max_cycle = cycle;
            }
            cycle = 0;
            k--;
        }
        cout << i << ' ' << j << ' ' << max_cycle << '\n';
    }


    return 0;
}

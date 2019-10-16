//
// 299 - Train Swapping
//
//  Created by Ridhwanul Haque  on 2/25/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    int swaps[cases];
    for (int k = 0; k < cases; k++) {
        int n;
        cin >> n;
        int v[n];
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            int j = i-1;
            int t = v[i];
            while(j>=0 && v[j]>t) {
                s++;
                v[j+1] = v[j];
                j--;
            }
            v[j+1] = t;
        }
        swaps[k] = s;
    }
    for (int i = 0; i < cases; i++) {
        cout << "Optimal train swapping takes " << swaps[i] << " swaps.\n";
    }
}

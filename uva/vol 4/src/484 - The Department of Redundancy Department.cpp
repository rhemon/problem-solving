//
// 484 - The Department of Redundancy Department
//
//  Created by Ridhwanul Haque  on 3/1/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
    map<int, int> num_count;
    vector<int> keys;
    int n;
    while (cin >> n) {
        vector<int>::iterator it = find(keys.begin(), keys.end(), n);
        if (it == keys.end()) {
            num_count[n] = 1;
            keys.push_back(n);
        } else {
            num_count[n] += 1;
        }
    }
    for (int n : keys) {
        cout << n << " " << num_count[n] << "\n";
    }
}

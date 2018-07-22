//
// 10300 - Ecological Problem
//
//  Created by Ridhwanul Haque  on 2/16/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


int main() {
    int num_test_case;
    vector<int> res;
    cin >> num_test_case;
    while (num_test_case > 0) {
        int num_farmes;
        cin >> num_farmes;
        float mon = 0.0;
        while (num_farmes > 0) {
            int sqr, ani, frn;
            cin >> sqr >> ani >> frn;
            mon += (float(sqr)/float(ani)) * float(frn) * float(ani);
            num_farmes--;
        }
        res.push_back(int(mon));
        num_test_case--;
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << '\n';
    }
}

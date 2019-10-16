//
// 694 - The Collatz Sequence
//
//  Created by Ridhwanul Haque  on 2/19/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    vector<long> cases, nums, limits, terms;
    long case_num = 0;
    long num, limit, term;
    while (cin >> num >> limit) {
        if (num < 0 && limit < 0) break;
        case_num++;
        cases.push_back(case_num);
        nums.push_back(num);
        limits.push_back(limit);
        term = 1;
        do {
            if (num%2==0) num /= 2;
            else num = (3*num)+1;
            if (num <= limit) term++;
        } while (num <= limit && num != 1);
        terms.push_back(term);
    }
    for (int i =0; i < cases.size(); i++) {
        cout << "Case " << cases[i] << ": A = " << nums[i] << ", limit = " << limits[i] << ", number of terms = " << terms[i] << endl;
    }
}

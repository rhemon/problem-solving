//
// 10038 - Jolly Jumpers
//
//  Created by Ridhwanul Haque  on 2/28/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> res;
    while(!cin.eof()) {
        int nums;
        cin >> nums;
        string jolly = "Jolly";
        vector<int> diffs;
        int diff, now, prev;
        for (int i = 0; i < nums; i++) {
            if (i==0) cin >> prev;
            else {
                cin >> now;
                diff = prev > now ? prev - now : now - prev;
                prev = now;
                diffs.push_back(diff);
            }
        }
        sort(diffs.begin(), diffs.end());
        if (nums > 1) {
            if (diffs[0] == 1 && diffs[diffs.size()-1] == nums-1) {
                for (int i = 1; i < diffs.size(); i++) {
                    if (diffs[i] == diffs[i-1]){
                        jolly = "Not jolly";
                        break;
                    }
                }
            } else jolly = "Not jolly";
        }
        res.push_back(jolly);
    }
    for (int i = 0; i < res.size()-1; i++) {
        cout << res[i] << endl;
    }
    return 0;
}

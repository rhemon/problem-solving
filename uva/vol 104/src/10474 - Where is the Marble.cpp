//
// 10474 - Where is the Marble?
//
//  Created by Ridhwanul Haque  on 2/24/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int num, que;
    cin >> num >> que;
    vector<string> outputs;
    int c = 1;
    while(num != 0 && que != 0) {
        vector<int> values;
        while(num > 0) {
            int i;
            cin >> i;
            values.push_back(i);
            num--;
        }
        sort(values.begin(), values.end());
        string out = "CASE# " + to_string(c) + ":\n";
        while (que > 0) {
            int q;
            cin >> q;
            vector<int>::iterator it = find(values.begin(), values.end(), q);
            if (it != values.end()){
                int pos = it - values.begin();
                out += to_string(q) + " found at " + to_string(pos+1) + "\n";
            } else {
                out += to_string(q) + " not found\n";
            }
            que--;
        }
        outputs.push_back(out);
        c++;
        cin >> num >> que;
    }
    for (string out : outputs) {
        cout << out;
    }
}

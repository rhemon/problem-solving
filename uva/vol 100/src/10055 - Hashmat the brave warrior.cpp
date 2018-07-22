// 10055 - Hashmat the Brave Warrior
//
//  Created by Ridhwanul Haque  on 2/8/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    unsigned long i, j;
    vector<unsigned long> ans;
    string line;
    do {
        getline(cin, line);
        stringstream ss(line);
        if (line.size() == 0) break;
        ss >> i >> j;
        unsigned long k = (j < i) ? i-j : j-i;
        ans.push_back(k);
    } while (true);
    for (int l = 0; l<ans.size(); l++){
        cout << ans[l] << '\n';
    }
}

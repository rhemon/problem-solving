//
// 10071 - Back to High School Physics
//
//  Created by Ridhwanul Haque  on 2/16/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<long> outputs;
    string line;
    long double s, v, t;
    while (getline(cin, line)) {
        if (line.size() == 0) {
            break;
        }
        stringstream ss(line);
        ss >> v >> t;
        if (t != 0 && v != 0) s = (((v/t) * 2 * t)*((v/t)* 2 * t))/(2*(v/t));
        else s = 0.0;
        outputs.push_back(long(round(s)));
    }
    for (long out : outputs) {
        cout << out << endl;
    }
}

//
// 11172 - Relational Operator
//
//  Created by Ridhwanul Haque  on 2/28/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string res;
    while(n > 0) {
        int x, y;
        cin >> x >> y;
        if (x < y) res.push_back('<');
        else if (x > y) res.push_back('>');
        else res.push_back('=');
        res.push_back('\n');
        n--;
    }
    cout << res;
}

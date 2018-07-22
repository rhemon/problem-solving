//
// 10420 - List of Conquests
//
//  Created by Ridhwanul Haque  on 2/24/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef map<string, int> msi;
typedef map<string, vector<string>> msv;
typedef vector<string> vs;
typedef vector<string>::iterator vit;
typedef map<string, int>::iterator mit;

int main() {
    int num;
    cin >> num;
    msi cb;
    msv cbd;
    cin.ignore();
    vs cn;
    while (num > 0) {
        num--;
        string line;
        getline(cin, line);
        stringstream ss(line);
        string country;
        ss >> country;
        string name = "";
        string word;
        while (ss >> word) {
            name += word + " ";
        }
        if (cb.count(country) > 0){
            vs names = cbd[country];
            vit it = find(names.begin(), names.end(), name);
            if (it == names.end()) {
                names.push_back(name);
                cb[country] += 1;
            }

        } else {
            cb[country] = 1;
            vs names;
            names.push_back(name);
            cbd[country] = names;
        }
        vit it = find(cn.begin(), cn.end(), country);
        if (it == cn.end()) {
            cn.push_back(country);
        }
    }
    sort(cn.begin(), cn.end());
    for (string c : cn) {
        cout << c << " " << cb[c] << endl;
    }
    return 0;
}

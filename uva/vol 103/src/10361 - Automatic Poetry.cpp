//
// 10361 - Automatic Poetry
//
//  Created by Ridhwanul Haque  on 2/20/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {

    int num_cases;
    vector<string> poetry;
    cin >> num_cases;
    cin.ignore();
    while (num_cases > 0) {
        string first, second;
        getline(cin, first);
        getline(cin, second);

        size_t start_fb = 0;
        size_t start_cb = 0;
        vector<size_t> fbs, cbs;
        do {
            size_t first_brack = first.find("<", start_fb);
            size_t close_brack = first.find(">", start_cb);
            if (first_brack == string::npos || close_brack == string::npos) {
                break;
            }
            start_fb = first_brack+1;
            start_cb = close_brack+1;
            fbs.push_back(first_brack);
            cbs.push_back(close_brack);
        } while(true);

        string line2;
        size_t dot = second.find(".");
        for (int i = 0; i < dot; i++) {
            line2.push_back(second[i]);
        }
        for (int i = fbs[1]+1; i < cbs[1]; i++) {
            line2.push_back(first[i]);
        }
        for (int i = cbs[0]+1; i<fbs[1]; i++) {
            line2.push_back(first[i]);
        }
        for (int i = fbs[0]+1; i < cbs[0]; i++) {
            line2.push_back(first[i]);
        }
        for (int i = cbs[1]+1; i < first.size(); i++) {
            line2.push_back(first[i]);
        }

        string line1;
        for (size_t i = 0; i < first.size(); i++) {
            if (i != fbs[0] && i != fbs[1] && i != cbs[0] && i != cbs[1]) {
                line1.push_back(first[i]);
            }
        }
        poetry.push_back(line1);
        poetry.push_back(line2);
        num_cases--;
    }
    for (string line : poetry) {
        cout << line << endl;
    }
}

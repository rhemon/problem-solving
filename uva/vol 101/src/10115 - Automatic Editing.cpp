//
// 10115 - Automatic Editing
//
//  Created by Ridhwanul Haque  on 2/21/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int num;
    vector<string> output;
    while(cin >> num) {
        if (num == 0) break;
        vector<string> find;
        // cout << "here" << endl;
        vector<string> replace_by;
        cin.ignore();
        while (num > 0) {
            string f, r;
            getline(cin, f);
            getline(cin, r);
            find.push_back(f);
            replace_by.push_back(r);
            num--;
        }
        string text;
        getline(cin, text);
        for (int i = 0; i < find.size(); i++) {
            string f = find[i];
            string r = replace_by[i];
            while(true) {
                size_t pos = text.find(f);
                if (pos != string::npos) {
                    text.erase(pos, f.size());
                    text.insert(pos, r);
                } else {
                    break;
                }
            }
        }
        output.push_back(text);
    }
    for (string out : output) {
        cout << out << endl;
    }
}

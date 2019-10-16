//
// 400 - Unix ls
//
//  Created by Ridhwanul Haque  on 2/26/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> outputs;
    string output;
    int num_columns, rows, max_size;
    string n;
    while (!cin.eof()) {
        int names;
        cin >> names;
        max_size = 0;
        vector<string> fnames;
        for (int i = 0; i < names; i++) {
            cin >> n;
            if (n.size() > max_size) max_size = n.size();
            fnames.push_back(n);
        }
        num_columns = (int) (60/(max_size+2));
        if (num_columns == 0) num_columns = 1;
        rows = (int) (names / num_columns);
        if (rows * num_columns < names) rows++;
        sort(fnames.begin(), fnames.end());
        output = "";
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < num_columns; c++) {
                if (rows*c + r >= fnames.size()) continue;
                string word = fnames[rows*c + r];
                string gap = "";
                int ms = max_size+2;
                if (c == num_columns-1) ms = max_size;
                for (int i = word.size(); i < ms; i++) gap += " ";
                output += word + gap;
            }
            output += "\n";
        }
        outputs.push_back(output);
    }
    for (string out : outputs) {
        for (int i = 0; i < 60; i++) cout << "-";
        cout << "\n";
        cout << out;
    }
    return 0;
}

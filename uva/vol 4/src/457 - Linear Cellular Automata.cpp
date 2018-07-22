//
// 457 - Linear Cellular Automata
//
//  Created by Ridhwanul Haque  on 2/19/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int dna_val(char c) {
    switch(c){
        case ' ':
            return 0;
        case '.':
            return 1;
        case 'x':
            return 2;
        case 'W':
            return 3;
        default:
            return 0;
    }
}

string get_start_dna(){
    string res;
    for (int i =0; i<40; i++){
        if (i == 19) {
            res.push_back('.');
        } else {
            res.push_back(' ');
        }
    }
    return res;
}

char val_dna(int num) {
    switch(num) {
        case 0:
            return ' ';
        case 1:
            return '.';
        case 2:
            return 'x';
        case 3:
            return 'W';
        default:
            return ' ';
    }
}
int main() {
    int num_cases;
    cin >> num_cases;
    vector<vector<string>> dna_cases;
    while(num_cases>0){
        string start_dna = get_start_dna();
        vector<int> dna;
        vector<string> dna_lines;
        int dna_det;
        for (int i =0; i<10; i++) {
            cin >> dna_det;
            dna.push_back(dna_det);
        }
        dna_lines.push_back(start_dna);
        for (int i =1; i < 50; i++) {
            string prev_dna = dna_lines[i-1];
            string new_dna;
            int val_r, val_l, val_c, k;
            for (int j = 0; j < prev_dna.size(); j++) {
                if (j == 0) val_r = 0;
                else val_r = dna_val(prev_dna[j-1]);
                if (j == prev_dna.size()-1) val_l = 0;
                else val_l = dna_val(prev_dna[j+1]);
                val_c = dna_val(prev_dna[j]);
                k = val_r + val_c + val_l;
                new_dna.push_back(val_dna(dna[k]));
            }
            dna_lines.push_back(new_dna);
        }
        dna_cases.push_back(dna_lines);
        num_cases--;
    }
    for (int m = 0; m < dna_cases.size(); m++) {
        vector<string> dna_days = dna_cases[m];
        for (string vals : dna_days){
            cout << vals << endl;
        }
        if (m != dna_cases.size()-1) cout << '\n';
    }
}

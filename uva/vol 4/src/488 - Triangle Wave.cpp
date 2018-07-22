//
// 488 - Triangle Wave
//
//  Created by Ridhwanul Haque  on 2/16/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    vector<string> outputs;
    int cases;
    cin >> cases;
    while (cases > 0) {
        int amp, freq;
        cin >> amp >> freq;
        string one_wave;
        for (int i = 1; i <= amp; i++) {
            for (int j =0; j < i; j++) {
                one_wave.push_back(to_string(i)[0]);
            }
            one_wave.push_back('\n');
        }
        for (int i = amp-1; i > 0; i--) {
            for (int j =0; j < i; j++) {
                one_wave.push_back(to_string(i)[0]);
            }
            one_wave.push_back('\n');
        }
        string full_wave;
        for (int i =0; i<freq; i++){
            full_wave += one_wave;
            full_wave.push_back('\n');
        }
        if (cases == 1) full_wave.pop_back();
        outputs.push_back(full_wave);
        cases--;
    }
    for (string out : outputs) {
        cout << out;
    }
}

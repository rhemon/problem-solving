//
// 499 - What's The Frequency, Kenneth?
//
//  Created by Ridhwanul Haque  on 2/28/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    string res;
    while(!cin.eof()){
        string line;
        getline(cin, line);
        map<char, int> word_count;
        string letters;
        int max_count = 0;
        for (char c : line) {
            if (!isalpha(c)) continue;
            if (word_count.count(c) > 0) {
                int count = word_count[c];
                count++;
                if (count > max_count) {
                    letters = string(1, c);
                    max_count = count;
                } else if (count == max_count){
                    letters.push_back(c);
                }
                word_count[c] = count;
            } else {
                word_count[c] = 1;
                if (1 >= max_count) {
                    letters.push_back(c);
                    max_count = 1;
                }
            }
        }
        sort(letters.begin(), letters.end());
        if (max_count != 0) res += letters + " " + to_string(max_count) + "\n";
    }
    cout << res;
    return 0;
}

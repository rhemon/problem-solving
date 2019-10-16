//
// 409 - Excuses, Excuses!
//
//  Created by Ridhwanul Haque  on 2/20/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include<iostream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;
string to_lower_str(string str){
    string res;
    for (char c : str) {
        res.push_back(tolower(c));
    }
    return res;
}
int score_excuse(string exc, vector<string> keywords) {
    int score = 0;
    exc = to_lower_str(exc);
    for (string word : keywords) {
        word = to_lower_str(word);
        size_t pos = 0;
        while (true) {
            pos = exc.find(word, pos);
            if (pos != string::npos) {
                if (pos > 0){
                    if (!isalpha(exc[pos-1]) && !isalpha(exc[pos+word.size()])) score++;
                } else if (!isalpha(exc[pos+word.size()])) score++;
            } else break;
            pos++;
        }
    }
    return score;
}

int main() {
    vector<string> cases_output;
    int k = 1;
    while(true) {
        string num;
        getline(cin, num);
        if(num.size() == 0) break;

        int num_words = atoi(&num[0]);
        int num_excuses = atoi(&num[2]);
        vector<string> keywords;
        while(num_words > 0){
            string word;
            cin >> word;
            keywords.push_back(word);
            num_words--;
        }
        vector<string> excuses;
        cin.ignore();
        while(num_excuses > 0) {
            string excuse;
            getline(cin, excuse);
            excuses.push_back(excuse);
            num_excuses--;
        }
        string output;
        int max_score = 0, score = 0;
        for (string excuse : excuses) {
            score = score_excuse(excuse, keywords);
            if (score > max_score) {
                output = excuse + "\n";
                max_score = score;
            } else if (score == max_score) {
                output += excuse + "\n";
            }

        }

        output = "Excuse Set #" + to_string(k) + "\n" + output;
        cases_output.push_back(output);
        k++;
    }
    for (int i = 0; i < cases_output.size(); i++) {
        string out = cases_output[i];
        cout << out << '\n';
    }
}

//
// 492 - Pig-Latin
//
// Created by Ridhwanul Haque on 04/04/2018
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    string output;
    string line;
    while (getline(cin, line)) {
        string word;
        for (int i = 0; i < line.size(); i++) {
            if (isalpha(line[i])) {
                word.push_back(line[i]);
            }
            if (!isalpha(line[i]) || i+1 == line.size()){
                if (word.size() != 0) {
                    char f = word[0];
                    char *p = find(vowels, vowels+5, tolower(f));
                    string res;
                    if (p == vowels+5) {
                        for (int j = 1; j < word.size(); j++) res.push_back(word[j]);
                        res.push_back(f);
                        res.push_back('a');
                        res.push_back('y');
                    } else {
                        res = word;
                        res.push_back('a');
                        res.push_back('y');
                    }
                    output += res;
                }
                if(!isalpha(line[i])) output += line[i];
                word = "";
            }
        }
        output += "\n";
    }
    cout << output;
}

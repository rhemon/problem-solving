// https://codeforces.com/contest/118/problem/A

#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    string word;
    cin >> word;
    string newword;
    for (char c : word) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            continue;
        }
        newword.push_back('.');
        newword.push_back(c);
    }
    cout << newword << endl;
    return 0;
}

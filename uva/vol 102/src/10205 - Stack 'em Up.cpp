//
// 10205 - Stack 'em Up
//
// Created by Ridhwanul Haque on 12/03/2018
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string values[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};

string name(int val) {
    int value = (val % 13)-1;
    int suit = (val/13);
    if (value == -1) suit--;
    if (value==-1) value = 12;
    return values[value] + " of " + suits[suit];
}

int main() {
    vector<int> card;
    for (int i = 1; i < 53; i++) card.push_back(i);
    int t;
    cin >> t;
    cin.ignore();
    string line;
    getline(cin, line);
    vector<vector<int>> output;
    while (t > 0) {
        int ns;
        cin >> ns;
        vector<vector<int>> shuffles;
        for (int i = 0; i < ns; i++) {
            vector<int> s;
            int c;
            for (int i = 0; i < 52; i++) {
                cin >> c;
                s.push_back(c);
            }
            shuffles.push_back(s);
        }
        vector<int> st;
        string k;
        cin.ignore();
        while(getline(cin, k)) {
            if (k.size() == 0) break;
            st.push_back(atoi(k.c_str()));
        }
        vector<int> scard = card;
        for (int pos : st) {
            vector<int> s = shuffles[pos-1];
            vector<int> nset;
            for (int ci : s) nset.push_back(scard[ci-1]);
            scard = nset;
        }
        output.push_back(scard);
        t--;
    }
    for (int i = 0; i < output.size(); i++) {
        vector<int> cset = output[i];
        for (int ci : cset) {
            cout << name(ci) << endl;
        }
        if (i < output.size()-1) cout << endl;
    }
    return 0;
}

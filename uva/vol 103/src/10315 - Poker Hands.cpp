//
// 10315 - Poker Hands
//
// Created by Ridhwanul Haque on 11/03/2018
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string VALUES = "23456789TJQKA";
string SUITS = "CDHS";
vector<string> CATEGORIES;
map<char, int> COUNTS[2];

void print_cards(vector<string> cards) {
    for (string c: cards) {
        cout << c << endl;
    }
}

vector<string> rank_cards(vector<string> cards) {
    vector<string> r_cards(cards.size(), "");

    for (string c : cards) {
        char value = c[0];
        char suit = c[1];
        int i = cards.size();
        int pos_v = VALUES.find(string(1, value));
        int pos_i;
        do {
            i--;
            if (r_cards[i] == "") break;
            char value_i = r_cards[i][0];
            pos_i = VALUES.find(string(1, value_i));
        } while (pos_i > pos_v);
        for (int j = 0; j<=i; j++){
            if (r_cards[j] == "") continue;
            r_cards[j-1] = r_cards[j];
        }
        r_cards[i] = c;
    }

    // print_cards(r_cards);
    return r_cards;
}

string set_cat(vector<string> cards, int op) {
    // cout << "set cat " << endl;
    map<char, int> COUNT = COUNTS[op];
    // cout << "asigned count map " << endl;

    int uv = 1, us = 0, c=1;
    string sets;
    for (int i = 0; i < 5; i++) {
        if (i < 4) {
            if (cards[i][0] != cards[i+1][0]) {
                uv++;
                if (c > 1) COUNT[cards[i][0]] = c;
                c = 1;
            } else {
                c++;
                if (i == 3) {
                    if (c > 1) COUNT[cards[i][0]] = c;
                }
            }
        }
        int pos = sets.find(string(1, cards[i][1]));
        if (pos == string::npos) {
            us++;
            sets.push_back(cards[i][1]);
        }
    }

    // cout << "Uncommon values : " << uv << endl;
    // cout << "Uncommon suits : " << us << endl;

    vector<char> v;
    for(map<char,int>::iterator it = COUNT.begin(); it != COUNT.end(); ++it) {
      v.push_back(it->first);
    }

    COUNTS[op] = COUNT;

    if (uv == 5) {
        int pos1 = VALUES.find(string(1, cards[0][0]));
        int pos2 = VALUES.find(string(1, cards[4][0]));
        if (pos2-pos1 == 4) {
            if (us == 1) return "SF";
            else return "S";
        }
        if (us == 1) return "F";
        return "HC";
    } else if (uv == 4) {
        return "P";
    } else if (uv == 3) {
        // cout << "uv found to be 3" << endl;
        // cout << "v 0 is " << v[0] << endl;
        if (COUNT[v[0]] == 2) return "TP";
        else return "TK";
    } else {
        if (COUNT[v[0]] == 3 || COUNT[v[1]] == 3) return "FH";
        return "FK";
    }
}

int winner(vector<string> black, vector<string> white) {
    // cout << "gotta find the winner"<<endl;
    string b_c = set_cat(black, 0);
    string w_c = set_cat(white, 1);
    vector<string>::iterator bit = find(CATEGORIES.begin(), CATEGORIES.end(), b_c);
    int p_b = bit - CATEGORIES.begin();
    vector<string>::iterator wit = find(CATEGORIES.begin(), CATEGORIES.end(), w_c);
    int p_c = wit - CATEGORIES.begin();
    if (p_b < p_c) return 0;
    else if (p_b > p_c) return 1;
    else {
        // cout << b_c << endl;
        map<char, int> black_count = COUNTS[0];
        map<char, int> white_count = COUNTS[1];
        vector<char> v_black;
        for(map<char,int>::iterator it = black_count.begin(); it != black_count.end(); ++it) {
          v_black.push_back(it->first);
        }
        vector<char> v_white;
        for(map<char,int>::iterator it = white_count.begin(); it != white_count.end(); ++it) {
          v_white.push_back(it->first);
        }
        bool higher = false;
        if (b_c == "P") {
            int p1_pos = VALUES.find(string(1,v_black[0]));
            int p2_pos = VALUES.find(string(1,v_white[0]));
            if (p1_pos < p2_pos) return 1;
            if (p2_pos < p1_pos) return 0;
            for (int i = 4; i >= 0; i--) {
                if (black[i][0] == v_black[0]) continue;
                int p1_pos = VALUES.find(string(1,black[i][0]));
                int p2_pos = VALUES.find(string(1,white[i][0]));
                if (p1_pos < p2_pos) return 1;
                if (p2_pos < p1_pos) return 0;
            }
        } else if (b_c == "TP") {
            int p1_pos = VALUES.find(string(1,v_black[0]));
            int p2_pos = VALUES.find(string(1,v_white[0]));
            if (p1_pos < p2_pos) return 1;
            if (p2_pos < p1_pos) return 0;
            p1_pos = VALUES.find(string(1,v_black[1]));
            p2_pos = VALUES.find(string(1,v_white[1]));
            if (p1_pos < p2_pos) return 1;
            if (p2_pos < p1_pos) return 0;
            for (int i = 4; i >= 0; i--) {
                if (black[i][0] == v_black[0] || black[i][0] == v_black[1]) continue;
                int p1_pos = VALUES.find(string(1,black[i][0]));
                int p2_pos = VALUES.find(string(1,white[i][0]));
                if (p1_pos < p2_pos) return 1;
                if (p2_pos < p1_pos) return 0;
            }
        } else if (b_c == "TK") {
            // cout << "here" << endl;
            int p1_pos = VALUES.find(string(1,v_black[0]));
            int p2_pos = VALUES.find(string(1,v_white[0]));
            if (p1_pos < p2_pos) return 1;
            if (p2_pos < p1_pos) return 0;
            for (int i = 4; i >= 0; i--) {
                if (black[i][0] == v_black[0]) continue;
                int p1_pos = VALUES.find(string(1,black[i][0]));
                int p2_pos = VALUES.find(string(1,white[i][0]));
                if (p1_pos < p2_pos) return 1;
                if (p2_pos < p1_pos) return 0;
            }
        } else if (b_c == "FK") {
            int p1_pos = VALUES.find(string(1,v_black[0]));
            int p2_pos = VALUES.find(string(1,v_white[0]));
            if (p1_pos < p2_pos) return 1;
            if (p2_pos < p1_pos) return 0;
            for (int i = 4; i >= 0; i--) {
                if (black[i][0] == v_black[0]) continue;
                int p1_pos = VALUES.find(string(1,black[i][0]));
                int p2_pos = VALUES.find(string(1,white[i][0]));
                if (p1_pos < p2_pos) return 1;
                if (p2_pos < p1_pos) return 0;
            }
        } else if (b_c == "FH") {
            char bc3, bc2, wc3, wc2;
            if (black_count[v_black[0]] == 3) {
                bc3 = v_black[0];
                bc2 = v_black[1];
            } else {
                bc3 = v_black[1];
                bc2 = v_black[0];
            }
            if (white_count[v_white[0]] == 3) {
                wc3 = v_white[0];
                wc2 = v_white[1];
            } else {
                wc3 = v_white[1];
                wc2 = v_white[0];
            }

            int p1_pos = VALUES.find(string(1,bc3));
            int p2_pos = VALUES.find(string(1,wc3));
            if (p1_pos < p2_pos) return 1;
            if (p2_pos < p1_pos) return 0;
            p1_pos = VALUES.find(string(1,bc2));
            p2_pos = VALUES.find(string(1,wc2));
            if (p1_pos < p2_pos) return 1;
            if (p2_pos < p1_pos) return 0;
            for (int i = 4; i >= 0; i--) {
                if (black[i][0] == v_black[0] || black[i][0] == v_black[1]) continue;
                int p1_pos = VALUES.find(string(1,black[i][0]));
                int p2_pos = VALUES.find(string(1,white[i][0]));
                if (p1_pos < p2_pos) return 1;
                if (p2_pos < p1_pos) return 0;
            }
        } else {
            for (int i = 4; i >= 0; i--) {
                int p1_pos = VALUES.find(string(1,black[i][0]));
                int p2_pos = VALUES.find(string(1,white[i][0]));
                if (p1_pos < p2_pos) return 1;
                if (p2_pos < p1_pos) return 0;
            }
        }
        return 2;
    }
}

void reset() {
    (COUNTS[0]).clear();
    (COUNTS[1]).clear();
}

int main() {
    CATEGORIES.push_back("SF");
    CATEGORIES.push_back("FK");
    CATEGORIES.push_back("FH");
    CATEGORIES.push_back("F");
    CATEGORIES.push_back("S");
    CATEGORIES.push_back("TK");
    CATEGORIES.push_back("TP");
    CATEGORIES.push_back("P");
    CATEGORIES.push_back("HC");

    string output;
    string b1, b2, b3, b4, b5, w1, w2,w3, w4, w5;
    int won;
    while(cin >> b1 >> b2 >> b3 >> b4 >> b5 >> w1 >> w2 >> w3 >> w4 >> w5) {
        reset();
        vector<string> black, white;
        black.push_back(b1);
        black.push_back(b2);
        black.push_back(b3);
        black.push_back(b4);
        black.push_back(b5);
        white.push_back(w1);
        white.push_back(w2);
        white.push_back(w3);
        white.push_back(w4);
        white.push_back(w5);

        black = rank_cards(black);
        white = rank_cards(white);
        won = winner(black, white);
        if (won == 0) output += "Black wins.\n";
        else if (won == 1) output += "White wins.\n";
        else output += "Tie.\n";
    }

    cout << output;
    return 0;
}

//
// 4439 - Knight Moves
//
//  Created by Ridhwanul Haque  on 3/1/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef string (*func)(int, int);

map<string, int> memory;
int min_count;

string move_ur(int prows, int pcols) {
    char mrows, mcols;
    string np;
    if (prows < 6 && pcols < 7) {
        prows += 2;
        pcols += 1;
    }
    mrows = '1' + prows;
    mcols = 'a' + pcols;
    np = string(1, mcols) + string(1, mrows);
    return np;
}

string move_ul(int prows, int pcols) {
    char mrows, mcols;
    string np;
    if (prows < 6 && pcols > 0) {
        prows += 2;
        pcols -= 1;
    }
    mrows = '1' + prows;
    mcols = 'a' + pcols;
    np = string(1, mcols) + string(1, mrows);
    return np;
}

string move_dr(int prows, int pcols) {
    char mrows, mcols;
    string np;
    if (prows > 1 && pcols < 7) {
        prows -= 2;
        pcols += 1;
    }
    mrows = '1' + prows;
    mcols = 'a' + pcols;
    np = string(1, mcols) + string(1, mrows);
    return np;
}

string move_dl(int prows, int pcols) {
    char mrows, mcols;
    string np;
    if (prows > 1 && pcols > 0) {
        prows -= 2;
        pcols -= 1;
    }
    mrows = '1' + prows;
    mcols = 'a' + pcols;
    np = string(1, mcols) + string(1, mrows);
    return np;
}

string move_lu(int prows, int pcols) {
    char mrows, mcols;
    string np;
    if (prows < 7 && pcols > 1) {
        prows += 1;
        pcols -= 2;
    }
    mrows = '1' + prows;
    mcols = 'a' + pcols;
    np = string(1, mcols) + string(1, mrows);
    return np;
}

string move_ld(int prows, int pcols) {
    char mrows, mcols;
    string np;
    if (prows > 0 && pcols > 1) {
        prows -= 1;
        pcols -= 2;
    }
    mrows = '1' + prows;
    mcols = 'a' + pcols;
    np = string(1, mcols) + string(1, mrows);
    return np;
}

string move_ru(int prows, int pcols) {
    char mrows, mcols;
    string np;
    if (prows < 7 && pcols < 6) {
        prows += 1;
        pcols += 2;
    }
    mrows = '1' + prows;
    mcols = 'a' + pcols;
    np = string(1, mcols) + string(1, mrows);
    return np;
}

string move_rd(int prows, int pcols) {
    char mrows, mcols;
    string np;
    if (prows > 0 && pcols < 6) {
        prows -= 1;
        pcols += 2;
    }
    mrows = '1' + prows;
    mcols = 'a' + pcols;
    np = string(1, mcols) + string(1, mrows);
    return np;
}

vector<string> possible_move(string pos) {
    int prows = pos[1] - '1';
    int pcols = pos[0] - 'a';
    vector<string> moved_to;
    func arr[8] = {&move_ur, &move_ul, &move_dl, &move_dr, &move_ld, &move_lu, &move_ru, &move_rd};
    for (int i = 0; i<8; i++) {
        func move = arr[i];
        moved_to.push_back((*move)(prows, pcols));
    }
    return moved_to;
}

int find_min_moves(string pos, string target) {
    if (pos == target) return 0;
    vector<string> till_now;
    vector<string> in;
    in.push_back(pos);
    int moves = 0;
    vector<string>::iterator it2;
    do {
        vector<string> new_ins;
        for (string p : in) {
            vector<string>::iterator it = find(till_now.begin(), till_now.end(), p);
            if (it == till_now.end()) {
                vector<string> pms = possible_move(p);
                new_ins.insert(new_ins.end(), pms.begin(), pms.end());
            }
            till_now.push_back(p);
        }
        in = new_ins;
        moves++;
        it2 = find(in.begin(), in.end(), target);
    } while (it2 == in.end());
    return moves;
}

int main() {
    string output;
    string pos, target;
    while (cin >> pos >> target) {
        int moves = find_min_moves(pos, target);
        output += "To get from " + pos + " to " + target + " takes " + to_string(moves) + " knight moves.\n";
    }
    cout << output;
}

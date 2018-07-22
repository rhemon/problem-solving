//
// 10196 - Check The Check
//
// Created by Ridhwanul Haque on 10/03/2018
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string chess_board[8];
vector<vector<int>> attacks_white;
vector<vector<int>> attacks_black;

void pawn_moves(int r, int c, char p) {
    if (p == 'p') {
        vector<int> attack;
        attack.push_back(r+1);
        attack.push_back(c-1);
        attacks_white.push_back(attack);
        attack.erase(attack.begin(), attack.end());
        attack.push_back(r+1);
        attack.push_back(c+1);
        attacks_white.push_back(attack);
    } else if (p == 'P') {
        vector<int> attack;
        attack.push_back(r-1);
        attack.push_back(c-1);
        attacks_black.push_back(attack);
        attack.erase(attack.begin(), attack.end());
        attack.push_back(r-1);
        attack.push_back(c+1);
        attacks_black.push_back(attack);
    }
}

void rook_moves(int r, int c, char m) {
    vector<vector<int>> attacks;
    for (int i = r-1; i >= 0; i--) {
        if (chess_board[i][c] != '.' && tolower(chess_board[i][c]) != 'k') break;
        vector<int> attack;
        attack.push_back(i);
        attack.push_back(c);
        attacks.push_back(attack);
        if (tolower(chess_board[i][c]) == 'k') break;
    }
    for (int i = r+1; i < 8; i++) {
        if (chess_board[i][c] != '.' && tolower(chess_board[i][c]) != 'k') break;
        vector<int> attack;
        attack.push_back(i);
        attack.push_back(c);
        attacks.push_back(attack);
        if (tolower(chess_board[i][c]) == 'k') break;
    }
    for (int i = c-1; i >= 0; i--) {
        if (chess_board[r][i] != '.' && tolower(chess_board[r][i]) != 'k') break;
        vector<int> attack;
        attack.push_back(r);
        attack.push_back(i);
        attacks.push_back(attack);
        if (tolower(chess_board[r][i]) == 'k') break;
    }
    for (int i = c+1; i < 8; i++) {
        if (chess_board[r][i] != '.' && tolower(chess_board[r][i]) != 'k') break;
        vector<int> attack;
        attack.push_back(r);
        attack.push_back(i);
        attacks.push_back(attack);
        if (tolower(chess_board[r][i]) == 'k') break;
    }
    if (m == 'r') attacks_white.insert(attacks_white.end(), attacks.begin(), attacks.end());
    else if (m == 'R') attacks_black.insert(attacks_black.end(), attacks.begin(), attacks.end());
}

void bishop_moves(int r, int c, char b) {
    vector<vector<int>> attacks;
    for (int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--) {
        vector<int> attack;
        if (chess_board[i][j] != '.' && tolower(chess_board[i][j]) != 'k') break;
        attack.push_back(i);
        attack.push_back(j);
        attacks.push_back(attack);
        if (tolower(chess_board[i][j]) == 'k') break;
    }
    for (int i = r-1, j = c+1; i >= 0 && j < 8; i--, j++) {
        vector<int> attack;
        if (chess_board[i][j] != '.' && tolower(chess_board[i][j]) != 'k') break;
        attack.push_back(i);
        attack.push_back(j);
        attacks.push_back(attack);
        if (tolower(chess_board[i][j]) == 'k') break;
    }
    for (int i = r+1, j = c+1; i < 8 && j < 8; i++, j++) {
        vector<int> attack;
        if (chess_board[i][j] != '.' && tolower(chess_board[i][j]) != 'k') break;
        attack.push_back(i);
        attack.push_back(j);
        attacks.push_back(attack);
        if (tolower(chess_board[i][j]) == 'k') break;
    }
    for (int i = r+1, j = c-1; i < 8 && j >= 0; i++, j--) {
        vector<int> attack;
        if (chess_board[i][j] != '.' && tolower(chess_board[i][j]) != 'k') break;
        attack.push_back(i);
        attack.push_back(j);
        attacks.push_back(attack);
        if (tolower(chess_board[i][j]) == 'k') break;
    }
    if (b == 'b') attacks_white.insert(attacks_white.end(), attacks.begin(), attacks.end());
    else if (b == 'B') attacks_black.insert(attacks_black.end(), attacks.begin(), attacks.end());
}

void queen_move(int r, int c, char q) {
    if (q == 'q') {
        rook_moves(r, c, 'r');
        bishop_moves(r, c, 'b');
    } else if (q == 'Q') {
        rook_moves(r, c, 'R');
        bishop_moves(r, c, 'B');
    }
}

void knight_move(int r, int c, char k) {
    vector<vector<int>> attacks;
    vector<int> attack;
    attack.push_back(r+2);
    attack.push_back(c+1);
    attacks.push_back(attack);
    attack.erase(attack.begin(), attack.end());
    attack.push_back(r+2);
    attack.push_back(c-1);
    attacks.push_back(attack);
    attack.erase(attack.begin(), attack.end());
    attack.push_back(r-2);
    attack.push_back(c-1);
    attacks.push_back(attack);
    attack.erase(attack.begin(), attack.end());
    attack.push_back(r-2);
    attack.push_back(c+1);
    attacks.push_back(attack);
    attack.erase(attack.begin(), attack.end());
    attack.push_back(r+1);
    attack.push_back(c-2);
    attacks.push_back(attack);
    attack.erase(attack.begin(), attack.end());
    attack.push_back(r-1);
    attack.push_back(c-2);
    attacks.push_back(attack);
    attack.erase(attack.begin(), attack.end());
    attack.push_back(r+1);
    attack.push_back(c+2);
    attacks.push_back(attack);
    attack.erase(attack.begin(), attack.end());
    attack.push_back(r-1);
    attack.push_back(c+2);
    attacks.push_back(attack);
    attack.erase(attack.begin(), attack.end());
    if (k == 'n') attacks_white.insert(attacks_white.end(), attacks.begin(), attacks.end());
    else if (k == 'N') attacks_black.insert(attacks_black.end(), attacks.begin(), attacks.end());
}

int main(){
    string row;
    int i = 0;
    bool empty = true;
    string output;
    int game = 1;
    while (getline(cin, row)) {
        if (row.size() == 0) {
            empty = true;
            i = 0;
            // cout << "here size = 0" << endl;
            attacks_black.erase(attacks_black.begin(), attacks_black.end());
            attacks_white.erase(attacks_white.begin(), attacks_white.end());
            vector<int> wk_pos, bk_pos;
            for (int r = 0; r < 8; r++) {
                string rr = chess_board[r];
                for (int c = 0; c < 8; c++) {
                    char m = rr[c];
                    switch (tolower(m)) {
                        case 'p':
                            pawn_moves(r, c, m);
                            break;
                        case 'r':
                            rook_moves(r, c, m);
                            break;
                        case 'b':
                            bishop_moves(r, c, m);
                            break;
                        case 'n':
                            knight_move(r, c, m);
                            break;
                        case 'q':
                            queen_move(r, c, m);
                            break;
                        case 'k':
                            if (m == 'K') {
                                wk_pos.push_back(r);
                                wk_pos.push_back(c);
                            } else {
                                bk_pos.push_back(r);
                                bk_pos.push_back(c);
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
            vector<vector<int>>::iterator wit = find(attacks_white.begin(), attacks_white.end(), wk_pos);
            vector<vector<int>>::iterator bit = find(attacks_black.begin(), attacks_black.end(), bk_pos);
            if (wit != attacks_white.end()) {
                output += "Game #" + to_string(game) + ": white king is in check.\n";
            } else if (bit != attacks_black.end()) {
                output += "Game #" + to_string(game) + ": black king is in check.\n";
            } else {
                output += "Game #" + to_string(game) + ": no king is in check.\n";
            }
            game++;
        } else {
            if (row != "........") empty=false;
            chess_board[i] = row;
            i++;
            // cout << "i " << i << " empty " << empty << endl;
            if (i==8 && empty) break;
        }
        // cout << "here" << endl;

    }
    cout << output;
    return 0;
}

//
// 10189 - Minesweeper
//
// Created by Ridhwanul Haque on 07/03/2018
//

#include <iostream>

using namespace std;

int main() {
    int x,y;
    string output;
    int f = 1;
    while (cin >> y >> x) {
        if (y == 0 && x == 0) break;
        char field[y][x];
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                char c;
                cin >> c;
                field[i][j] = c;
            }
        }
        output += "Field #" + to_string(f) + ":\n";
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                int num_mines = 0;
                if (field[i][j] == '*') {
                    output.push_back('*');
                    continue;
                }
                if (i > 0) {
                    if (field[i-1][j] == '*') num_mines++;
                    if (j > 0) if (field[i-1][j-1] == '*') num_mines++;
                    if (j < x-1) if (field[i-1][j+1] == '*') num_mines++;
                }
                if (i < y-1) {
                    if (field[i+1][j] == '*') num_mines++;
                    if (j > 0) if (field[i+1][j-1] == '*') num_mines++;
                    if (j < x-1) if (field[i+1][j+1] == '*') num_mines++;
                }
                if (j > 0) if (field[i][j-1] == '*') num_mines++;
                if (j < x-1) if (field[i][j+1] == '*') num_mines++;
                output.push_back('0' + num_mines);
            }
            output.push_back('\n');
        }
        output.push_back('\n');
        f++;
    }
    output.pop_back();
    cout << output;
    return 0;
}

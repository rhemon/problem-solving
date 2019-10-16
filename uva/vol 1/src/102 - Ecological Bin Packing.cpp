//
// 102 - Ecological Bin Packing
//
// Created by Ridhwanul Haque on 06/03/2018
//

#include <iostream>

using namespace std;

int main(){
    string output;
    int b1,g1,c1,b2,g2,c2,b3,g3,c3;
    while (cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3) {
        int bin[3][3] = {{b1,g1,c1},{b2,g2,c2},{b3,g3,c3}};
        string cases[] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
        string min_case = "NONE";
        int min_moves = -1;
        for (string c : cases) {
            int to_move = 0;
            for (int i = 0; i < 3; i++) {
                char b = c[i];
                switch (b) {
                    case 'B':
                        to_move += bin[i][1]+bin[i][2];
                        break;
                    case 'C':
                        to_move += bin[i][0]+bin[i][1];
                        break;
                    case 'G':
                        to_move += bin[i][0] + bin[i][2];
                        break;
                }
            }
            if (to_move < min_moves || min_moves == -1) {
                min_moves = to_move;
                min_case = c;
            }
        }
        output += min_case + " " + to_string(min_moves) + "\n";
    }
    cout << output;
    return 0;
}

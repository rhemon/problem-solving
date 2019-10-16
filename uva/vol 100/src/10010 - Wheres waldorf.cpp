//
// 10010 - Where's Waldorf?
//
//  Created by Ridhwanul Haque  on 2/20/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check_left(int x, int y, vector<string> grid, string word){
    if (x+1 < word.size()) return false;
    int j = 0;
    int condition_calc = (x+1)-word.size();
    for (int i = x; i >= condition_calc; i--) {
        if (tolower(grid[y][i]) != tolower(word[j])) return false;
        j++;
    }
    return true;
}
bool check_right(int x, int y, vector<string> grid, string word) {
    if (grid[0].size()-x < word.size()) return false;
    int j = 0;
    int condition_calc = x+word.size();
    for (int i = x; i < condition_calc; i++) {
        if (tolower(grid[y][i]) != tolower(word[j])) return false;
        j++;
    }
    return true;
}
bool check_up(int x, int y, vector<string> grid, string word) {
    if (y+1 < word.size()) return false;
    int j = 0;
    int condition_calc = (y+1)-word.size();
    for (int i = y; i >= condition_calc; i--) {
        if (tolower(grid[i][x]) != tolower(word[j])) return false;
        j++;
    }
    return true;
}
bool check_down(int x, int y, vector<string> grid, string word) {
    if (grid.size()-y < word.size()) return false;
    int j = 0;
    int condition_calc = y+word.size();
    for (int i = y; i < condition_calc; i++) {
        if (tolower(grid[i][x]) != tolower(word[j])) return false;
        j++;
    }
    return true;
}
bool check_up_left(int x, int y, vector<string> grid, string word) {
    if (x+1 < word.size()) return false;
    if (y+1 < word.size()) return false;
    int x_cond = (x+1)-word.size();
    int y_cond = (y+1)-word.size();
    int j = 0;
    for (int i = x, k = y; i >= x_cond && k >= y_cond; i--, k--) {
        if (tolower(grid[k][i]) != tolower(word[j])) return false;
        j++;
    }
    return true;
}
bool check_up_right(int x, int y, vector<string> grid, string word) {
    if (grid[0].size()-x < word.size()) return false;
    if (y+1 < word.size()) return false;
    int j = 0;
    int x_cond = x+word.size();
    int y_cond = (y+1)-word.size();
    for (int i = x, k = y; i < x_cond && k >= y_cond; i++, k--) {
        if (tolower(grid[k][i]) != tolower(word[j])) return false;
        j++;
    }
    return true;
}
bool check_down_left(int x, int y, vector<string> grid, string word) {
    if (x+1 < word.size()) return false;
    if (grid.size()-y < word.size()) return false;
    int j = 0;
    int x_cond = (x+1)-word.size();
    int y_cond = y+word.size();
    for (int i = x, k = y; i >= x_cond && k < y_cond; i--, k++) {
        if (tolower(grid[k][i]) != tolower(word[j])) return false;
        j++;
    }
    return true;
}
bool check_down_right(int x, int y, vector<string> grid, string word) {
    if (grid[0].size()-x < word.size()) return false;
    if (grid.size()-y < word.size()) return false;
    int j = 0;
    int x_cond = x+word.size();
    int y_cond = y+word.size();
    for (int i = x, k = y; i < x_cond && k < y_cond; i++, k++) {
        if (tolower(grid[k][i]) != tolower(word[j])) return false;
        j++;
    }
    return true;
}

bool check_word(int x, int y, vector<string> grid, string word) {
    if (check_up(x, y, grid, word)) return true;
    if (check_down(x, y, grid, word)) return true;
    if (check_left(x, y, grid, word)) return true;
    if (check_right(x, y, grid, word)) return true;
    if (check_up_left(x, y, grid, word)) return true;
    if (check_up_right(x, y, grid, word)) return true;
    if (check_down_left(x, y, grid, word)) return true;
    if (check_down_right(x, y, grid, word)) return true;
    return false;
}

int main() {
    int num_cases;
    cin >> num_cases;
    vector<vector<int>> case_coord_x, case_coord_y;
    while (num_cases>0) {
        vector<string> grid;
        int n, m;
        cin >> n >> m;
        string line;
        while(n>0) {
            cin >> line;
            grid.push_back(line);
            n--;
        }
        int words_num;
        cin >> words_num;
        vector<string> words;
        string word;
        while (words_num > 0) {
            cin >> word;
            words.push_back(word);
            words_num--;
        }
        vector<int> coord_x, coord_y;
        for (string w : words) {
            bool ifword = false;
            for (int y = 0; y < grid.size(); y++) {
                for (int x = 0; x < grid[y].size(); x++) {
                    ifword = check_word(x, y, grid, w);
                    if (ifword) {
                        coord_x.push_back(x+1);
                        coord_y.push_back(y+1);
                        break;
                    }
                }
                if (ifword) break;
            }
        }

        case_coord_x.push_back(coord_x);
        case_coord_y.push_back(coord_y);
        num_cases--;
    }

    for (int i =0; i < case_coord_x.size(); i++) {
        vector<int> x_cords = case_coord_x[i];
        vector<int> y_cords = case_coord_y[i];
        for (int j = 0; j < x_cords.size(); j++) {
            cout << y_cords[j] << " " << x_cords[j] << endl;
        }
        if (i != case_coord_x.size()-1) cout << '\n';
    }



}

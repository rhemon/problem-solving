//
// 10267 - Graphical Editor
//
// Created by Ridhwanul Haque on 09/03/2018
//

#include <iostream>
#include <sstream>

using namespace std;

string canvas;
int canvas_row, canvas_col;

void init(int r, int c) {
    if (r <= 0 || c <= 0) return;
    canvas = "";
    canvas_row = r;
    canvas_col = c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            canvas.push_back('O');
        }
        canvas.push_back('\n');
    }
}

void clear() {
    canvas = "";
    for (int i = 0; i < canvas_row; i++) {
        for (int j = 0; j < canvas_col; j++) {
            canvas.push_back('O');
        }
        canvas.push_back('\n');
    }
}

void color_pixel(int r, int c, char col) {
    if (r < 0 || c < 0 || r >= canvas_row || c >= canvas_col) return;
    canvas[((canvas_col+1)*r) + c] = col;
}

char color_at(int r, int c) {
    return canvas[((canvas_col+1)*r) + c];
}

void vertical(int x, int y1, int y2, char col) {
    int r1 = y1 < y2 ? y1 : y2;
    int r2 = y1 > y2 ? y1 : y2;
    for (int i = r1; i <= r2; i++) {
        color_pixel(i, x, col);
    }
}

void horizontal(int x1, int x2, int y, char col) {
    int c1 = x1 < x2 ? x1 : x2;
    int c2 = x1 > x2 ? x1 : x2;
    for (int i = c1; i <= c2; i++) {
        color_pixel(y, i, col);
    }
}

void rect(int x1, int y1, int x2, int y2, char col) {
    int r1 = y1 < y2 ? y1 : y2;
    int r2 = y1 > y2 ? y1 : y2;
    int c1 = x1 < x2 ? x1 : x2;
    int c2 = x1 > x2 ? x1 : x2;
    for (int i = c1; i <= c2; i++) {
        for (int j = r1; j <= r2; j++) {
            color_pixel(j, i, col);
        }
    }
}

void fill(int r, int c, char col, char old_col) {
    if (r < 0 || c < 0 || r >= canvas_row || c >= canvas_col) return;
    color_pixel(r, c, col);
    int start_r, start_c, end_r, end_c;
    if (r > 0) start_r = r-1;
    else start_r = r;
    if (r < canvas_row-1) end_r = r+1;
    else end_r = r;
    if (c > 0) start_c = c-1;
    else start_c = c;
    if (c < canvas_col-1) end_c = c+1;
    else end_c = c;
    for (int i = start_r; i <= end_r; i++) {
        for (int j = start_c; j <= end_c; j++) {
            if (color_at(i, j) == old_col && color_at(i, j) != col) fill(i, j, col, old_col);
        }
    }
}

int main() {
    string output;
    string order;
    while (getline(cin, order)) {
        char ord;
        stringstream ss(order);
        ss >> ord;
        if (ord == 'X') break;
        int x,y,r,c,x1,x2,y1,y2;
        char col, oc;
        string name;
        switch (ord) {
            case 'I':
                if (order.size() == 1) break;
                ss >> c >> r;
                init(r, c);
                break;
            case 'C':
                clear();
                break;
            case 'L':
                if (order.size() == 1) break;
                ss >> x >> y >> col;
                color_pixel(y-1, x-1, col);
                break;
            case 'H':
                if (order.size() == 1) break;
                ss >> x1 >> x2 >> y >> col;
                horizontal(x1-1, x2-1, y-1, col);
                break;
            case 'V':
                if (order.size() == 1) break;
                ss >> x >> y1 >> y2 >> col;
                vertical(x-1, y1-1, y2-1, col);
                break;
            case 'K':
                if (order.size() == 1) break;
                ss >> x1 >> y1 >> x2 >> y2 >> col;
                rect(x1-1, y1-1, x2-1, y2-1, col);
                break;
            case 'F':
                if (order.size() == 1) break;
                ss >> x >> y >> col;
                oc = color_at(y-1, x-1);
                fill(y-1, x-1, col, oc);
                break;
            case 'S':
                if (order.size() == 1) break;
                ss >> name;
                output += name + "\n" + canvas;
                break;
            default:
                break;
        }
    }
    cout << output;
    return 0;
}

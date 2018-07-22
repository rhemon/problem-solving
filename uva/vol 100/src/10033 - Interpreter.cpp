//
// 10033 - Interpreter
//
// Created by Ridhwanul Haque on 10/03/2018
//

#include <iostream>

using namespace std;

int R[10];
string RAM[1000];
int ri;
bool is_halt;

void init() {
    for (int i = 0; i < 1000; i++) RAM[i] = "000";
    for (int i = 0; i < 10; i++) R[i] = 0;
    ri = 0;
}
int perform(int ord, int reg1, int reg2, string line) {
    string x;
    int count = 0;
    int o, r1, r2;
    int start, end;
    switch (ord) {
        case 0:
            // cout << "reg1 : " << reg1 << endl;
            // cout << "reg2 : " << reg2 << endl;
            // cout << "R[8] : " << R[8] << endl;
            // cout << "RAM[R[7]] : " << RAM[R[7]] << endl;
            // cout << "R[7] : " << R[7] << endl;
            RAM[ri] = line;
            start =  R[reg1];
            count++;
            while (R[reg2] != 0) {
                // cout << "R[8] : " << R[8] << endl;
                // cout << "RAM[R[7]] : " << RAM[R[7]] << endl;
                // cout << "R[7] : " << R[7] << endl;
                // cout << "reg1 : " << reg1 << endl;
                // cout << "reg2 : " << reg2 << endl;
                // cout << "start : " << start << endl;
                // cout << "RAM[start] : " << RAM[start] << endl;
                if (is_halt) {
                    count--;
                    break;
                }
                x = RAM[start];
                if (x == "000") {
                    start++;
                    count++;
                    if (start > 999) start = 0;
                } else {
                    o = x[0] - '0', r1 = x[1] - '0', r2 = x[2] - '0';
                    count += perform(o, r1, r2, line);
                    count++;
                }
            }
            break;
        case 1:
            if (reg1 == 0 && reg2 == 0) {
                count++;
                is_halt = true;
            }
            break;
        case 2:
            RAM[ri] = line;
            R[reg1] = (reg2)%1000;
            count++;
            break;
        case 3:
            RAM[ri] = line;
            R[reg1] = (R[reg1] + reg2)%1000;
            count++;
            break;
        case 4:
            RAM[ri] = line;
            R[reg1] = (R[reg1] * reg2)%1000;
            count++;
            break;
        case 5:
            RAM[ri] = line;
            R[reg1] = (R[reg2])%1000;
            count++;
            break;
        case 6:
            RAM[ri] = line;
            R[reg1] = (R[reg1] + R[reg2])%1000;
            count++;
            break;
        case 7:
            RAM[ri] = line;
            R[reg1] = (R[reg1] * R[reg2])%1000;
            count++;
            break;
        case 8:
            RAM[ri] = line;
            R[reg1] = atoi(RAM[R[reg2]].c_str()) % 1000;
            // cout << "R[" << reg1 << "] " << R[reg1] << endl;
            count++;
            break;
        case 9:
            RAM[ri] = line;
            x = to_string(R[reg1]);
            // cout << "x " << x << endl;
            // cout << "reg1 reg2 " << reg1 << " " << reg2 << endl;
            // cout << "R[" << reg1 << "] " << R[reg1] << endl;
            // cout << "R[" << reg2 << "] " << R[reg2] << endl;
            while (x.size() < 3) x = "0"+x;
            RAM[R[reg2]] = x;
            count++;
            break;
        default:
            break;
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    string output;
    string line;
    getline(cin, line);
    while (t > 0) {
        is_halt = false;
        init();
        int count = 0;
        while (getline(cin, line)) {
            // cout << "here " << endl;
            if (line.size() == 0) break;
            if (is_halt) continue;
            // cout << "line " << line << endl;
            int ord = line[0] - '0';
            int reg1 = line[1] - '0';
            int reg2 = line[2] - '0';
            count += perform(ord, reg1, reg2, line);
            ri++;
        }
        // cout << "here " << endl;
        output += to_string(count) + "\n\n";
        t--;
    }
    output.pop_back();
    cout << output;
    return 0;
}

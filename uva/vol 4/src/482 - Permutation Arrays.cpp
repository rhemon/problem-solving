//
// 482 - Permutation Arrays
//
// Created by Ridhwanul Haque on 06/03/2018
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string output;
    while (n > 0) {
        string line;
        vector<int> indices;
        getline(cin, line);
        if (line.size() == 0) continue;
        stringstream ss(line);
        int i;
        while (ss >> i) {
            indices.push_back(i);
        }
        string line2;
        getline(cin, line2);
        stringstream ss2(line2);
        string d;
        vector<string> values(indices.size());
        int k = 0;
        while (ss2 >> d) {
            // cout << indices[k] << endl;
            values[indices[k]-1] = d;
            k++;
        }
        // cout << "vs " << values.size() << endl;
        // cout << "is " << indices.size() << endl;
        for (string str : values) {
            output += str + "\n";
        }
        output += "\n";
        n--;
    }
    output.pop_back();
    cout << output;
    return 0;
}

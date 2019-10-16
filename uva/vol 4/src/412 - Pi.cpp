//
// 412 - Pi
//
// Created by Ridhwanul Haque on 06/03/2018
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

bool common_divisor(int p1, int p2) {
    int a = p1 > p2 ? p1 : p2;
    int b = p1 < p2 ? p1 : p2;
    if (b) {
        if (b==1) return true;
        return common_divisor(b, a%b);
    } else return false;
}

vector<int> pairs(vector<int> values) {
    int all_pairs = 0;
    int ncf_pairs = 0;
    for (int i = 0; i<values.size()-1; i++){
        for (int j = i+1; j<values.size(); j++) {
            int p1 = values[i];
            int p2 = values[j];
            all_pairs++;
            if (common_divisor(p1,p2)) ncf_pairs++;
        }
    }
    vector<int> res;
    res.push_back(all_pairs);
    res.push_back(ncf_pairs);
    return res;

}

int main() {
    int t;
    vector<double> outputs;
    while (true) {
        cin >> t;
        if (t==0) break;
        vector<int> dataset;
        int num;
        for (int i = 0; i < t; i++) {
            cin >> num;
            dataset.push_back(num);
        }
        vector<int> pair_vals = pairs(dataset);
        if (pair_vals[1] == 0) {
            outputs.push_back(0);
        } else {
            double fraction = double(pair_vals[1])/double(pair_vals[0]);
            double pi = sqrt(6.0/fraction);
            outputs.push_back(pi);
        }
    }
    for (double d : outputs) {
        if (d==0) {
            cout << "No estimate for this data set." << endl;
        } else {
            cout << setprecision(6) << fixed << d << endl;
        }
    }
}

//
// 537 - Artificial Intelligence?
//
//  Created by Ridhwanul Haque  on 2/20/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>


using namespace std;

int main() {
    int num_cases;
    cin >> num_cases;
    string valuesOf;
    string units;
    vector<double> outputs;
    cin.ignore();

    while (num_cases>0){
        num_cases--;
        string problem;
        getline(cin, problem);
        double I=0.0, V=0.0, P=0.0;
        size_t ipos = problem.find("I=");
        if (ipos != string::npos) {
            size_t upos = problem.find("A", ipos);
            string val;
            for (int i = ipos+2; i < upos+1; i++) {
                if (isdigit(problem[i]) || problem[i] == '.' || problem[i] == '-' || problem[i]=='+') {
                    val.push_back(problem[i]);
                } else {
                    switch(problem[i]) {
                        case 'm':
                            I = atof(val.c_str()) * 0.001;
                            break;
                        case 'k':
                            I = atof(val.c_str()) * 1000;
                            break;
                        case 'M':
                            I = atof(val.c_str()) * 1000000;
                            break;
                        default:
                            I = atof(val.c_str());
                            break;
                    }
                    break;
                }
            }
        }
        size_t vpos = problem.find("U=");
        if (vpos != string::npos) {
            size_t upos = problem.find("V",vpos);
            string val;
            for (int i = vpos+2; i < upos+1; i++) {
                if (isdigit(problem[i]) || problem[i]=='.' || problem[i] == '-' || problem[i]=='+') {
                    val.push_back(problem[i]);
                } else {
                    switch(problem[i]) {
                        case 'm':
                            V = atof(val.c_str()) * 0.001;
                            break;
                        case 'k':
                            V = atof(val.c_str()) * 1000;
                            break;
                        case 'M':
                            V = atof(val.c_str()) * 1000000;
                            break;
                        default:
                            V = atof(val.c_str());
                            break;
                    }
                    break;
                }
            }
        }
        size_t ppos = problem.find("P=");
        if (ppos != string::npos) {
            size_t upos = problem.find("W", ppos);
            string val;
            for (int i = ppos+2; i < upos+1; i++) {
                if (isdigit(problem[i]) || problem[i] == '.' || problem[i] == '-' || problem[i]=='+') {
                    val.push_back(problem[i]);
                } else {
                    switch(problem[i]) {
                        case 'm':
                            P = atof(val.c_str()) * 0.001;
                            break;
                        case 'k':
                            P = atof(val.c_str()) * 1000;
                            break;
                        case 'M':
                            P = atof(val.c_str()) * 1000000;
                            break;
                        default:
                            P = atof(val.c_str());
                            break;
                    }
                    break;
                }
            }
        }

        if (vpos == string::npos) {
            V = P/I;
            valuesOf.push_back('U');
            outputs.push_back(V);
            units.push_back('V');
        } else if (ppos == string::npos){
            P = I * V;
            valuesOf.push_back('P');
            outputs.push_back(P);
            units.push_back('W');
        } else {
            I = P/V;
            valuesOf.push_back('I');
            outputs.push_back(I);
            units.push_back('A');
        }
    }
    cout << fixed;
    cout << setprecision(2);
    for (int i =0; i < valuesOf.size(); i++) {
        cout << "Problem #" << i+1 << endl;
        cout << valuesOf[i] << "=";
        cout << outputs[i] << units[i] << endl;
        cout << '\n';
    }
}

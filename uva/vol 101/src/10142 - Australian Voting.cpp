//
// 10142 - Australian Voting
//
// Created by Ridhwanul Haque on 11/03/2018
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string output;
    int t;
    cin >> t;
    cin.ignore();
    string line;
    getline(cin, line);
    int k;
    while (t > 0) {
        cin >> k;
        cin.ignore();
        vector<string> cand_names(k+1);
        for (int i = 1; i < k+1; i++) {
            getline(cin, line);
            cand_names[i] = line;
        }
        vector<vector<int>> VOTES;
        while (getline(cin, line)) {
            if (line.size() == 0) break;
            vector<int> v;
            stringstream ss(line);
            int a;
            for (int i = 0; i < k; i++) {
                ss >> a;
                v.push_back(a);
            }
            VOTES.push_back(v);
        }
        vector<int> cancelled_candidates;
        vector<double> candidate_percentage(k+1, 0);
        bool winner_found = false;
        bool is_tie;
        int K = VOTES.size();
        vector<double> copy_cp;
        int abc= 0;
        while (true) {
            for (vector<int> vote : VOTES) {
                int i = -1;
                vector<int>::iterator it;
                do {
                    i++;
                    it = find(cancelled_candidates.begin(), cancelled_candidates.end(), vote[i]);
                } while (it != cancelled_candidates.end());
                // cout << "reading void " << vote[i] << " at " << abc << endl;
                candidate_percentage[vote[i]] = candidate_percentage[vote[i]] + ((1.0/K)*100.0);
                if (candidate_percentage[vote[i]] > 50.0000001){
                    // cout << candidate_percentage[1] + ((1.0/K)*100) << endl;
                    winner_found = true;
                    break;
                }
            }
            if (winner_found) break;
            copy_cp = candidate_percentage;
            sort(copy_cp.begin(), copy_cp.end());
            is_tie = true;
            for (int i = copy_cp.size()-1; i > 1; i--) {
                if (copy_cp[i] != copy_cp[i-1] && copy_cp[i-1] != 0) {
                    is_tie = false;
                    break;
                }
                if (copy_cp[i-1] == 0) break;
            }
            if (is_tie) {
                // cout << "here\n";
                break;
            } else {
                int min_i = 1;
                bool min_f = false;
                for (int i = 1; i < k+1; i++) {
                    if (candidate_percentage[i] == 0) {
                        vector<int>::iterator it = find(cancelled_candidates.begin(), cancelled_candidates.end(), i);
                        if (it == cancelled_candidates.end()) {
                            cancelled_candidates.push_back(i);
                            min_i = i;
                            min_f = true;
                            break;
                        }
                    }
                }
                if (!min_f) {
                    while (copy_cp[min_i] == 0) min_i++;
                    for (int l = 1; l < k+1; l++) {
                        if (candidate_percentage[l] == copy_cp[min_i]) {
                            // cout << l << " removed\n";
                            cancelled_candidates.push_back(l);
                        }
                        candidate_percentage[l] = 0;
                    }
                } else {
                    for (int l = 1; l < k+1; l++) candidate_percentage[l] = 0;
                }
            }
        }

        if (winner_found) {
            for (int i = 1; i < k+1; i++) {
                if (candidate_percentage[i] > 50) output += cand_names[i] +"\n\n";
            }
        } else if (is_tie) {
            for (int i = 1; i < k+1; i++) {
                // cout << i << " has " << candidate_percentage[i] << endl;
                // cout << " max " << copy_cp[copy_cp.size()-1] << endl;
                // cout << "for " << i << " " << to_string(candidate_percentage[i] == copy_cp[copy_cp.size()-1]) << endl;
                if (candidate_percentage[i] == copy_cp[copy_cp.size()-1]) {
                    output += cand_names[i] + "\n";
                    // cout << cand_names[i] << endl;
                }
            }
            output += "\n";
        }
        t--;
    }
    output.pop_back();
    cout << output;
    return 0;
}

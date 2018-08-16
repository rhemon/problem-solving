#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<pair<int, int>> PairList;
typedef vector<pair<int, int>> PROBLEMS;

bool comp_tasks(pair<int, int> t1, pair<int, int> t2) {
    if (t1.first == t2.first) {
        return t1.second > t2.second;
    }
    return t1.first < t2.first;
}

bool comp_diffs(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

int main() {
    PROBLEMS probs;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        PairList subtasks(k);
        for (int j = 0; j < k; j++) {
            cin >> subtasks[j].first;
        }
        for (int j = 0; j < k; j++) {
            cin >> subtasks[j].second;
        }
        sort(subtasks.begin(), subtasks.end(), comp_tasks);
        // PairList difficulties;
        pair<int, int> diff;
        int sn = 0;
        diff.second = i+1;
        // cout << "subtask of " << diff.second << endl;
        for (int j = 0; j < k-1; j++) {
            // cout << " score " << subtasks[j].first << " solved by " << subtasks[j].second << endl;
            if (subtasks[j].second > subtasks[j+1].second)
                sn++;
        }
        // cout << sn << endl;
        diff.first = sn;
        probs.push_back(diff);
    }
    sort(probs.begin(), probs.end(), comp_diffs);
    string output;
    // cout << probs.size() < < endl;
    for (int i = 0; i < probs.size(); i++) {
        cout << probs[i].second << endl;
    }
    // cout << output.size() << endl;

}

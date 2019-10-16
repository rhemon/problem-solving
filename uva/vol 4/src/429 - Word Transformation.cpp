//
// 429 - Word Transformation
//
// Created by Ridhwanul Haque 07/06/2018
//

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> find_map(vector<string> dict, string word){
    vector<string> mapped_to;
    for (string w : dict) {
        if (w == word) continue;
        if (w.size() != word.size()) continue;
        int unmatched_char= 0;
        for (int i = 0; i < w.size(); i++) {
            if (w[i] != word[i]) unmatched_char++;
            if (unmatched_char > 1) break;
        }
        if (unmatched_char == 1) mapped_to.push_back(w);
    }
    return mapped_to;
}

int count_steps(string curr, string target, map<string, vector<string>> graph) {
    if (curr == target) return 0;
    vector<string> curr_to = graph[curr];
    vector<string>::iterator it = find(curr_to.begin(), curr_to.end(), target);
    if (it != curr_to.end()) return 1;
    vector<string> visited;
    visited.push_back(curr);
    int moves = 1;
    while (true) {
        vector<string> next_layer;
        for (string w : curr_to) {
            vector<string>::iterator vit = find(visited.begin(), visited.end(), w);
            if (vit == visited.end()) {
                vector<string> sub_words = graph[w];
                next_layer.insert(next_layer.end(), sub_words.begin(), sub_words.end());
                visited.push_back(w);
            }
        }
        vector<string>::iterator wit = find(next_layer.begin(), next_layer.end(), target);
        moves++;
        if (wit != next_layer.end()) return moves;
        curr_to = next_layer;
    }
}

int main() {
    int t;
    cin >> t;
    string output;
    while (t > 0) {
        vector<string> dict;
        string word;
        while (cin >> word) {
            if (word == "*") break;
            dict.push_back(word);
        }
        map<string, vector<string>> graph;
        for (int i = 0; i < dict.size(); i++) {
            vector<string> maps_to = find_map(dict, dict[i]);
            graph[dict[i]] = maps_to;
        }

        cin.ignore();
        string query;
        while (getline(cin, query)) {
            if (query.size() == 0) break;
            stringstream ss(query);
            string current, target;
            ss >> current >> target;
            int steps = count_steps(current, target, graph);
            output += current + " " + target + " " + to_string(steps) + "\n";
        }
        output += "\n";
        t--;
    }
    output.pop_back();
    cout << output;
    return 0;
}

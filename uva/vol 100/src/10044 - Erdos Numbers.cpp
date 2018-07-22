//
// 10044 - Erdos Numbers
//
// Created by Ridhwanul Haque on 12/03/2018
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

string ERDOS =  "Erdos, P.";
map<string, int> node_depth;

set<string> get_authors(string paper) {
    set<string> names;
    string name;
    int c_count = 0;

    // cout << paper << endl;
    for (int i = 0; i < paper.size(); i++) {
        if (paper[i] == ':') {
            // cout << name << endl;
            names.insert(name);
            break;
        } else if (paper[i] == ',' && c_count == 1) {
            names.insert(name);
            name = "";
            i++;
            c_count = 0;
        } else {
            if (paper[i] == ',') c_count++;
            if (paper[i] != ' ') name.push_back(paper[i]);
            if (paper[i] == ',' && c_count == 1) name.push_back(' ');
        }
    }
    return names;
}

int erdos_num(string name, map<string, set<string>> author_conn) {
    if (author_conn.count(name) == 0) return -1;
    if (node_depth.count(name) > 0) return node_depth[name];
    set<string> searched;
    searched.insert(name);
    set<string> to_search = author_conn[name];
    int count = 1;
    // cout << "Search for " << name << endl;
    while(to_search.size() != 0) {

        if (to_search.count(ERDOS) > 0) {
            node_depth[name] = count;
            return count;
        }
        set<string> nset;
        for (string auth : to_search) {
            if (node_depth.count(auth) > 0) {
                if (node_depth[auth] == -1) continue;
                if (node_depth[auth] == 1) {
                    node_depth[name] = count+1;
                    return count+1;
                }
            }
            if (searched.count(auth) > 0) continue;
            searched.insert(auth);
            // cout << "Searching " << auth << endl;
            if (author_conn.count(auth) == 0) continue;
            set<string> aset = author_conn[auth];
            nset.insert(aset.begin(), aset.end());
        }
        to_search = nset;
        count++;


    }
    node_depth[name] = -1;
    return -1;
}

int main () {
    int t;
    cin >> t;
    string output;
    for (int sc = 1; sc <= t; sc++) {
        node_depth.erase(node_depth.begin(), node_depth.end());
        int p, n;
        cin >> p >> n;
        cin.ignore();
        map<string, set<string>> author_connection;
        for (int i = 0; i < p; i++) {
            string paper;
            getline(cin, paper);
            set<string> authors = get_authors(paper);
            for (string auth : authors) {
                if (author_connection.count(auth) == 0) {
                    set<string> conn;
                    conn.insert(authors.begin(), authors.end());
                    author_connection[auth] = conn;
                } else {
                    set<string> conn = author_connection[auth];
                    conn.insert(authors.begin(), authors.end());
                    author_connection[auth] = conn;
                }
            }
        }
        output += "Scenario " + to_string(sc) + "\n";
        vector<string> names;
        for (int i = 0; i < n; i++) {
            string name;
            getline(cin, name);
            int erdos = erdos_num(name, author_connection);
            if (erdos == -1) {
                output += name + " infinity\n";
            } else {
                output += name + " " + to_string(erdos) + "\n";
            }
        }
    }
    cout << output;
    return 0;
}

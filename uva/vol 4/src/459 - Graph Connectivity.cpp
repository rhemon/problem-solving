//
// 459 - Graph Connectivity
//
// Created by Ridhwanul Haque on 05/03/2018
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
    char n;
    vector<char> connection;
public:
    Node(char c) { n = c; };
    char name() { return n; };
    void add_conn(char c) { connection.push_back(c); };
    vector<char> connections () { return connection; };
};

vector<char> explore(Node n, vector<char> visited, vector<Node> nodes, vector<char> node_names) {
    vector<char> cs = n.connections();
    for (char c : cs) {
        vector<char>::iterator it = find(visited.begin(), visited.end(), c);
        if (it == visited.end()) {
            vector<char>::iterator cit = find(node_names.begin(), node_names.end(), c);
            if (cit != node_names.end()) {
                int pos = cit - node_names.begin();
                Node b = nodes[pos];
                visited.push_back(b.name());
                visited = explore(b, visited, nodes, node_names);
            }
        }
    }
    return visited;
}

int main() {
    vector<char> visited;
    vector<Node> nodes;
    vector<char> node_names;
    string output;
    int t;
    cin >> t;
    string edges;
    int nl = 0;
    cin.ignore();
    while (t > 0) {
        // cout << "edges " << edges << " " << edges.size() << endl;
        getline(cin, edges);
        if (edges.size() == 0) {
            // cout << "here" << endl;
            if (nodes.size() != 0) {
                int counter = 0;
                for (Node n : nodes) {
                    vector<char>::iterator it = find(visited.begin(), visited.end(), n.name());
                    if (it == visited.end()) {
                        // cout << "Visiting " << n.name() << endl;
                        visited.push_back(n.name());
                        visited = explore(n, visited, nodes, node_names);
                        counter++;
                    }
                }
                // cout << counter << endl;

                output += to_string(counter) + "\n\n";
                // cout << "Output: " << output << endl;
                t--;
            }
            visited.erase(visited.begin(), visited.end());
            nodes.erase(nodes.begin(), nodes.end());
            node_names.erase(node_names.begin(), node_names.end());
        } else {
            if (edges.size() == 1) {
                char node_till = edges[0];
                for (char i = 'A'; i <= node_till; i++) {
                    // cout << i << endl;
                    Node n(i);
                    node_names.push_back(i);
                    nodes.push_back(n);
                }
            } else {
                char node_1 = edges[0];
                char node_2 = edges[1];

                vector<char>::iterator n1_it = find(node_names.begin(), node_names.end(), node_1);
                vector<char>::iterator n2_it = find(node_names.begin(), node_names.end(), node_2);
                int n1_pos = n1_it - node_names.begin();
                int n2_pos = n2_it - node_names.begin();
                Node n1 = nodes[n1_pos];
                Node n2 = nodes[n2_pos];
                // cout << "n1 " << n1.name() << endl;
                // cout << "n2 " << n2.name() << endl;
                n1.add_conn(node_2);
                n2.add_conn(node_1);
                nodes[n1_pos] = n1;
                nodes[n2_pos] = n2;
            }
        }
    }
    output.pop_back();
    cout << output;
    return 0;
}

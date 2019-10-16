#include <iostream>
#include <algorithm>

using namespace std;

char dict['z'-'a'+1];
string key = "the quick brown fox jumps over the lazy dog";


string decrypt(string str) {
    string output;
    for (char c : str) {
        if (isalpha(c)) {
            output.push_back(dict[c-'a']);
        } else {
            output.push_back(c);
        }
    }
    return output;
}

bool assign(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ' || str[i] == '\n') continue;
        // if (!isalpha(str[i])) continue;
        int is =  count(dict, dict+('z'-'a'+1), key[i]);
        if (is == 0 && dict[str[i]-'a'] == ' ') {
            dict[str[i]-'a'] = key[i];
        } else if (dict[str[i]-'a'] != key[i]) {
            return false;
        }
    }
    if (count(dict, dict+('z'-'a'+1), ' ') != 0) return false;
    if (decrypt(str) == key) return true;
    return false;
}

void init() {
    for (int i = 0; i < 'z'-'a'+1; i++){
        dict[i] = ' ';
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    string line;
    getline(cin, line);
    string output;
    for (int i = 0; i < t; i++) {
        init();
        bool assigned = false;
        string input;
        while(getline(cin, line)) {
            if (line.size()==0) break;
            input += line + "\n";
            if (line.size() == key.size()) {
                if (!assigned) {
                    init();
                    assigned = assign(line);
                }
            }
        }

        if (!assigned) output += "No solution.\n\n";
        else {
            output += decrypt(input) + "\n";
        }
    }
    output.pop_back();
    cout << output;
    return 0;
}

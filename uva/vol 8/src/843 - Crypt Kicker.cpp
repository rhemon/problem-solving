//
// 843 - Crypt Kicker
//
// Created by Ridhwanul Haque 12/03/2018
//

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

typedef string str;
typedef vector<str> vs ;
typedef vector<int> vi;
typedef map<char, char> dict ; // 'a' = 'b', etc.
typedef vector<string>::iterator vsi;

dict empty;
map<string, vi> word_dets;
map<vi, vs> dets_word;
map<string, vi> code_dets;

vi get_det (str word) {
    vi det;
    det.push_back(word.size());
    str rep;
    for (char c : word) {
        int n = count(word.begin(), word.end(), c);
        if (n > 1 && rep.find(string(1,c)) == string::npos) {
            det.push_back(n);
            rep.push_back(c);
        }
    }
    return det;
}

dict assign(str code, str word, dict ltol) {
    vi cdet = code_dets[code];
    vi det_w = word_dets[word];
    // cout << "code " << code << endl;
    // cout << "word " << word << endl;
    if (code.size() != word.size()) return empty;
    if (cdet.size() != det_w.size()) return empty;
    // cout << "line 45" << endl;
    if (cdet != det_w) return empty;
    // cout << "line 46" << endl;
    vector<char> values;
    for (dict::iterator it = ltol.begin(); it != ltol.end(); it++) {
        values.push_back(it->second);
    }
    for (int i = 0; i < code.size(); i++) {
        char c = code[i];
        if (ltol.count(c) > 0) {
            if (ltol[c] == word[i]) continue;
            else {
                return empty;
            }
        } else {
            vector<char>::iterator it = find(values.begin(), values.end(), word[i]);
            if (it != values.end()) return empty;
            ltol[c] = word[i];
            values.push_back(word[i]);
        }
    }
    return ltol;
}

vs decrypt(vs code_set, vs word_set, dict ltol) {
    vs words;
    for (str code : code_set) {
        str word;
        for (char c : code) {
            if (ltol.count(c) == 0) break;
            else (word.push_back(ltol[c]));
        }
        vsi it = find(word_set.begin(), word_set.end(), word);
        if (word.size() != code.size() || it == word_set.end()) {
            break;
        }
        words.push_back(word);
    }
    if (words.size() != code_set.size()) {
        words.erase(words.begin(), words.end());
        for (str code : code_set) {
            str word = code;
            fill(word.begin(), word.end(), '*');
            words.push_back(word);
        }
    }
    return words;
}

dict decode(vs word_set, vs code_set, dict ltol) {
    for (int i = 0; i < code_set.size(); i++) {
        str code = code_set[i];
        vs quick_c;
        quick_c.push_back(code);
        vs quick_w = decrypt(quick_c, word_set, ltol);
        if (quick_w[0][0] != '*') continue;
        vs selected_words = dets_word[code_dets[code]];
        for (int j = 0; j < selected_words.size(); j++) {
            dict e = assign(code, selected_words[j], ltol);
            if (e == empty) {
                if (j==selected_words.size()-1) return empty;
            } else {
                vs n_code_set;
                vs n_word_set;

                for (int k = i+1; k < code_set.size(); k++) n_code_set.push_back(code_set[k]);
                for (str ww : word_set) if (ww != selected_words[j]) n_word_set.push_back(ww);

                if (n_code_set.size() == 0) return e;
                dict t = decode(n_word_set, n_code_set, e);
                if (t == empty) continue;
                else {
                    return t;
                }
            }
        }
    }
    return ltol;
}

int main(){
    int t;
    cin >> t;
    vs word_set;
    vector<vs> output;
    while (t > 0) {
        string word;
        cin >> word;
        word_set.push_back(word);
        vi wdet = get_det(word);
        word_dets[word] = wdet;
        if (dets_word.count(wdet) == 0) {
            vs ws;
            ws.push_back(word);
            dets_word[wdet] = ws;
        } else {
            vs ws = dets_word[wdet];
            ws.push_back(word);
            dets_word[wdet] = ws;
        }

        t--;
    }
    cin.ignore();
    string code_line;
    while (getline(cin, code_line)) {
        if (code_line.size()==0) break;
        stringstream cl(code_line);
        vs code_set;
        code_dets.erase(code_dets.begin(), code_dets.end());
        string code;
        while (cl >> code) {
            code_set.push_back(code);
            code_dets[code] = get_det(code);
        }
        dict ltol;
        ltol = decode(word_set, code_set, ltol);
        vs mset = decrypt(code_set, word_set, ltol);
        output.push_back(mset);
    }

    for (vs mset : output) {
        for (int i = 0; i < mset.size(); i++) {
            cout << mset[i];
            if (i == mset.size()-1) cout << "\n";
            else cout << " ";
        }
    }
    return 0;
}

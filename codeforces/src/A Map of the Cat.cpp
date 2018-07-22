// https://codeforces.com/problemset/problem/952/B

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string input;
    string cat = "";
    int  i = 0;
    string grumpy[] = {"terrible", "worse", "go die in a whole", "are you serious?","no way","don't even"};
    string normal[] = {"cool", "not bad", "don't think so", "don't touch me", "great!"};
    while (cat != "grumpy" && cat != "normal") {
        cout << i << endl;
        getline(cin, input);
        if (find(grumpy, grumpy+6, input) != grumpy+6) cat = "grumpy";
        else if (find(normal, normal+5, input) != normal+5) cat = "normal";
        cout.clear();
        cin.clear();
        i++;
    }
    cout << cat << endl;
}

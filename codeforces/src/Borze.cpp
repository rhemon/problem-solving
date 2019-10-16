#include <iostream>
using namespace std;
int main() {
    string output;
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '.') {
            output += "0";
        } else if (input[i] == '-') {
            i++;
            if (input[i] == '.') {
                output += "1";
            } else {
                output += "2";
            }
        }
    }
    cout << output << endl;
}

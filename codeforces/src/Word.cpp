#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    char c;
    string input;
    cin >> input;
    int upper = 0;
    for (char c : input) {
        if (isupper(c))
            upper++;
    }
    if (upper > (input.size()-upper))
        transform(input.begin(), input.end(), input.begin(), ::toupper);
    else
        transform(input.begin(), input.end(), input.begin(), ::tolower);
    cout << input << endl;
}

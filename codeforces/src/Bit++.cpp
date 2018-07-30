// http://codeforces.com/problemset/problem/282/A
#include <iostream>
using namespace std;
int main(){
    int i, j;
    j = 0;
    cin >> i;
    string b;
    while (i > 0) {
        i--;
        cin >> b;
        if (b == "X++" || b == "++X")
            j++;
        else
            j--;
    }
    cout << j << endl;
}

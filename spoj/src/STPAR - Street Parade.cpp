#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        if (n==0)
            break;
        vector<int> arr;
        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            arr.push_back(a);
        }

        vector<int> right;
        right.push_back(0);
        vector<int> stack;
        stack.push_back(0);
        for (int i = 0; i < n; i++) {
            if (arr[i] == right.back()+1) {
                right.push_back(arr[i]);
            } else if (stack.back() == right.back()+1) {
                right.push_back(stack.back());
                stack.pop_back();
                i--;
            } else {
                stack.push_back(arr[i]);
            }
        }
        bool f = true;
        for (int i = 2; i < stack.size(); i++) {
            if (stack[i] > stack[i-1]) {
                f = false;
                break;
            }
        }
        if (f)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}

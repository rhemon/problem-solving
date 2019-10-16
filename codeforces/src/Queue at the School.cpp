#include <iostream>
using namespace std;
int main () {
    int n, x;
    cin >> n >> x;
    string queue;
    cin >> queue;
    int i = 0;
    while (i < x) {
        string nq = queue;
        for (int j = queue.size()-2; j>= 0; j--) {
            if (queue[j]=='B' && queue[j+1] == 'G') {
                nq[j+1] = 'B';
                nq[j] = 'G';
            }
        }
        queue = nq;
        i++;
    }
    while (queue.size() > n) {
        queue.pop_back();
    }
    cout << queue << endl;
}

#include <iostream>
using namespace std;

int main() {
    int cases;
    int count = 1;
    cin >> cases;
    int monsters_num;
    int i;
    int k;
    while (cases > 0) {
        cin >> monsters_num;
        unsigned long monsters_coins[monsters_num] = {0};
        unsigned long mosts_coins_at_ind[monsters_num] = {0};
        
        for (int j = 0; j < monsters_num; j++) {
            cin >> monsters_coins[j];
        }
        mosts_coins_at_ind[monsters_num-1] = monsters_coins[monsters_num-1];
        if (monsters_num > 1) {
            mosts_coins_at_ind[monsters_num-2] = monsters_coins[monsters_num-2] > monsters_coins[monsters_num-1] ? monsters_coins[monsters_num-2]: monsters_coins[monsters_num-1];
        }
        if (monsters_num > 2) {
            k = monsters_num - 3;
            while (k >= 0) {
                if ((monsters_coins[k] + mosts_coins_at_ind[k+2]) > mosts_coins_at_ind[k+1]) {
                    mosts_coins_at_ind[k] = monsters_coins[k] + mosts_coins_at_ind[k+2];
                } else {
                    mosts_coins_at_ind[k] = mosts_coins_at_ind[k+1];
                }
                k--;
            }
        }
        cout << "Case " << count << ": " << mosts_coins_at_ind[0] << "\n";
        count++;
        cases--;
    }
}
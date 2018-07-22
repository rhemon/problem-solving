//
// 406 - Prime Cuts
//
//  Created by Ridhwanul Haque  on 3/2/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<int, bool> prime_mem;

bool is_prime(int x) {
    if (prime_mem.count(x) > 0) return prime_mem[x];
    bool is_prime = true;
    for (int i = 2; i < x/2; i++) {
        if (x % i == 0) {
            is_prime = false;
            break;
        }
    }
    prime_mem[x] = is_prime;
    return is_prime;
}

vector<int> primes_till(int x) {
    vector<int> nums;
    int j = 1;
    for (int i = 1; i <= x; i+=j) {
        if (is_prime(i)) nums.push_back(i);
        if (i == 3) j = 2;
    }
    return nums;
}

int main() {
    int n, c;
    string out;
    while (cin >> n >> c) {
        vector<int> primes = primes_till(n);
        int center = primes.size()/2;
        int lb = primes.size() % 2 == 0 ? center - c : center - (c - 1);
        int ub = center + (c-1);
        string c_primes;
        for (int i = lb; i <= ub; i++) {
            if (i < 0) continue;
            if (i > primes.size()-1) break;
            c_primes += to_string(primes[i]) + " ";
        }
        out += to_string(n) + " " + to_string(c) + ": " + c_primes;
        out.pop_back();
        out += "\n\n";
    }
    cout << out;
    return 0;
}

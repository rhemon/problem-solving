#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

struct bigint {
    bigint() : num(100) {}
    vector<ull> num;
    ull base = 1000000;
    ull base_length = 6;
    ull size;

    void init(ull a) {
        string str = to_string(a);
        reverse(str.begin(), str.end());
        size = 0;
        for (int i = 0; i < ceil((double)str.size()/(double)base_length); i++) {
            // cout << "here" << endl;
            ull a = 0;
            for (int j = 0; j < base_length && ((base_length*i)+j < str.size()); j++) {
                ull index = (base_length*i)+j;
                ull h = ::pow(10, j);
                a += ((str[index]-'0') * h);
            }
            size++;
            num[i] = a;
        }
    }

    bigint add(bigint o) {
        bigint r;
        ull s = 0;
        ull carry = 0;
        for (int i = 0; i < max(size, o.size)+1; i++) {
            ull a = i < size ? num[i] : 0;
            ull b = i < o.size ? o.num[i] : 0;
            ull c = (a+b+carry)%base;
            carry = ((a+b+carry)-c)/base;
            r.num[i] = c;
            s++;
        }
        // cout << " s " << s << endl;
        while (r.num[s-1] == 0) {
        //     // r.num.pop_back();
        //     // cout << "here" << endl;
            s--;
        }
        // cout << " s " << s << endl;

        r.size = s;

        return r;
    }

    bigint multiply(bigint o) {
        bigint r;
        r.init(0);
        r.size = 1;
        for (int i = 0; i < o.size; i++) {
            bigint x;
            ull carry = 0;
            ull m = o.num[i];
            ull s = 0;
            // cout << "m " << m << endl;
            ull k = 0;
            for (; k < i; k++) {
                x.num[k] = 0;
                s++;
            }
            // cout << "num size " << num.size() << endl;
            // cout << "num " << num << endl;
            for (int j = 0; j < size; j++) {
                ull b = num[j];
                // cout << "b " << b << endl;
                ull c = ((m*b)+carry) % base;
                // cout << "c " << c << endl;
                carry = (((m*b)+carry) - c)/base;
                // cout << "carry " << carry << endl;
                x.num[k] = c;
                k++;
                s++;
            }
            while (carry != 0) {
                ull c = carry % base;
                carry = (carry - c)/base;
                x.num[k] = c;
                k++;
                s++;
            }

            while (x.num[s-1] == 0) {
                s--;
            }

            x.size = s;

            r = r.add(x);
        }
        return r;
    }
    bigint pow(ull n, ull m, bigint rem) {
        bigint r;
        // cout << "rem ";
        // rem.print();
        // cout << "n ";
        // cout << n << endl;
        // cout << "m " << m << endl;
        if (n == 0) {
            r.init(1);
            return r;
        } else if (n % 2) {
            r = this->pow(n-1, m, rem);
            // cout << "before multiply r ";
            // r.print();
            r = r.multiply(rem);
            // cout << "r print  N mod 2==1 ";
            // r.print();
        } else {
            r = this->pow(n/2, m, rem);
            r = r.multiply(r);
            // cout << "r print  N mod 2==0 ";
            // r.print();
        }
        ull f = r.mod(m);
        // cout << f << endl;
        r.init(f);
        // r.print();
        return r;
    }

    bigint pow(ull n, ull m) {
        // cout << "here" << endl;
        ull q = this->mod(m);
        bigint rem;
        rem.init(q);
        return pow(n, m, rem);
    }

    ull mod(ull a) {

        ull res = 0;
        for (int i = size-1; i >= 0; i--)
             res = (res*base + (ull)num[i]) %a;
        return res;
    }


    void print() {
        string output = "";
        for (int i = size-1; i >= 0; i--) {
            string p = to_string(num[i]);
            while ((p.size() < base_length) && i != size-1) {
                p = "0" + p;
            }
            output += p;
        }
        cout << output << endl;
    }

};

ull gcd(ull a, ull b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b, a%b);
}



int main() {
    ull T;
    cin >> T;
    ull M = 1000000007;
    for (ull i = 0; i < T; i++) {
        ull a, b, n;
        cin >> a >> b >> n;
        ull amb = a-b;
        bigint A, B;
        A.init(a);
        B.init(b);
        if (amb == 1) {
            cout << 1 << endl;
        }else if (amb) {
            bigint AN = A.pow(n, amb);
            bigint BN = B.pow(n, amb);
            ull ANBN = (AN.add(BN)).mod(amb);
            ull d = gcd(amb, ANBN);
            cout << d % M << endl;
        } else {
            bigint AN = A.pow(n, M);
            bigint BN = B.pow(n, M);
            ull d = (AN.add(BN)).mod(M);
            cout << d << endl;
        }
    }
}

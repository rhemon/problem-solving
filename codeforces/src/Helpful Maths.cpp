// https://codeforces.com/contest/339/problem/A

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void merge(int a[], int p, int q, int r) {
    int i, j, k;
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = a[p+i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = a[q+1+j];
    }
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        k++;
        i++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int a[], int p, int r) {
    if (p < r) {
        int q = (p+r)/2;
        merge_sort(a, p, q);
        merge_sort(a, q+1,r);
        merge(a, p, q, r);
    }
}

int main () {
    int a[100];
    int n = 0;
    int i;
    string s;
    getline(cin, s);
    stringstream ss(s);
    while(ss >> i) {
        a[n] = i;
        n++;
    }

    merge_sort(a, 0, n-1);

    for (int i = 0; i < n-1; i++) {
        cout << a[i] << "+";
    }
    cout << a[n-1] << endl;
}

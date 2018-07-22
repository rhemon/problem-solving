// https://codeforces.com/contest/1006/problem/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void merge(vector<pair<int,int>>*A, int p, int q, int r, bool comp(pair<int,int> a, pair<int, int> b)) {
    int i, j, k;
    int n1 = q-p+1;
    int n2 = r-q;
    vector<pair<int,int>> L, R;
    for (int i = 0; i < n1; i++) {
        L.push_back((*A)[p+i]);
    }
    for(int j = 0; j < n2; j++) {
        R.push_back((*A)[q+1+j]);
    }
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (comp(L[i], R[j])){
            (*A)[k] = L[i];
            i++;
        } else {
            (*A)[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        (*A)[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        (*A)[k] = R[j];
        j++;
        k++;
    }
    return;
}


void merge_sort(vector<pair<int, int>>* A, int p, int r, bool comp(pair<int,int> a, pair<int, int> b)) {
    if (p < r) {
        int q = (p+r)/2;
        merge_sort(A, p, q, comp);
        merge_sort(A, q+1, r, comp);
        merge(A, p, q, r, comp);
    }
}

bool compFirst(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

bool compSecond(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> res(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i].first;
        a[i] = res[i].first;
        res[i].second = i+1;
    }

    merge_sort(&res, 0, res.size()-1, &compFirst);

    merge_sort(&res, 0, k-1, &compSecond);

    int lst = 0, sum = 0;
    int sizes[k];
    for (int i = 0; i < k-1; ++i) {
        sum += res[i].first;
        sizes[i] = res[i].second-lst;
        lst = res[i].second;
    }
    sum += res[k-1].first;
    sizes[k-1] = n-lst;
    cout << sum << endl;
    for (int i = 0; i < k-1; i++) {
        cout << sizes[i] << " ";
    }
    cout << sizes[k-1] << endl;
}

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int arr[3], sor[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sor[0] = arr[0];
    sor[1] = arr[1];
    sor[2] = arr[2];
    sort(sor, sor+3);
    cout << sor[0] << endl;
    cout << sor[1] << endl;
    cout << sor[2] << endl;
    cout << endl;
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
}

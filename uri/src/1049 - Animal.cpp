#include <iostream>
using namespace std;
int main() {
    string a, b, c;
    cin >> a >> b >> c;
    if (a == "vertebrado") {
        if (b == "ave") {
            if (c == "carnivoro") {
                cout << "aguia" << endl;
            } else if (c == "onivoro") {
                cout << "pomba" << endl;
            }
        } else if (b == "mamifero") {
            if (c == "onivoro") {
                cout << "homem" << endl;
            } else {
                cout << "vaca" << endl;
            }

        }
    } else if (a == "invertebrado") {
        if (b == "inseto") {
            if (c == "hematofago") {
                cout << "pulga" << endl;
            } else {
                cout << "lagarta" << endl;
            }
        } else if (b == "anelideo") {
            if (c == "onivoro") {
                cout << "minhoca" << endl;
            } else {
                cout << "sanguessuga" << endl;
            }
        }
    }
}

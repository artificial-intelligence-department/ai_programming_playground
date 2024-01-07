#include <iostream>
using namespace std;

int main () {
    unsigned m, n, res;

    cin >> m >> n;
    res = m*n;

    if (res%2==0) {
        cout << "Dragon";
    } else {
        cout << "Imp";
    }
}
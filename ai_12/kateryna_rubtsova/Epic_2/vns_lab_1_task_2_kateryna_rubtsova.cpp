#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main() {
    double n, m, o;
    bool e, f;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    o = n++-m;
    e = m-->n;
    f = n-->m;
    cout << "n++-m = " << o << endl;
    cout << "m-->n = " << e << endl;
    cout << "n-->m = " << f << endl;

    return 0;
}
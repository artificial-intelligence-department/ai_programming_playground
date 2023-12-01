#include <iostream>
using namespace std;

int main() {

    float n, m, r;
    bool x, x2;

    cout << "n: ";
    cin >> n;
    cout << "m: ";
    cin >> m;

    r = m - ++n; // r = m - (n+1)
    cout << "  m - ++n: " << m << " - " << n << " = " << r << endl;
    --n;

    x = ++m<++n; // x is true if (m+1) < (n+1)
    cout << "++m < ++n: " << m << " < " << n << " is " << x << endl;
    --m; --n;

    x2 = --n<++m; // x2 is true if (n-1) < (m+1)
    cout << "--n < ++m: " << m << " < " << n << " is " << x << endl;
    return 0;
}


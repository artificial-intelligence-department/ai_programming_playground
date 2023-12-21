#include <iostream>
using namespace std;

int main() {
    int m = 5;
    int n = 7;

    int result1 = m - ++n;
    bool result2 = (++m > --n);
    bool result3 = (--n < ++m);

    cout << "m-++n: " << result1 << endl;
    cout << "++m>--n: " << result2 << endl;
    cout << "--n<++m: " << result3 << endl;

    return 0;
}


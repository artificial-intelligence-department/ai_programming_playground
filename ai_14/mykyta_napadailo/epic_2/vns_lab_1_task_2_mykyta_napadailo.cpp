#include <iostream>
using namespace std;

int main()
{
    int m, n, r1, r2, r3;
    cout << "Enter a value of 'm': ";
    cin >> m;
    cout << "Enter a value of 'n': ";
    cin >> n;

    r1 = n++-m;
    r2 = m-- > n;
    r3 = n-- > m;

    cout << "n++-m = " << r1 << endl;
    cout << "m-- > n: ";
    if (r2 == 0) {
        cout << "false" << endl;
    }
    else {
        cout << "true" << endl;
    }
    cout << "n-- > m: ";
    if (r3 == 0) {
        cout << "false" << endl;
    }
    else {
        cout << "true" << endl;
    }
    
    return 0;
}
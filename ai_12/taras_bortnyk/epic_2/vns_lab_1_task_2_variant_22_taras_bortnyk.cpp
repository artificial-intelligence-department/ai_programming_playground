#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n, m;
    cout << "Print number for m" << endl;
    cin >> m;
    cout << "Print number for n" << endl;
    cin >> n;

    cout << "Result of the first expression: " << ((++n) * (++m)) << endl;
    cout << "Result of the second expression: " << boolalpha << ((m++) < (n)) << endl;
    cout << "Result of the third expression: " << boolalpha << ((n++) > (m)) << endl;

    return 0;
}


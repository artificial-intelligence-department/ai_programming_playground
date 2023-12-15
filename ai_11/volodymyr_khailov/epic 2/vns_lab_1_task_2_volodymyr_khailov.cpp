#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    const int a = n, b = m;

    cout << "Result 1: " << n++ - m << endl;

    n ,m = a, b;
    cout << "Result 2: " << (m-- > n) << endl;

    n ,m = a, b;
    cout << "Result 3: " << (n-- > m) << endl;

    return 0;
}

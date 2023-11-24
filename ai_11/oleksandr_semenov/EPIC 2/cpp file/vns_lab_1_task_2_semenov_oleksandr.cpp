#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    cout << "Result 1: " << m+--n << endl;

    ++n;
    cout << "Result 2: " << (m++<++n) << endl;

    m--; --n;
    cout << "Result 3: " << (n--< --m) << endl;
    
    return 0;
}
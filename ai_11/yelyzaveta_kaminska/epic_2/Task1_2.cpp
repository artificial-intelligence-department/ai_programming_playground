#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int m = 7;

    int result1 = n++ * m;
    cout << "Result 1: " << result1 << endl;

    int result2 = n++ < m;
    cout << "Result 2: " << result2 << endl;

    int result3 = m-- > m;
    cout << "Result 3: " << result3 << endl;

    return 0;
}

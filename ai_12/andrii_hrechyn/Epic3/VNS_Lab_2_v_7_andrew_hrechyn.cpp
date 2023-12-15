#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double result = 0.0;
    double e = 0.0001;
    int n = 0;

    while (result < e) {
        result += 1.0 / ((3 * n - 2) * (3 * n + 1));
        n++;
    }

    cout << result << endl;
    return 0;
}

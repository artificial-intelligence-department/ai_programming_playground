#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    int n; 
    double sum = 0.0;

    cout << "enter number of vals: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double term = (i % 2 == 0) ? 1.0 : -1.0;
        term /= 2 * i + 1;
        sum += term;
    }

    cout << sum << endl;

    cout << "compare with pi/4: " << M_PI/4 - sum;

    return 0;
}

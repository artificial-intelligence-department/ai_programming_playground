#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    double a, sum = 0;

    cout << "Enter the first term of the series: ";
    cin >> n;

    for (int i = 1; i <= 7; i++) {
        a = n * n / pow(n, i);
        sum += a;
    }

    cout << "The sum of 7 members of the series: " << sum << endl;

    return 0;
}

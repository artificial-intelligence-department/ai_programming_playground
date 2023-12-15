#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double b;
    cout << "Enter the value of b: ";
    cin >> b;

    double c = sqrt(2 * b + 2 * sqrt(b * b - 4)) / (sqrt(b * b - 4) + b + 2);

    cout << "Result: " << c << endl;

    return 0;
}

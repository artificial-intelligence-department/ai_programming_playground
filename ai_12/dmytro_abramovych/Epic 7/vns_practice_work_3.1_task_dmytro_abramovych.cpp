// 1
#include <iostream>
using namespace std;

int main() {
    double a, b, h;
    cout << "Enter a, b, h (cm): ";
    cin >> a >> b >> h;

    const double V = a * b * h;
    cout << "Volume: " << V << " (cubic cm)\n";

    return 0;
}

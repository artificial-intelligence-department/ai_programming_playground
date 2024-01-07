#include <iostream>
#include <cmath>

using namespace std;


int main() {
    double a=1000,b=0.0001;

    double result = (a + b) * (a + b) * (a + b) - (a * a * a + 3 * a * a * b) / (3 * a * b * b + b * b * b);

    cout << "Your result = " << result << '\n';

    return 0;
}
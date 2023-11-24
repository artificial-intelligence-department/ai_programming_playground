#include <iostream>
#include <cmath>
using std::cout, std::cin, std::endl;

void ByDouble() {
    double a = 1000, b = 0.0001;

    double  numerator   = pow(a - b, 2) - (pow(a, 2) - 2 * a*b),
            denominator = pow(b, 2),
            result      = numerator / denominator;

    cout << "The result of an expression (by doubles): " << result << "\n"; // or endl
}

void ByFloat() {
    float a = 1000, b = 0.0001;

    float   numerator   = pow(a - b, 2) - (pow(a, 2) - 2 * a*b),
            denominator = pow(b, 2),
            result      = numerator / denominator;

    cout << "The result of an expression (by floats): " << result << "\n"; // or endl
}

/**
 * <h4>Task 1-1</h4>
 * It resolves given mathematical expression: <p>
 * (a-b)^2 - (a^2 - 2ab) <p>
 * --------------------- <p>
 *          b^2
 */
int main() {
    ByFloat();
    ByDouble();
    return 0;
}

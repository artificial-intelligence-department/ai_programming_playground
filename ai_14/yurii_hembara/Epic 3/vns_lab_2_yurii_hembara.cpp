#include <iostream>
#include <cmath>

double sum = 0.0;
int n = 1;

double calculateTerm(int n) {
    return 1.0 / ((3 * n - 2) * (3 * n + 1));
}

double calculateSum(double epsilon) {
    

    while (true) {
        double term = calculateTerm(n);
        sum += term;

        if (std::abs(term) < epsilon) {
            break;
        }

        n++;
    }

    return sum;
}

int main() {
    double epsilon = 0.0001;
    double result = calculateSum(epsilon);

    std::cout << "Sum with precision " << epsilon << " is: " << result << std::endl;

    return 0;
}

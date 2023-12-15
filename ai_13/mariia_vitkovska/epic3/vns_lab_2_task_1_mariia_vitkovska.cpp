#include <iostream>
#include <cmath>

using namespace std;

const double eulerNumber = 2.71828182845904523536028747135266249775724709369995;
const int numberOfTerms = 9;

double calculateTerm(int n) {
    return exp(-sqrt(n));
    // Обчислення членів ряду
}

int main() {
    double sumTerms = 0;
    for (int n = 1; n <= 9; ++n) {
        sumTerms += calculateTerm(n);
    }
    // Cумa перших 9 членів ряду

    std::cout << "The sum of " << numberOfTerms <<  " members of a row: " << sumTerms << std::endl;

    return 0;
}

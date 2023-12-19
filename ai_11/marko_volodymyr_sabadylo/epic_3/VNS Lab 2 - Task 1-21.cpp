#include <iostream>
#include <cmath>
using namespace std;
// Функція для обчислення факторіалу
double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n = 13; // Кількість членів ряду
    double sum = 0.0;

    for (int i = 1; i <= n; ++i) {
        double term = log(factorial(i)) / pow(i, 2);
        sum += term;
    }

    cout << sum <<endl;

    return 0;
}
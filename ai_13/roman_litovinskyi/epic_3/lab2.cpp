#include <iostream>
#include <cmath>

double calculateSeries(double epsilon) {
    double sum;
    double term = 1.0;
    int n = 0;

do {
    term = 1 / ((3 * n - 2) * (3 * n + 1)); // Обчислюємо кожен член послідовності
    sum += term;                           // Додаємо поточний член до суми
    n++;                                  // Збільшуємо лічильник для наступної ітерації
} while (term > epsilon);                // Перевіряємо, чи досягнута необхідна точність (epsilon)

return sum; // Повертаємо підсумок суми

}

int main() {
    const double epsilon = 0.0001; // Точність

    double sum = calculateSeries(epsilon);//cума ряду

    std::cout << "Sum of a series with precision ε=0.0001: " << sum << std::endl;

    return 0;
}
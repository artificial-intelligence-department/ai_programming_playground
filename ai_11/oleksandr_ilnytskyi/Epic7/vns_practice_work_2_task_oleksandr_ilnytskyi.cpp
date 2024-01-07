#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int a = 5; // 4. В коді використана як мінімум одна цілочисельна константа
    int b = 3; // 1. В коді використана як мінімум одна цілочисельна змінна
    float x = 1; // 2. В коді використана як мінімум одна дійсна змінна

    for (float i = x; i <= 2.1; i += 0.1) { // 10. В коді використаний for цикл
        if (abs(x) < a/b) { // 5. В коді використані умовні оператори та розгалуження
            double result = sin(abs(a * i + b)); // 17. В коді використано математичні операції та математичні функції
            cout << "With x = " << i << " result is: " << result << endl; // 21. В коді використано оператори виведення даних
        }
        else {
            double result = sin(abs(a * i - b));
            cout << "With x = " << i << " result is: " << result << endl;
        }
    }
}
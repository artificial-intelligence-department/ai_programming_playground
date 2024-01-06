#include <iostream> // 21. Оператори виведення та введення даних
#include <cmath>    // 17. Математичні операції та функції
using namespace std;

int main() {
    // 4. Цілочисельні константи
    const int xMin = -1, xMax = 1, yMin = -2, yMax = 2;

    // 3. Дійсні змінні з подвійною точністю
    double x, y, z;
    // 2. Дійсні змінні
    double a = 1.7, b = 2.3, hy = 1.0, hx = 0.9;

    // 21. Введення даних
    cout << "Введіть x у діапазоні [-1, 1]: ";
    cin >> x;
    cout << "Введіть y у діапазоні [-2, 2]: ";
    cin >> y;

    // 5. Умовні оператори та розгалуження
    if ((x < xMin || x > xMax) || (y < yMin || y > yMax)) {
        cout << "Некоректне введення!" << endl;
        return 1; // Помилка вводу
    }

    // 5. Умовні оператори та розгалуження
    if (x * y > 0) {
        // 17. Математичні операції та функції
        z = log(sqrt(pow(a * x, 2) + pow(b * y, 3)));
    } else {
        // 17. Математичні операції та функції
        z = pow(a * x, 2) + pow(b * y, 3);
    }

    // 21. Виведення результату
    cout << "Значення функції z: " << z << endl;
    
    return 0; // 16. Параметри та аргументи функції
}

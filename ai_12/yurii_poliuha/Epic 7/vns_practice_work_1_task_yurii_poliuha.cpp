#include <iostream>  // Підключення бібліотеки для введення та виведення даних
#include <cmath>     // Підключення бібліотеки для математичних функцій
using namespace std; // Використання простору імен std

int main(){
    const double a = 0.5, b = 3.1, x = 1.4; // Оголошення та ініціалізація констант типу double
    double A, W;                            // Оголошення змінних типу double
    
    // Розв'язання виразів

    A = sqrt(fabs(a * pow(x, 2) * sin(2 * x) + exp(-2 * x) * (x + b))); // Розв'язування виразу за допомогою математичних функцій
    W = 1 / pow(cos(pow(x, 3)), 2) - x / cbrt(pow(a, 2) + pow(b, 2));   // Розв'язування виразу за допомогою математичних функцій

    // Вивід результату на екран
    
    cout << "A = " << A << endl; // Виводимо значення першого виразу
    cout << "W = " << W << endl; // Виводимо значення другого виразу

    return 0; // Повернення 0, що свідчить про успішне завершення програми
}
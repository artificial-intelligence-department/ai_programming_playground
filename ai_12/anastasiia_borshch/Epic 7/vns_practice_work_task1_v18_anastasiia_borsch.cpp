#include <iostream> // Підключення бібліотеки для введення-виведення в консоль
#include <cmath>    // Підключення бібліотеки для обчислення математичних виразів
using namespace std;

int main() {
    double a = 10.2;      // Задання значення змінних за допомогою double , бо вони не цілі
    double b = 9.3;
    double x = 2.4;
    double c = 0.5;

    double K = log(a + pow(x, 3)) + pow(sin(x / b), 2);    // Обчислення функції К

    double n = cbrt(x+a);   // Обчислання кубічного кореня за умовою
    double M = exp(-c * x) * (x + n) / (x - sqrt(fabs(x - b)));  // Обчислення функції М

    cout << "The meaning of the expression K : " << K ;  // Вивід результата К
    cout << "The meaning of the expression M : " << M ;  // Вивід результата М

    return 0; //Завершення програми
}

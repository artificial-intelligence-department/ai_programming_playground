#include <iostream>
#include <math.h>
//Вимога 4 - в коді використана як мінімум одна цілочисельна константа (дані константи надалі використовуються для обрахунків у математичних формулах)
#define a 3.2
#define b 9.3
#define x 2.4
#define c 0.5
//Вимога 13 - в коді використано структури (структура застосовується в коді для збереження результатів математичних обрахунків)
struct variables
{
    //Вимога 3 - в коді використана як мінімум одна дійсна з подвійною точністюзмінна (надалі в змінних зберігаються результати обрахунків)
    double K;
    double M;
};

int main() {
    variables variables;
    //Вимога 17 - в коді використано математичні операції та математичні функції (використано функцію log() для обчислення логарифма, pow() для піднесення в степінь, exp() для обчислення експоненти в певному степені, sqrt() для обчислення квадратного кореня та abs() для обчислення модуля числа)
    variables.K = log(a + pow(x, 3) + pow(sin(x / b), 2));
    variables.M = exp(-c * x) * (x + pow(x + a, 1/3)) / (x - sqrt(abs(x - b)));
    //Вимога 21 - в коді використано оператори виведення та введення даних (використано cout для виводу в консоль)
    std::cout << "K = " << variables.K << std::endl;
    std::cout << "M = " << variables.M << std::endl;

    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float a = 1.1; //Вимога №2: в коді використана як мінімум одна дійсна змінна
    float b = 0.004; //Вимога №3: в коді використана як мінімум одна дійсний з подвійною точністю змінна
    const float x = 0.2;

    double y = pow(sin(pow(a, 2)), 3) - cbrt(x / b); //Вимога №17: в коді використано математичні операції та математичні функції
    double z = (pow(x, 2) / a) + pow(cos(x + b), 2) * pow(cos(x + b), 2) * pow(cos(x + b), 2);

    cout << "y: " << y << endl; //Вимога №21: в коді використано оператори виведення та введення даних
    cout << "z: " << z << endl;


    return 0;
}

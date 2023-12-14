#include <iostream>
#include <cmath>
const double PI = 3.141592653589793238463;

int main() {
    const int R = 11, r = 5, h = 8; 
    //Вимога #4 - в коді використана як мінімум одна цілочисельна константа
    double l = sqrt(h*h + (R - r));
    //Вимога #17 - в коді використано математичні операції та математичні функції
    double S = (R + r)*l*PI + PI*R*R + PI*r*r;
    //Вимога #3 - в коді використана як мінімум одна дійсний з подвійною точністю змінна
    float V = (PI/3)*h*(R*R + r*r + R*r);
    //Вимога #2 - в коді використана як мінімум одна дійсна змінна
    std::cout << "Surface area of a truncated cone: " << S << "\nAnd its volume: " << V;
    return 0;
}
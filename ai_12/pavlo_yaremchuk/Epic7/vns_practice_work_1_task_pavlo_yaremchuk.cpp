#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Задання вхідних параметрів
    double pi = M_PI;
    double x = 0.25;
    double y = 1.31;
    double a = 3.5;
    double b = 0.9;
    double num, denom, addend, P;
    
    //Обчислення чисельника за вказаною формулою
    num = pow(sin(a * pow(x, 3) + b * pow(y, 2) - a * b), 3);

    //Обчислення знаменника за вказаною формулою
    denom = pow(pow(a * pow(x, 3) + b * pow(y, 2) - a, 2) + pi, 1 / 3);

    //Обчислення доданку за вказаною формулою
    addend = tan(a * pow(x, 3) + b * pow(y, 2) - a * b);

    //Обчислення виразу P за вказаною формулою
    P = abs(num / denom) + addend;

    //Виведення результату
    cout << P;

    return 0;
}
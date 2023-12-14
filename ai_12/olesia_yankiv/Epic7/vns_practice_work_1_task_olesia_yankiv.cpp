#include <iostream>
#include <cmath>
using namespace std;

// Функція для конвертації градусів в радіани
double degtorad(double degrees) 
{
    return degrees * M_PI / 180.0;
}

int main() 
{
    // Ініціалізація змінних a, b, x
    double a = 0.3, b = 0.9, x = 0.53;

    // Обчислення значення y за формулою
    double y = (pow(a, 2 * x) - pow(b, -x) * cos(a + b) * x) / fabs(x + 1);

    // Обчислення значення r за формулою
    double r = (sqrt(pow(x, x) + b)) - (pow(b, 2) * pow(sin(degtorad(x + a)), 3)) / x;

    // Виведення значень y та r на екран
    cout << "y: " << y << endl;
    cout << "r: " << r << endl;

    // Завершення програми
    return 0;
}

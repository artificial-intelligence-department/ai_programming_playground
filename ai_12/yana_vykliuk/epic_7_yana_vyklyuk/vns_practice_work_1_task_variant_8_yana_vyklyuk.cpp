#include <iostream>
#include <cmath> // Підключення бібліотеки cmath для математичних обчислень

using namespace std;

int main()
{
    // Ініціалізація змінних
    double x = 1.82; // Значення для x
    double y = 18.5; // Значення для y
    double z = -3.4; // Значення для z

    // Використання типу double для точних розрахунків
    // Обчислення гамми
    double gamma = fabs(pow(x,(y/x)) - cbrt(y/x)); // Застосування функції fabs для модуля, pow для піднесення до степеня, cbrt для кореня кубічного
    // Обчислення фі
    double fi = (x - y) * ((y - z)/(y - x))/(1 + pow((y - x), 2));

    // Виведення результатів обчислень
    cout << "gamma = " << gamma << endl;
    cout << "fi = " << fi << endl;    
    
    return 0;
}

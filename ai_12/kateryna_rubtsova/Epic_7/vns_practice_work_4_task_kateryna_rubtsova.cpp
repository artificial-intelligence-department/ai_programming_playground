#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    // Оголошення та ініціалізація змінних a і b, які є межами х
    double a = -4;
    double b = 4;
    
    // Виведення заголовка таблиці
    cout << "|   x   |   y   |" << endl;
    cout << "|-------|-------|" << endl;
    // Цикл для обчислення та виведення значень функції для різних x
    for(double x = a; x <= b; x += 0.5){
        // Обчислення значення функції
        double y = fabs(x - 2) + fabs(x + 1);
        // Виведення значень x та y у вигляді таблиці
        cout << "| " << setw(5) << x << " | " << setw(5) << y << " |" << endl;
        cout << "+-------+-------+" << endl;
    }

    return 0;
}
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    // Задання меж для x та a
    double x_min =1.0;
    double x_max =4.0;
    double a_min =-0.3;
    double a_max =0.9;
    
    // Кроки для змін x та a
    double hx = 0.5;
    double ha = 0.2;
    
    // Виведення заголовка таблиці, щоб було гарно)
    cout << "+-------+-------+-------+" << endl;
    cout << "|   x   |   a   |   z   |" << endl;
    cout << "+-------+-------+-------+" << endl;
    
    // Цикл для обчислення та виведення значень z для різних x та a
    for(double x = x_min, a = a_min; x <= x_max && a <= a_max; x += hx, a += ha){
        // Обчислення z за заданою формулою
        double z =(sqrt(x - 1.5)+pow(x, a))/cbrt(x - 2);
        // Виведення значень x, a та z в таблицю
        cout << "| " << setw(5) << x << " | " << setw(5) << a << " | " << setw(5) << z << " |" << endl;
        // Виведення горизонтальної межі між рядками таблиці
        cout << "+-------+-------+-------+" << endl;
    }
    

    return 0;
}

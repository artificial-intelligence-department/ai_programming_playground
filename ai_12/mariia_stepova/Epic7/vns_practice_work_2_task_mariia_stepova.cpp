#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double start_x = 0.3;
    double end_x = 5;
    double step = 0.1;
    //використані дійсні змінні з подвійною точністю
    int count_negative = 0;//є цілочисельною змінною, оскільки використовується для підрахунку негативних значень інтегральної частини

    for (double x = start_x; x <= end_x; x += step) { //В коді використаний for цикл
        double y = cos(x * x) * exp(-x); //В коді використано математичні операції та математичні функції
        if (y < 0) { //умовний оператор if використовується для перевірки, чи є y негативним
            count_negative++;
        }
    }

    cout << "Функція приймає негативне значення " << count_negative 
              << " разів на інтервалі [" << start_x << ", " << end_x << "] з кроком " << step << "." << endl;
              //В коді використано оператори виведення

    return 0;
}
#include <iostream>
#include <cmath> //підключаю заголовковий файл cmath, щоб мати змогу прауювати з математичними функціями

using namespace std;

const double eps = 1e-9;

void Func(double a, double x, const double ha, const double hx)
{
    double y;
    if(x>3.1+eps) //умова виходу з рекурсивної функції
    {
        return;
    } else{
        if(a<=2) //якщо а<=2, то функція обчислюється за одною формулою, в іншому випадку - за іншою
        {
            y = tan(abs(x-2*a));
        } else{
            y = cos(a*x+2);
        }
        cout << "x = " << x << "\t\ta = " << a << "\t\ty = " << y << endl; //виводжу результати
        Func(a+ha, x+hx, ha, hx); //рекурсивно викликаю функцію зі збільшенням значення а та х на їх кроки
    }
}

int main(){
    double a=0.1, x=0.5, y; //ініціалізую змінним a, x початкові значення
    const double hx = 0.2, ha = 0.3; //hx - крок, на який змінюється х; ha - крок, на який змінюється а; eps - змінна з дуже малим значенням для порівняння чисел типу double

    Func(a, x, ha, hx); //викликаю функцію для виведення результатів обчислення

    return 0;
}
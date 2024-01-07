#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Оголошення змінних x, y, z та кроку h
    double x, y, z, h = 0.5;

    //Цикл для обчислення значень y при різних x
    for (x = 1.0; x < 4.1; x += h)
    {
        //Обчислення виразу для змінної z
        z = abs(x) + pow(x, 3);

        //Обчислення значення y 
        y = z * (sin(pow(2 + x, 2)) / 2 + x);

        //Виведення результатів
        cout << "При x = " << x << "\t" << "==>" << "\t" << "y = " << y << endl;
    }

    return 0;
}
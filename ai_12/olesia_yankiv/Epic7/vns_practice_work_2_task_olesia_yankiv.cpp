#include <iostream>
#include <cmath>
using namespace std;

// Функція для обчислення значення z залежно від x та y
double calculateZ(double x, double y) 
{
   
    if (x > y) 
    {
        return (pow(x, 2)) / pow((x - 5), 3);
    } 
    else 
    { 
        return (pow((x - 2), 3)) / (y * pow((x - 5), 4));
    }
}

int main() {
    // Константи для параметрів циклів
    const double xFirst = 1, xLast = 10, xStep = 2;
    const double yFirst = -4, yLast = 3, yStep = 1;

    // Вкладений цикл для ітерації по значенням x та y
    for (double x = xFirst; x <= xLast; x += xStep) {
        for (double y = yFirst; y <= yLast; y += yStep) {
            // Обчислення z за допомогою функції calculateZ
            double z = calculateZ(x, y);
            // Виведення результату
            cout << "Для x = " << x << " та y = " << y << ", z = " << z << endl;
        }
    }

    return 0;
}



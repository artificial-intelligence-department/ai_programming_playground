#include <iostream>
#include <cmath>
#include <stdarg.h>

using namespace std;

double calculateR(int k, ...);

int main()
{
    cout << "TASK 1\n\n";
    float r, h, V;
    cout << "Calculation of the volume of the cylinder.\n";
    cout << "Enter the initial data:\n";
    cout << "Base radius (cm) > ";
    cin >> r;   // Вимога #21 - в коді використано оператори виведення та введення даних
    cout << "Cylinder height (cm) > ";
    cin >> h;

    V = M_PI * pow(r, 2) * h;

    cout << "Cylinder volume " << V << " cm square\n";


    cout << "\nTASK 2\n\n";

    cout << "Calculation of the resistance of an electric circuit consisting of three resistors connected in series.\n";
    double R1, R2, R3, R;
    cout << "Resistance 1 (ohm) > ";
    cin >> R1;
    cout << "Resistance 2 (ohm) > ";
    cin >> R2;
    cout << "Resistance 3 (ohm) > ";
    cin >> R3;

    R = calculateR(3, R1, R2, R3);

    cout << "Circuit resistance " << R << " ohm.\n";
    
    cout << "Press the <Enter> key to finish.\n";

    cin.get();
    cin.get();

    return 0;
}
double calculateR(int k, ...)   // Вимога #13 - в коді використано еліпсис, для обчислення опору кола з різною кількістю елементів.
{
    double R1, R2, R3, R;
    va_list ptr;
    va_start(ptr, k); 

    while(k--) // Вимога #9 - в коді використаний while цикл, для отримання всіх значень опорів.
    {
        R += va_arg(ptr, double);
    }

    va_end(ptr);

    return R;
}

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double z, a = 2.4, M, N; // дійсні змінні з подвійною точністю
    int x; // цілочисельна змінна
    
    cout << "Введіть значення x: "; // оператор виведення
    cin >> x; // оператор введення

    if (-3 <= x && x <= 3) // умовний оператор і розгалуження
    {
        x = 0.5;
        M = pow(a,x) * log(x + pow(2,3)); // математичні операції log, pow
        N = x + 1;

        z=M/N;

        cout << "z = " << z << endl;
    }
    else
    {
        cout << "ERROR\n";
    }

    return 0;
}
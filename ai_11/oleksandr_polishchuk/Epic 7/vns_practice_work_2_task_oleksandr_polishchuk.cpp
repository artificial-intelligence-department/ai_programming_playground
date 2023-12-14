#include <iostream>

using namespace std;

int main()
{
    double a = 2.0;//Вимога 2. в коді використана як мінімум одна дійсна змінна
    do 
    {
        double x = 1.0;
        while (x <= 8.0) //Вимога 9. в коді використаний while цикл
        {
            double y;
            if (a > x) // Вимога 5. в коді використані умовні оператори та розгалуження
                y = a*a + x;
            else if (a == x)
                y = a*a;
            else if (a < x)
                y = a*a - x;
            cout << "y = " << y <<"; a = " << a << "; x = " << x << endl;
            x += 0.5;
        }
        a += 1.0;
    } while (a <= 10.0); //Вимога 8. в коді використаний do while цикл
    return 0;
}

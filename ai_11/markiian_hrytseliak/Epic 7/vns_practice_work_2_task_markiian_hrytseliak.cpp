#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int count;
    float h=0.1;                              // Вимога 1. в коді використана як мінімум одна цілочисельна змінна
    for(float x=0.3; x<5.1; x+=h)             // Вимога 2. в коді використана як мінімум одна дійсна змінна
    {                                         // Вимога 10. в коді використаний for цикл                       
        double y=cos(x*x)*exp(-x);
        if(y<0)                               // Вимога 5. в коді використані умовні оператори та розгалуження
        {
           count++;
        }
        cout<<"y= "<<y<<endl;
    }
    cout<<"The number of times function gets negative value is: "<<count; // 21. в коді використано оператори виведення та введення даних
    return 0;
}

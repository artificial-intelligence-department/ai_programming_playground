#include <iostream>
#include <cmath>

using namespace std;

double Func(double a, double b, double x)                        // Вимога 16. в коді використано параметри та аргументи функції

{
    double c=(b*x*x-c)/(exp(a*x)-1);                             // Вимога 17. в коді використано математичні операції та математичні функції
    double S=((pow(x,3)*pow(tan(pow(x+b,2)),2)+a)/sqrt(x+b))*c;  
    return S;
}

int main()
{
    double a= 16.5, b=3.4, x=0.61;                               // Вимога 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    Func(a,b,x);
    cout<<"The value of S is: "<<Func(a,b,x);
    return 0;                    // Вимога 21. в коді використано оператори виведення та введення даних
 
}
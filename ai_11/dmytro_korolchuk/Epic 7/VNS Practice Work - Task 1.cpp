#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double P, x, y ,a ,b; //задаємо тип змінних
    x=0.25;
    y=1.31; //задаємо значення змінних
    a=3.5;
    b=0.9;
    P=abs((pow(sin(a*x*x*x+b*y*y-a*b),3))/(cbrt(pow((a*x*x*x+b*y*y -a), 2)+3.14)))+tan((a*x*x*x+b*y*y-a*b));//обчислюємо значення виразу
    cout<<P<<endl;//виводимо результат
}
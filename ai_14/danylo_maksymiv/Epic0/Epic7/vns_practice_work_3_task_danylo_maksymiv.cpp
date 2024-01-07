#include <iostream>                                                                        
#include <cmath>         
using namespace std;                //інклудим модулі потоку вводу/виводу, математичний модуль і неймспейс стд щоб не писати std::

void resistance(double r1,double r2)
{
    cout<<"The circuit resistance is:"<<(r1*r2)/(r1+r2)<<endl; /*функцція для обчислення опору на ланцюгу,приймає два значення 
                                                                з подвійною точністю - опір 1 і опір2,виводить на екран результат*/
}

void volume(double radius,double h)
{
    cout<<"The volume of the cone is:"<< (1.0/3.0)*M_PI*h*pow(radius,2)<<endl; /*функцція для обчислення обʼму конуса,приймає два значення 
                                                                            з подвійною точністю - радіус і висота,виводить на екран результат*/
}

int main()
{
    double r1,r2,radius,h;                  //ініціалізую змінні типу double для подальшої роботи
    cout<<"Enter resitance #1: ";
    cin>>r1;
    cout<<"Enter resitance #2: ";
    cin>>r2;                                    //робим запити на ввід данних та виводим опір на ланцюгу
    resistance( r1, r2);
    
    cout<<"Enter radius: ";
    cin>>radius;
    cout<<"Enter h: ";                      //робим запити на ввід данних та виводим обʼм конуса
    cin>>h;
    volume(radius,h);

}
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a=1000;
    double b=0.0001;
    float x;
    double y;

     x=(pow((a-b),3)-pow (a,3))/(pow(b,3)-3*a*pow (b,2)-3*pow (a,2) *b);
     y=(pow((a-b),3)-pow (a,3))/(pow(b,3)-3*a*pow (b,2)-3*pow (a,2) *b);
     cout<<"Лабораторна робота №1"<<endl;
     cout<<"Завдання 1"<<endl;
     cout<<"Варіант 7"<<endl;
     cout<<"Значення виразу для даних типу float: "<<x<<endl;
     cout<<"Значення виразу для даних типу double: "<<y<<endl;

     return 0;
}
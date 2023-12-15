#include <iostream>
#include <math.h>

int main()
{
    double vnesok;
    int time, n;
    double rate, suma;
    printf("Please enter deposit: ");
    scanf_s("%lf", &vnesok); // символ "&" вказує на адресу пам'яті (адреса) змінної, в яку буде зчитано значення.
    printf("Please enter years: ");
    scanf_s("%d", &time);
    printf("Please enter number of times the interest is compounded annually: ");
    scanf_s("%d", &n);
    printf("Please enter rate: ");
    scanf_s("%lf", &rate);
    char name[100];  
    printf("Enter your name: ");
    scanf_s("%s", name, _countof(name)); // _countof(name) -  Це допомагає уникнути переповнення буфера та інших проблем,

    suma = vnesok *  pow (1+ rate/n, n*time );

    printf("Hi %s, your summa = %f", name, suma);
    return 0;
}

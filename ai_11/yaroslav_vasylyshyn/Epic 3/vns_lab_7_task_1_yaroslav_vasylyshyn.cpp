#include <iostream>
#include <cstdarg>
#include <math.h>

using namespace std;

void v_to_d(int num, ...);

void v_to_d(int num, ...)
{
va_list arguments;
va_start(arguments, num);
int lastnumber;
int d=0;
int j=0;
int a[num];
for (int i = 0; i < num; i++)
{
    a[i] = va_arg(arguments, int);
    //Переведення в 10-кову
    while(a[i] != 0){
        lastnumber = a[i] % 10;
        d += lastnumber * pow(8 , j);
        j++;
        a[i] /= 10;
    } 
    j=0;
    cout<<d<<" ";
    d=0;
}
cout<<'\n';
va_end(arguments);
}

int main(){
    v_to_d(3, 15, 13, 10);
    v_to_d(6, 5, 23, 65, 25, 46, 23);
    v_to_d(7, 15, 13, 24, 35 ,36, 56, 23);
    return 0;
}
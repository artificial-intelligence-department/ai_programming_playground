#include <iostream>
#include <cmath>
using namespace std;

float x, y, z;
double n,f;


int main(){
    //задання змінних
    x= 1.82;
    y= 18.5;
    z= -3.4;
    //формули
    n=abs(pow(x,y/x)-pow(y/x,1/3));
    f=(x-y)*(y-z)/(y-x)/(1+pow(y-x,2));
    //вивід
    cout << n << endl;
    cout<<f;
}
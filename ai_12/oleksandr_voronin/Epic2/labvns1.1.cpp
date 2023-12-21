#include <iostream>
#include <cmath>
#include <cstdio>
int main(){

    double a=1000;
    double b=0.0001;
    long double c;

c= (pow(a+b,2)-(pow(a,2)+2*a*b))/pow (b,2);
std::cout << c;

}
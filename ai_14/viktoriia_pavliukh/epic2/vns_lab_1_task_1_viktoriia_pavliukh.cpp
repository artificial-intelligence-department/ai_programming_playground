#include <iostream>
#include <cstdio>
#include <cmath>

int main(){
long double a=1000, b=0.0001, c, d, e, f, g;

c=pow((a-b),3);
d=pow(a,3);
e=3*a*a*b;
f=pow(b,3);
g=3*a*b*b;

long double y=(c-(d-e))/(f-g);
printf("%lf", y);
}
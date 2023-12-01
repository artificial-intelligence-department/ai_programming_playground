#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
int main(){
    float a=100; 
    float b=0.001;
    float c, d,e, f, h, i, j, k;

    double a1=100; 
    double b1=0.001;
    double c1, d1,e1, f1, h1, i1, j1, k1;

c=pow(a+b,4);
d=(pow(a,4)+4*pow(a,3)*b);
e=c-d;
f=6*pow(a,2)*pow(b,2);
h=4*a*pow(b,3);
i=pow(b,4);
j=f+h+i;
k=e/j;

c1=pow(a1+b1,4);
d1=(pow(a1,4)+4*pow(a1,3)*b1);
e1=c1-d1;
f1=6*pow(a1,2)*pow(b1,2);
h1=4*a1*pow(b1,3);
i1=pow(b1,4);
j1=f1+h1+i1;
k1=e1/j1;

cout<<k<<endl;
cout<<k1;

return 0;
}

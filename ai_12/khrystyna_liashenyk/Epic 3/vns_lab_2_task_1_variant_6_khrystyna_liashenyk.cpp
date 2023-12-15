#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
 
int main() {
double epsylon = 0.0001, n, an, s;

for (n = 1; an >= epsylon; n++)
{
an = an*(pow(3,n+1)+pow(2,n+1))/(6*(pow(3,n)+pow(2,n)));
s += an;
}
cout<<s;
    return 0;
}

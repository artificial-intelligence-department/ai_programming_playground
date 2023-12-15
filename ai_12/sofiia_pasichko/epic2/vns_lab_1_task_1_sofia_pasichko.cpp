#include <iostream>
#include <cmath>
using namespace std;
int main()
{
double a=1000, b=0.0001, c, d, e;
c=pow((a+b), 3)-pow(a, 3);
d=3*a*pow(b, 2)+pow(b, 3)+3*pow(a, 2)*b;
e=c/d;
cout << e << endl; 
return 0;

}


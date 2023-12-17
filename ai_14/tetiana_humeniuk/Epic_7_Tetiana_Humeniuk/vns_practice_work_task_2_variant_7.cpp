#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double z(double x, int b)
{
  return 0.5*pow(4*b + x*x, 0.5);
}
double f(double x, int b)
{
  return exp(0.5*x)*pow(b,x)*(cos(z(x,b)) + sin(z(x,b)));
}
int main() 
{
    double x, y, hx;
    int b;
    hx = 0.2;
    b = 2.0;
    while(b<=8)
    {
      cout<<"b = "<<b<<":"<<endl;
      x = 1.0;
      while(x<=2.0)
      {
        y = f(x,b);
        cout<<fixed<<setprecision(1)<<"\t"<<"x = "<<x;
        cout<<"     ";
        cout<<fixed<<setprecision(2)<<"y = "<<y<<"\n"; 
        x+=hx;     
      }
      b+=2;
    }
}
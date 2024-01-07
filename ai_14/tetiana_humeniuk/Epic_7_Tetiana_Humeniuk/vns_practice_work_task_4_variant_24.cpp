#include <iostream>
#include <math.h>
using namespace std;
float f (float x)
{
  return 5*x*x-x+2;
}
float integral_trap (float a, float b, int n)
{ 
  float h, S, x; 
  h = (b - a) / n;
  S = 0;
  for (int i = 1; i<= n -1; i++)
  { 
    x = a + i * h;
    S += f(x); 
  }
  S = h/2* (f(a) + f(b) + 2*S);
  return S;
}
main() {
  float a, b, S;
  int n;
  cout<<"a = ";
  cin>>a;
  cout<<"b = ";
  cin>>b;
  cout<<"n = ";
  cin>>n;
  cout<<"Integral = "<<integral_trap(a,b,n);
  return 0;
}
#include <iostream>
#include <math.h>

using namespace std;

int main(){
  float a,b,c,d,e,f,g,h,x;
  float a = 100,b = 0.001;

  c=pow((a+b),4);
  d=pow(a,4);
  e=4*pow(a,3)*b;
  f=6*pow(a,2)*pow(b,2);
  g=4*a*pow(b,3);
  h=pow(b,4);

  x=(c-(d+e+f))/(g+h);

  cout<<"x="<<x;




}
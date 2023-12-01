#include <iostream>
#include <cmath>
using namespace std;

int main ( ) {
   float sum;
   float a,b, c;
//   double sum;
//   double a,b,c;
   c=a-b;
   a=1000;
   b=0.0001;
   sum=(pow (c,3) - pow (a,3) - 3*pow(a,2)*b)/(pow (b,3)-3*a*pow(b,2));
   cout<<sum;
}
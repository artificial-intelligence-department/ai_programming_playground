#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int a =1000;
  float b=0.0001;
  float result;
  result=(pow(a-b,3)-pow(a,3))/(pow(b,3)-3*a*pow(b,2)-3*pow(a,2)*b);
  cout<<result<<endl;
  return 0;





}
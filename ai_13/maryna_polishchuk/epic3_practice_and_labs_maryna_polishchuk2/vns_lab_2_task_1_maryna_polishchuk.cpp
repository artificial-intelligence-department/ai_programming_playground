#include <iostream>
#include <cmath>
int main ()
{
  unsigned long long factorial=1; 
  double sum=0;
  float a=0;
  for (int n=1; n <=13; n++ )
  {
    factorial *=n;
    a=(log(factorial))/pow(n,2);
    sum +=a;
  }
  std::cout << "result = " << sum << std::endl;
  return 0;
}

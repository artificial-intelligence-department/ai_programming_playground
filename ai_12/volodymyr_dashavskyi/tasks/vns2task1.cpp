#include <iostream>
#include <cstdio>
#include <cmath>
#include <math.h>
using namespace std; 

int main() {
  float s10 = 0;
  float nf = 1;
  float sumf = 1;
  int d = 1;
  int n = 10;

  while (d <= n) {
    nf *= sumf*((d/d)*(d++));
    d--;
    sumf = sumf*((d/d)*(d++));
  }

  for (int i = 1; i <= 10; i++) {
    s10 += (sumf / (n * pow(n,sqrt(n))));
  }

  cout << "Sum of first 10 elements is: " << ((n*(1+s10))/2) << endl;

  return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int main(){

  float a,b,res1,res2,res3;
  a = 1000;
  b = 0.0001;

  res1=pow((a+b),2);
  res2=(pow(a,2)+2*a*b);
  res3=pow(b,2);

  cout<<(res1-res2)/res3<<endl;

}

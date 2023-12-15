




#include <cmath>
#include <iostream>

using namespace std;

double calc(int a, float b ){
    int c = (pow((a-b),3) - (pow(a,3) - 3*a*pow(b,2)))/(pow(b,3)-3*pow(a,2)*b);
    
    return c;
}

int main()
{
    
    int a {1000};
    float b {0.0001};

    int c = (pow((a-b),3) - (pow(a,3) - 3*a*pow(b,2)))/(pow(b,3)-3*pow(a,2)*b);
   cout << c;
  return 0 ;
}

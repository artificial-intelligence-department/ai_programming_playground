




#include <cmath>
#include <iostream>

using namespace std;


int main()
{
    
    int a {1000};
    double b {0.0001};
    float r {0.0001};

    double c = (pow((a-b),3) - (pow(a,3) - 3*a*pow(b,2)))/(pow(b,3)-3*pow(a,2)*b);
    float k = (pow((a-r),3) - (pow(a,3) - 3*a*pow(r,2)))/(pow(r,3)-3*pow(a,2)*r);
   cout << c << endl;
   cout << k << endl;
  return 0 ;
}

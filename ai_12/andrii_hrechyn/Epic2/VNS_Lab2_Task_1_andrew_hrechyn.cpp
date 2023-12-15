#include <iostream>
#include <math.h>
using namespace std;

int main()
{

double a = 100, b = 0.001, c, d, f, result;

c = pow((a+b), 4);
d = (pow(a,4)+4*a*a*a*b+6*a*a*b*b);
f = 4*a*b*b*b+pow(b,4);

result = (c - d)/(f);

cout << "The result is: " << result;

return 0;
}

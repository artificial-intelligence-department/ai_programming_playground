<<<<<<< HEAD
#include <stdio.h> 
#include <iostream>
#include <math.h> 
using namespace std;
int main()
{
    double a = 1000;
    double b = 0.0001;
    double numerator1 = pow(a - b, 2.0);
    double numerator2 = (pow(a, 2.0) - 2.0 * a * b);
    double denominator = pow(b, 2);
    double f = (numerator1 - numerator2)/ denominator;
    cout<<f;
=======
#include <stdio.h> 
#include <iostream>
#include <math.h> 
using namespace std;
int main()
{
    double a = 1000;
    double b = 0.0001;
    double numerator1 = pow(a - b, 2.0);
    double numerator2 = (pow(a, 2.0) - 2.0 * a * b);
    double denominator = pow(b, 2);
    double f = (numerator1 - numerator2)/ denominator;
    cout<<f;
>>>>>>> 752bdc72e3aee37bfd7b872441d591f34f62d552
}
#include <cmath>
#include <iostream>
using namespace std;
int main() {
float a1 = 1000.0;
float b1 = 0.0001;
float c1 = pow((a1-b1), 3);
float d1 = pow (a1, 3);
float e1 = 3*a1*b1*b1;
float f1 = pow (b1, 3);
float g1 = 3*a1*a1*b1;
float result1 = (c1-(d1-e1))/(f1-g1);
cout << "The result of the calculation when a is float and b is float = " << result1 <<endl;
double a2 = 1000.0;
double b2 = 0.0001;
double c2 = pow((a2-b2), 3);
double d2 = pow (a2, 3);
double e2 = 3*a2*b2*b2;
double f2 = pow (b2, 3);
double g2 = 3*a2*a2*b2;
double result2 = (c2-(d2-e2))/(f2-g2); 
cout << "The result of the calculation when a is double and b is double = " << result2;
    return 0;
}

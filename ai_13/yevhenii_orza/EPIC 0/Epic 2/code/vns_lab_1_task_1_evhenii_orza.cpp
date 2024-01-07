#include <iostream>
#include <math.h>

using namespace std;

int main () {

    
    float a, b;

    a = 1000;
    b = 0.0001;


    float  plus1 = pow((a + b), 3);


    float plus2 = pow(a, 3) + 3*pow(a, 2) * b;


    float num1 = plus1 - plus2;
    float num2 = 3 * a * pow (b, 2) + pow(b, 3);

    float result = num1/num2;
    printf("%.3f", result);
    printf("%s, \n", " -float");
    cout << "Next in double" << endl;
    double  dplus1 = pow((a + b), 3);

    double dplus2 = pow(a, 3) + 3*pow(a, 2) * b;


    double dnum1 = dplus1 - dplus2;
    double dnum2 = 3 * a * pow (b, 2) + pow(b, 3);

    double dresult = dnum1/dnum2;

    printf("%.3f", dresult);
    printf("%s, \n ", " -double");

    cout << "Different between float and double is: \nFloat has lower precision and is utilized for storing decimal numbers with fewer digits,\nwhile double offers nearly double the precision and is employed for storing decimal numbers with more digits." << endl;
    
    
    
    
    
    return 0;

}
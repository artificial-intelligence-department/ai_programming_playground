/*
    #TASK 4.1
((a+b)^3 - a^3) / 3a(b^2) + b^3 - 3(a^2)b  
this ^^^ expression must be 1
*/

#include <iostream>
#include <cmath>
#define DATA_TYPE float
#define OUTPUT std::cout << top << " / " << down << " = " << result << std::endl

int main() 
{
    DATA_TYPE a = 1000.0, b = 0.0001;
    DATA_TYPE top, down, result;

    top = pow(a + b, 3) - (pow(a, 3));
    down = (3 * a * pow(b, 2)) + pow(b, 3) + (3 * pow(a, 2) * b);

    result = top / down;
    OUTPUT;

    return 0;
}

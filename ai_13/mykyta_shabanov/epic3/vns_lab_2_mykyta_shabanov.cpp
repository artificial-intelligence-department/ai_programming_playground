#include <iostream>
#include <math.h>


int main()
{
    long double result = 0, expectedRes = 1.5, epsilon = 0.0001;


    //main logic


    double num = 1;
    for(int n = 1; num >= epsilon; n++)
    {
        num = (1 / (pow(2, n))) + (1 / pow(3, n));
        result += num;
    }


    std::cout << result;
    return 0;
}

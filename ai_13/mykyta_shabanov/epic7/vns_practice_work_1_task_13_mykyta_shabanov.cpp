#include <math.h>
#include <iostream>

using namespace std;

float FindR(float x = 0.5, float a = 0.7, float b = 0.05)
{
    float result = 0;
    if(x <= 0 || a <= 0 || b <= 0)
        goto end; //using goto

    result = (pow(x, 3) * (x + 1)) / pow(b, 2);
    result -= pow(sin(x * (x + a)), 2);

        end:
    return result;
}

float FindS(float x = 0.5, float a = 0.7, float b = 0.05)
{
    float result = 0, cosValue;
    if(x <= 0 || a <= 0 || b <= 0)
        goto end; //using goto

    result = pow(((x * b) / a), 0.5);
    
    cosValue = cos(pow((x + b), 3));
    result += pow(cosValue, 2);

        end:
    return result;
}


int main()
{
    cout << FindR() << endl;

    cout << FindS() << endl;
}

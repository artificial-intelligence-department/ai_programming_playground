#include <iostream>
#include <cmath>

using namespace std;

const float c = 1000;
const float d = 0.0001;

int floatFunction(){
    const float c2 = pow(c, 2);
    const float c3 = pow(c, 3);
    const float d2 = pow(d, 2);
    const float d3 = pow(d, 3);

    const float shortMultiply1 = c3 - 3*c2*d + 3*c*d2 - d3;

    float firstPart1 = shortMultiply1 - c3;

    float secondPart1 = d3 - 3*c*d2 - 3*c2*d; 

    const float result1 = firstPart1 / secondPart1;

    cout << result1;


    return 0;
}

const double a = 1000;
const double b = 0.0001;

int main(){
    const double a2 = pow(a, 2);
    const double a3 = pow(a, 3);
    const double b2 = pow(b, 2);
    const double b3 = pow(b, 3);

    const double shortMultiply = a3 - 3*a2*b + 3*a*b2 - b3;

    double firstPart = shortMultiply - a3;

    double secondPart = b3 - 3*a*b2 - 3*a2*b; 

    const double result = firstPart / secondPart;

    cout << result << endl;

    floatFunction();

    return 0;
}


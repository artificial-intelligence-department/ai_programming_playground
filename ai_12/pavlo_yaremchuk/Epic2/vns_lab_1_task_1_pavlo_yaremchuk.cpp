#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    double a1 = 1000;
    double b1 = 0.0001;
    double result1 = (pow(a1 - b1, 3) - (pow(a1, 3) - 3 * pow(a1, 2) * b1)) / (pow(b1, 3)- 3 * a1 * pow(b1,2));
    cout << result1 <<endl;
    float a2= 1000;
    float b2 = 0.0001;
    float result2 = (pow(a2 - b2, 3) - (pow(a2, 3) - 3 * pow(a2, 2) * b2)) / (pow(b2, 3)- 3 * a2 * pow(b2,2));
    cout << result2 <<endl;
    return 0;
}
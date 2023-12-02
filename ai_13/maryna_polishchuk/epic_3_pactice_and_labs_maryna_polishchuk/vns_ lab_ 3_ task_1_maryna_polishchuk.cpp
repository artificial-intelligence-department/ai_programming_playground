#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x, a=0.1;
    int b=1, k=10;
    for (x=a; x <= b; x+=(b-a)/k ){
    double Y, SN = 0;
    Y = atan(x);
    double result = x; 
    for(int i = 1; i <= 40; i++)
    {
        double 
        m = pow(-1, i),
         top = pow(x, 2*i + 1), 
        bottom = 2*i + 1; 
        result += m * (top / bottom);
    }
    double result1 = x; 
    for(int i = 1; true; i++)
    {
        double 
        m = pow(-1, i), 
        top = pow(x, 2*i + 1), 
        bottom = 2*i + 1;
        result1 += m * (top / bottom);
        if (abs(m * (top / bottom)) < 0.0001) {
            break;
        }
    }
    cout << "X: " << x << "      SN: " << result << "    SE: " << result1 << "  Y: " << Y << endl;
    }   
}




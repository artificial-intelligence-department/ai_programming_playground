#include <iostream>    
#include <cmath>        
using namespace std;   

int main()              
{
    double b = 1.5;       

    dou xStart = 0.5;
    double xEnd = 3.1;
    double xStep = 0.21;

    double aStart = -0.1;
    double aEnd = -1.4;
    double aStep = 0.1;

    for(double x = xStart; x <= xEnd; x += xStep)      
    {
        for(double a = aStart; a >= aEnd; a -= aStep)  
        {
            double result;                             

            if(x<b)                                    
            {
                result = sin(fabs(a*x + pow(b, a)));   
            }
            else                                       
            {
                result = cos(fabs(a*x - pow(b, a)));
            }

            cout << "Result for x = " << x << ", a = " << a << ", y = " << result << endl;  
        }
    }

    return 0;     
}

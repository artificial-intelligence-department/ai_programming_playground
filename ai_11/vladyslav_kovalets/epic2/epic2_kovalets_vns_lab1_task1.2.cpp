#include <iostream> 
#include <math.h>

int main()
{
    float a = 1000, b = 0.0001;
    float suma1;
    suma1 = ((pow(a+b, 3)- pow (a, 3))/(3*a*pow(b,2)+pow(b, 3)+3* pow(a,2) *b  ));
    std::cout << "Pruklad = " << suma1 << "\n";
    return 0;
}

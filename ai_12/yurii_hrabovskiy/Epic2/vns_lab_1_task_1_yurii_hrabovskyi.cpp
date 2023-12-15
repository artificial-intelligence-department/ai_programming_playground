#include<iostream>
#include<math.h>

int main()
{ 
    int a=1000;
    double b=0.0001, result;
    
    result = (pow(a-b,3)-pow(a,3))/(pow(b,3)-3*a*pow(b,2)-3*b*pow(a,2));
    std::cout << result << std::endl;

    return 0;
}

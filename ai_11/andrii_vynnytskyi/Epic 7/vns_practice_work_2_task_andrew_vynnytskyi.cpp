#include <iostream>
#include <cmath>

double processing(double a , double x, double b)
{
    return sin(std::abs(a * x + pow(b, a)));
}
double processing1(double a , double x, double b)
{
    return cos(std::abs(a * x - pow(b, a)));
}
int main()
{
    double b = 1.5;
for(double i = 0.5, j = -0.1; i <= 3.1 && j >= -1.4; i+=0.21, j-=0.1)
{
    if(i < b)
    {
        std::cout<< "X = "<< i<<"\nA = "<< j<<"\nY =" <<processing(j,i,b)<<std::endl;
    }
    else
    {
        std::cout<< "X = "<< i<<"\nA = "<< j<<"\nY =" <<processing1(j,i,b)<<std::endl;
    }
}
return 0;
}
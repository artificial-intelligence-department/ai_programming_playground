#include <iostream>
#include <cmath>

double processing(double b, double x, double a)
{

    double result = pow(b , 3) * pow(tan(x), 2) - (a/ pow(sin(x/a), 2));
    return result;
}
double processing1(double b, double x, double a)
{
    double result = a*exp(-sqrt(3))*cos((b*x)/a);
    return result;
}

int main() {
    double b = 17.5, a=3.2, x = -4.8;
    std::cout << "Y = b^3 * tg^2(x) - a/(sin^2(x/a))" << std::endl;
    std::cout<<"\na = "<<a<<"\nb = "<<b<<"\nx = "<<x<<std::endl;
    printf("Y = %lf", processing(b,x,a));
    std::cout << "\nZ = a * e^(-(3^(1/2))) * cos(bx/a)" << std::endl;
    std::cout<<"\na = "<<a<<"\nb = "<<b<<"\nx = "<<x<<std::endl;
    std::cout<< "Z = "<<processing1(b,x,a)<<std::endl;
    return 0;
}

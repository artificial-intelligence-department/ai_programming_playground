#include <iostream>


int main()
{
    double a = 1000;
    double b = 0.0001;
    double x = pow(a+b,2) , y = pow(a, 2) + 2*a*b , z = pow(b, 2) , R;

    R = (x-y)/z;

    std::cout << "Результат: " << R << std::endl;

    return 0;

    


}
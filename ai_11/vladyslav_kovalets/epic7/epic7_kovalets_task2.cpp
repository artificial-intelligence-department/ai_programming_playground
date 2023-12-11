#include <iostream>
#include <cmath>

int main()
{
    int a = 2, b = 3, c = 7;
    double y, x = 0, h = 0.31;

    while(x<=5)
    {
        if(x<2)
        {
            y = pow(a, b-x) + c; 
            std::cout << "y = " <<y << std::endl;
        }
        if(2<=x && x>=4)
        {
            y = pow(b, c-x) + a;
            std::cout << "y = " <<y << std::endl;
        }
        if(x>4)
        {
            y = pow(c, a-x) + b;
            std::cout << "y = " <<y << std::endl;
        }
        x += h;
    }

    
}
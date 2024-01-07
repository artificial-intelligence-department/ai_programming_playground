#include <iostream>
#include <cmath>

int main(){
    double y, x;
    for ( x = -4; x <= 4; x += 0.5)
    {
        y = fabs(x);
        std::cout << "x = " << x << "  " << "y = " << y << std::endl; 
    }
    return 0;
}
#include <iostream>
#include <cmath>

int main(){
    double y;
    int amount = 0;
     for (double x = 0.3; x <=5.01; x +=0.1)
     {
        y = cos(pow(x,2)) * exp(-x);
        if (y < 0){
            amount++;
        }
        std::cout << "y = " << y << std::endl;
     }
     std::cout << "amount of negative reault = " << amount << std::endl;
     return 0;
}
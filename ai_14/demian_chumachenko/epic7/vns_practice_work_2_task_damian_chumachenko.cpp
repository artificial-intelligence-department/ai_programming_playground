//v-15
#include <iostream>
#include <cmath>

int main() {
    float x, a;
    double z, z1;

    //using it to make simplify the formula
    double t = 1.0 / 3;

    a = -0.3; // a > -0.5 and h = 0.2 -> a = -0.3 - the first value of a

    //x[1; 4] with step 0.5
    for(float x = 1; x <= 4; x += 0.5){
        z = (sqrt(x - 1.5) + pow(x, a)) / pow(x - 2, 1/3); // formula where 1/3 is int
        z1 = (sqrt(x - 1.5) + pow(x, a)) / pow(x - 2, t); // formula where 1/3 is double
        
        std::cout << "x = " << x << " a = " << " z = " << z << " z1 = " << z1 <<  "\n";

        a += 0.2; // making step 0.2
    }

    return 0;
}
#include <stdio.h>
#include <cmath>


int main() {
    short a=1000;
    float b=0.0001f, res;
    res=pow(a+b,3)-(pow(a,3)+3*pow(a,2)*b);
    res=res/(3*a*pow(b,2)+pow(b,3));
    printf("Result: %f\n", res);

return 0;
}

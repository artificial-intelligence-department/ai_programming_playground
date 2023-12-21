#include <iostream>
#include <math.h>
int main(){
    int a=100;   
    double b=0.001;
    double c;
 c=(pow(a-b,4) -(pow(a,4)-4*pow(a,3)*b+6*pow(a,2)*pow(b,2)))/(pow(b,4)-4*a*pow(b,3));
std::cout << c; 
return 0;

}

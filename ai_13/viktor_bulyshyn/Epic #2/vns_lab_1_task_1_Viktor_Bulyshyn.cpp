#include <cmath>
#include <iostream>
// includes
int main(){

float a = 1000;
float b = 0.0001; // 

double c = pow(a + b,2);
double d = pow(a,2)+2*a*b;
double r = c-d;
double x = r/pow(b,2); 

std::cout <<x;  
// x = answer

}
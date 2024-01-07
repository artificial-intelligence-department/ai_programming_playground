#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;


int main () {
    float a,b;
    a = 100;
    b=0.001;
    cout << "result is: " << (pow(a-b,3)-(pow(a,3)-3*a*pow(b,2)))/(pow(b,3)-3*pow(a,2)*b) << "";

 return 0;

}
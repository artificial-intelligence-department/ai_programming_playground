#include <iostream>
using namespace std;
int main(){
    float a = 100;
    float b = 0.001;
    float c = (pow(a+b,4)-(a*a*a*a+4*a*a*a*b+6*a*a*b*b))/(4*a*b*b*b+b*b*b*b);
    cout << c;
}
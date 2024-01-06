#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a=0.5, b=3.1, x=1.4;
    double alpha=0, w=0;
    alpha=sqrt(abs((a*pow(x,2)*sin(2*x))+(exp(-2 * x)*(x+b))));
    w=(1/pow(cos(x*x*x),2)-x/(pow(a*a+b*b, (1/3))));
    cout << "alpha: " << alpha << endl << "w: " << w; 
    return 0;
}
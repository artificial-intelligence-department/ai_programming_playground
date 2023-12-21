#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a=100.0, b=0.001, d, e, c;
    d=pow(a+b,4)-(pow(a,4)+4*pow(a,3)*b);
    e=6*pow(a,2)*pow(b,2)+4*a*pow(b,3)+pow(b,4);
    c=d/e;
    cout <<c;
    return 0;
}

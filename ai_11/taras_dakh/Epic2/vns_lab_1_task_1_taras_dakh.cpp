#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double a= 100;
    float b= 0.001;
    double c = pow(a-b, 4)-(pow(a,4)- 4*pow(a,3)*b);
    double d = 6*pow(a,2)*pow(b,2) - 4*a*pow(b,3) + pow(b,4);
    double result = c/d;
    cout<<"Значення виразу:"<<endl<<result;
    return 0;
}

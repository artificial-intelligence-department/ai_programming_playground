#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double x=1.77, m=0.7, a=0.5, b=1.08, Z, S;
    Z=(sin(x)/pow(1+pow(m,3)*pow(sin(x), 2),0.5))-m*x*log(m*x);
    cout<<Z<<endl;
    S=exp(-a*x)*pow(x+1, 0.5)+exp(b*x)*pow(abs(x-3), 0.5);
    cout<<S;
} 
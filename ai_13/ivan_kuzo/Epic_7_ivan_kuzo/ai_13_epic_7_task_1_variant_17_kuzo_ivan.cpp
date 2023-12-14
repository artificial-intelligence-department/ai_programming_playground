#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double a=10.2;
    double b=17.5;
    double x=-4.8;
    double Y,y1,y2,y3,y4;
    double Z,z1,z2,z3;
    y1=pow(b,3);
    y2=pow(tan(x),2);
    y3=a/pow(sin(x/a),2);
    y4=y1*y2-y3;
    Y=y4;
    cout<<"Y="<<Y<<endl;
    z1=a*pow(M_E,-1*sqrt(3));
    z2=cos(b*x/a);
    z3=z1*z2;
    Z=z3;
    cout<<"Z="<<Z<<endl;
    return 0;

}
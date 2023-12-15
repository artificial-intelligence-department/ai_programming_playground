#include<iostream>
#include<cmath>
using namespace std;
void value(double x){
    if(x>4)
        return;
    double y=2*pow(x,2)-5*x-8;
    cout<<"x="<<x<<"  y="<<y<<endl;
    x+=0.5;
    value(x);
    }
int main()
{   
    cout<<"\t\t\t\ty=2x^2-5x-8"<<endl;
    value(-4.0);
    return 0;
}
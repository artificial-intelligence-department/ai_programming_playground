#include <iostream>
#include <math.h>
#include <iomanip>
#include <math.h>
using namespace std;

double versts(double S)
{
    return  S/pow(100*1066.8, 2);
}

int main() 
{
    double a, b, c, S;
    cout<<"Calculation surface area of a parallelepiped\n";
    cout<<"Enter the initial data:\n";
    cout<<"Enter length(cm)> ";
    cin>>a;
    cout<<"Enter width(cm)> ";
    cin>>b;
    cout<<"Enter height(cm)> ";
    cin>>c;
    S = 2*(a*b + b*c + a*c);
    cout<<fixed<<setprecision(2)<< "The surface area of a parallelepiped is " << S << " cubic cm\n";
    cout<< "The surface area of a parallelepiped is ";
    cout<<fixed<<setprecision(10)<<versts(S)<<" cubic versts\n";
    return 0;
}
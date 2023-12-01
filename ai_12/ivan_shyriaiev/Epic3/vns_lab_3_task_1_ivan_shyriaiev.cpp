#include<iostream>
#include<cmath>
using namespace std;
double Factorial(double n){
    if(n<1)
        return 1;
return n*Factorial(n-1);
}
double FunctionN(double n, double x){
double ln=log(3);
double lnPower=pow(ln,n);
double xPower=pow(x,n);
    if(n<1)
        return 1;
return ( (lnPower/Factorial(n))*xPower + FunctionN(n-1,x));
}
double FunctionEpsi(double x, double num){
double e= 0.0001;
double ln=log(3);
double lnPower=pow(ln,num);
double xPower=pow(x,num);
double element=(lnPower/Factorial(num))*xPower;
if(element>e) 
        return ( (lnPower/Factorial(num))*xPower + FunctionEpsi(x,num+1));
    return 0;
}
int main(){
double n=10;
double num=0;
double x=1;
double something1, something2, y;
    while(x>=0.1){
    something1 = FunctionN(n,x);
    something2 = FunctionEpsi(x,num);

        cout<<"x="<< x << "  SN="<< something1<<"  SE="<< something2<<"  Y="<< pow(3,x)<< "\n";

            x=x-0.09;
    }
        return 0;
}
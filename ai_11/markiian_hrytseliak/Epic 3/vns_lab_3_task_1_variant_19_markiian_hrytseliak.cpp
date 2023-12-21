#include <iostream>
#include <cmath>

using namespace std;

long fact(int n){
    if (n ==0 || n==1){
        return 1;
    } 
    else
        return n*fact(n-1);
}
    
int main(){
    cout<<"VNS lab 3 "<<endl;
    cout<<"Variant 19"<<endl;
    cout<<"The sum of a range for maximum n = 20 with precision to epsilon = 0.0001 for every function is: "<<endl;
    double x,y,a,n,nse,eps = 0.0001,se,sn;
    for(x=0.1; x <= 1.01; x +=0.09)
    {
        a=0.0;
        se=0.0;
        sn= 1;
        nse=0.0;
        y=exp(2*x);

        for(n=1; n<=20; n++)
        {
        a=pow(2*x,n)/fact(n);
        sn +=a;
        }
        do{
        a=pow(2*x,nse)/fact(nse);
        se+=a;
        nse++;
        }
        while(a > eps);
        cout<<"x="<< x <<" sn="<< sn <<" se="<< se <<" y="<< y <<endl;
    }
    return 0;
}
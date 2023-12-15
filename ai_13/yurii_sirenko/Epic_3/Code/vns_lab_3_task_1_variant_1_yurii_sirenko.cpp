#include <iostream>
#include <cmath>
 
using namespace std;

int factorial(int f)
{
    int result=1;
    for(int i = 1;i<=f;i++)
    {
        result *=i;
    }
    return result;
}
int main()
{

    double s = 1;

    for(double x =0.1;x<=1;x+=(1-0.1)/10)
    {
        cout<<"X="<<x<<" "; 

        double s = 1;
        for(int n = 1;n<=10;n++)
        {   
            s+=(log(pow(3,n))*x)/factorial(n);
        }
        cout<<"SN="<<s<<" "; 

   
        double t = 1;
        for(int n = 1;(log(pow(3,n))*x)/factorial(n)>0.0001;n++)
        {
            t+=(log(pow(3,n))*x)/factorial(n);
        }
        cout<<"SE="<<t<<" "; 
        cout<<"Y="<<pow(3,x)<<"\n";

    }
    return 0;
}
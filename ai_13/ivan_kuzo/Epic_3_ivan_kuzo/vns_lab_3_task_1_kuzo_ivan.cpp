#include<iostream>
#include<cmath>
using namespace std;
int factorial(int a)
{
    int b=1;
    for (int i=1;i<=a;i++)
    {
        b*=i;
    }
    return b;
}
int main()
{
    double A = 0.1 , B = 1;
    int k = 10;
    double step = (B-A)/k;
    double epsilon = 0.0001;
    for (double x=A;x<=B;x+=step)
    {
        long double SE=0, SN=0,check=1;
        for(int n=1;n<=35;n++)
        {
            SN+=pow(-1,n)*pow(2*x,2*n)/factorial(2*n);
        }
        for(int n=1; check>epsilon; n++)
        { 
            SE+=pow(-1,n)*pow(2*x,2*n)/factorial(2*n);
            check=pow(-1,n)*pow(2*x,2*n)/factorial(2*n);
        }
        double y=2*(pow(cos(x),2)-1);
        
        cout<<"X="<<x<<"   "<<"SN="<<SN<<"    "<<"SE="<<SE<<"    "<<"Y="<<y<<endl;
    }
    return 0;
}
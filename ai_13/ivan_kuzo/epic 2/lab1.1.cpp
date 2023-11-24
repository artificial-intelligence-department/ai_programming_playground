#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    cout<<"\t\t\tvar3"<<endl;
    float a=1000.0;
    float b=0.0001;

    float arg1=pow(a+b,3);

    float a3=pow(a,3);
    float c=3*pow(a,2)*b;
    float arg2=a3+c;

    float d=3*a*pow(b,2);
    float b3=pow(b,3);
    float arg3 = d+b3;
            
    float result = (arg1-arg2)/arg3;
    cout<<"Result is: "<<result<<endl;


    double af=1000.0;
    double bf=0.0001;

    double arg1f=pow(a+b,3);
    double a3f=pow(a,3);
    double cf=3*pow(a,2)*bf;

    double arg2f=a3+cf;
    double df=3*af*pow(bf,2);
    double b3f=pow(bf,3);

    double arg3f = df+b3f;
    double resultf = (arg1f-arg2f)/arg3f;
    cout<<"Result is: "<<resultf<<endl;




    int n,m;
    cout<<"Enter n and m: ";
    cin>>n>>m;
    cout<<"n is: "<<n<<endl;
    cout<<"m is: "<<m<<endl;
    double first =n---m;
    cout<<"n---m is: "<<first<<endl;
    cout<<"n is: "<<n<<endl;
    cout<<"m is: "<<m<<endl;

    bool second = m--<n;
    cout<<"m--<n is: "<<second<<endl;
    cout<<"n is: "<<n<<endl;
    cout<<"m is: "<<m<<endl;
    
    double third = n++>m;
    cout<<"\n\n\n\n"<<second;
    cout<<"(n++>m) is: "<<third;

    cout<<"\n\n"<<boolalpha;


    return 0;
}
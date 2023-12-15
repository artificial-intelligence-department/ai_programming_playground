#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double max_h=0;
    int a,b,c;
    int abc[3];
    double p,help_v,h;
    for (int i=0;i<5;i++){
        cin>>a>>b>>c;
        a=abs(a);
        b=abs(b);
        c=abs(c);

        p=(a+b+c)/2.0;
        help_v=p*(p-a)*(p-c);
        h=2.0/a*sqrt(help_v);
        if(max_h<h){
            max_h=h;
            abc[0]=a;
            abc[1]=b;
            abc[2]=c;
        }
    }
    cout<< endl;
    for (int i=0;i<3;i++){
        if(i==0)
            cout<<"a="<<abc[i]<<endl;
        if(i==1)
            cout<<"b="<<abc[i]<<endl;
        if(i==2)
            cout<<"c="<<abc[i]<<endl;
    }
    return 0;
}
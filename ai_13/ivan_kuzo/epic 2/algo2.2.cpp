#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int ri=0;
    int d=0;
    int a,b,c;
    int N=0;
    cout<<"Enter a size of array: ";
    cin>>N;
    if (N<1)
    {
        N=1;
    }
    int r[N];
    int r1[N];
    int r2[N];

    for (int i=0; i<N;i++)
    {
        cin>> ri;
        r[i]=ri;
    }

    cout<<"Enter a 3 number you want to remove: ";
    cin>>a>>b>>c;

    for (int i=0;i<N;i++)
    {
        if (r[i]!=a && r[i]!=b && r[i]!=c)
        {
            r1[d]=r[i];
            d++;
        }
    }
    if (d<=1)
        cout<<0;
    else{
        cout<<"array of sum of numbers: ";
        for (int i=0;i<d-1;i++)
        {
            r2[i]=r1[i]+r1[i+1];
            cout<<r2[i]<<",";
        }
    }

    return 0;
}
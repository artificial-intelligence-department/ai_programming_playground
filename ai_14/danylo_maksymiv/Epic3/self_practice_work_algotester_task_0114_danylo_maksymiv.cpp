#include<iostream>

using namespace std;

int main()
{
int n,i;
cin>>n;
long long x[n];

for (i = 0;i<n;i++)
{
    cin>>x[i];

}

long long xmax=x[0],xmin=x[0];
for (i = 1;i<n;++i)
{
    if(x[i]>xmax)
    {
        xmax=x[i];
    }
}

for (i = 1;i<n;++i)
{
    if(x[i]<xmin)
    {
        xmin=x[i];
    }
}

long long c = xmax-xmin;
cout<<c;

}
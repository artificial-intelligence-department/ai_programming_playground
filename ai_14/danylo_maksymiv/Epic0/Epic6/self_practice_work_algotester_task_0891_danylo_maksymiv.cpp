#include<iostream>

using namespace std;

int main()
{
    int m,n,i;
    cin>>m;
    cin>>n;
    int a[m];
    int b[n];

    for (i = 0;i<m;i++)
    {
        cin>>a[i];
    }
    for (i = 0;i<n;i++)
    {
        cin>>b[i];
    }
    
    int minb = b[0],mina = a[0];
    
    for(i=0;i<m;i++)
    {
        if (a[i] < mina) 
        {
            mina = a[i];
        }

    }
    for(i=0;i<n;i++)
    {

        if (b[i] < minb) 
        {
            minb = b[i];
        }
    }

cout<<minb+mina;

}
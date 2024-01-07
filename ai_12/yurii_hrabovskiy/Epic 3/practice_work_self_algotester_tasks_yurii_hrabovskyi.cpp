#include<iostream>
using namespace std;

int main()
{   
    int n, m, a, b;
    cin>>n>>m;
    int ar1[n], ar2[m];

    for(int i=0; i<n; i++)
    {
        cin>>ar1[i];
    }

    for(int i=0; i<m; i++)
    {
        cin>>ar2[i];
    }
    
    
    a=ar1[0];
    for(int i=0; i<n; i++)
    {
        if (ar1[i]<a)
        {
            a=ar1[i];
        }
    }

    b=ar2[0];
    for(int i=0; i<m; i++)
    {
        if (ar2[i]<b)
        {
            b=ar2[i];
        }
    }

    cout<<a+b;
    return 0;
}

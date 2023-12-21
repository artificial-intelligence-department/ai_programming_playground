#include<iostream>
using namespace std;

int main()
{
    long long n, k;
    cin>>n>>k;
    long long a[n];
    
    for(long long i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    long long max=0, current=0;

    for(long long i=0; i<n; i++)
    {
        if (a[i]>=k)
        {
            current++;
        }
        else
        {
            if (current>max)
            {
                max=current;
            }
            current=0;  
        }
    }

    if (current>max)
    {
        max=current;
    }

    cout<<max;
       
    return 0;
}

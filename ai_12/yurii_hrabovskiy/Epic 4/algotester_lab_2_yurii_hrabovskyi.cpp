#include<iostream>
#include<climits>
using namespace std;

int main()
{
    long long N;
    cin>>N;

    long long a[N];

    for(long i=0; i<N; i++)
    {
        cin>>a[i];
    }
    
    if (N<2)
        {
            cout<<0;
        }
    
    else
    {
        long long min1=LLONG_MAX;
        long long min2=LLONG_MAX;
        for(long long i=0; i<N; i++)
        {
           if (a[i]<min1)
           {
                min2=min1;
                min1=a[i];
           }
           else if (a[i]<min2) 
           {
             min2 = a[i];
         }
     }

    
        long long max1=LLONG_MIN;
        long long max2=LLONG_MIN;
        for(long long i=0; i<N; i++)
        {
            if (a[i]>max1)
            {  
                 max2=max1;
                 max1=a[i];
            }
            else if (a[i]>max2)
            {
                max2=a[i];
            }
        }

        long long b, c;
    
        b=max1-min2;
        c=max2-min1;

        if(b<=c)
            cout<<b;
    
        else if(c<=b)
            cout<<c;
    }
    
    return 0;
}
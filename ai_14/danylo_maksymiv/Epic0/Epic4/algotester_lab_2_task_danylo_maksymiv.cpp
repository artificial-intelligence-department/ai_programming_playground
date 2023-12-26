#include <iostream>
using namespace std;

int main()
{
    int n,i=0,j=0,a,b,c;

    cin>>n;

    int arr[n];

    if(n==1)
    {
        cout<<0;
        return 0 ;
    }

    
    for (i=0;i<n;i++)
    {
        cin>>arr[i];
    }


    for (i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
            }
        }
    }
    
    
    int max = arr[n-1],min = arr[0];

    if(n==2)
    {
        cout<<max-min;
        return 0;
    }

    a = arr[n-2] - arr[0];
    b = arr[n-1]- arr[1];
    c = arr[n-1]- arr[0];

    int arr2[]={a,b,c};
    int new_min=arr2[0];

    for(i =1;i<3;i++)
    {
        if(arr2[i]<new_min)
        {
            new_min=arr2[i];
        }
    }

    cout<<new_min;
      
    return 0;
}
    
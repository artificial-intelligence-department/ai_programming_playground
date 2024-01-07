#include<iostream>
using namespace std;

int main()
{
    int N=100;
    int arr[N];

    int size;
    cin>>size;

    for(int i=0; i<size; i++)
        {
            cin>>arr[i];
        }
    
    int k;
    cin>>k;

    for(int i=k-1; i>=0; i--)
    {
        cout<<arr[i]<<" ";
    }

    for(int i=size-1; i>=k; i--)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    int j=0;
    for (int i=0; i<size; i++) 
    {
        if (arr[i]%2==0) 
        {
            arr[j++]=arr[i];
        }
    }
    size=j;
    
    cout<<endl;
    
    for(int i=k-1; i>=0; i--)
    {
        cout<<arr[i]<<" ";
    }

    for(int i=size-1; i>=k; i--)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;

}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a,b,c,N;
    cin>>N;
    int *arr=new int[N];
    for(int i=0; i<N; i++)
    {
        cin>>arr[i];
    }
    cin>>a>>b>>c;
    int x=0;
    for(int i=0; i<N; ++i)
    {
        if(arr[i] !=a && arr[i] !=b && arr[i] !=c)
        {
            arr[x++]=arr[i];
        }
    }
    N=x;
    if (N<=1)
    {
        cout<<0;
        return 0;
    }
    int Nnew=N-1;
    cout<<Nnew<<endl;
    for(int i=0; i<Nnew; i++)
    {
        cout<<arr[i]+arr[i+1]<<" ";
    }
    delete [] arr;
    return 0;
}
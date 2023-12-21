#include <iostream>

using namespace std;

int main()
{
    long N=0;
    cin>>N;
    long arr[N];
    long sum_of_bisquits=0;

    for(int i=0; i<N; i++)
    {
        cin>>arr[i];
        if(arr[i] > 1 )
        sum_of_bisquits+=(arr[i]-1);
        else
        sum_of_bisquits+=0;
    }

    cout<<sum_of_bisquits;
   
    return 0;
    
}
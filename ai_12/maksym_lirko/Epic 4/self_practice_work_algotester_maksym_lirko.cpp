#include<iostream>
using namespace std;

int main(){
    long long N,K;
    int sum=0, max1=0;

    cin>>N>>K;

    long long array[N];

    for (int i = 0; i < N; i++)
    {
        cin>>array[i];
    }


    for (int i = 0; i < N; i++)
    {
        if (array[i]>=K)
        {
            sum++;
        }
        else{
            sum=0;
        }
        max1=max(max1,sum);
    }
    
    cout<<max1<<endl;
    return 0;
}
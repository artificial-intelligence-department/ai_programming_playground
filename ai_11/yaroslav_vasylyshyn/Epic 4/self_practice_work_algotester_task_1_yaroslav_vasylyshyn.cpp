#include <iostream>

using namespace std;

int main(){
    int n,max=0;
    long long min= 10000000000;
    cin>>n;
    long long x[n];
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
        if(max<x[i])
            max=x[i];
        if(min>x[i])
            min=x[i];
    }
    cout<<max-min;
    
    return 0;
}

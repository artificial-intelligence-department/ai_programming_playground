#include<iostream>
using namespace std;

int main(){

    int n;
    long sum=0;
    cin>>n;
    int array[n];
    for (int i = 0; i < n; i++)
    {  
            cin>>array[i];
        if (array[i]>0)
        {
            sum+=array[i]-1;
        }
        else{
            sum=0;
        }
    }
    
      cout<<sum<<endl;
    
    return 0;
}
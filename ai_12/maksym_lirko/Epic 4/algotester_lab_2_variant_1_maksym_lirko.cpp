#include<iostream>
using namespace std;

int main(){
    long  N,m;
    cin>>N;

   long road[N];
    for (int i = 0; i < N; i++)
    {
        cin>>road[i];
    }

    for (int i = 0; i < N; i++)
    {
        int i2 = i;

        for (int j = i+1; j < N; j++)
        {
            if(road[j]<road[i2])
            i2 = j; 
        }
        swap(road[i],road[i2]); 
    }
    
    
    if (N==1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    else 
    {
        m=min(road[N - 2] - road[0], road[N-1] - road[1]);
    }
    cout<<m;
    
 return 0;
}
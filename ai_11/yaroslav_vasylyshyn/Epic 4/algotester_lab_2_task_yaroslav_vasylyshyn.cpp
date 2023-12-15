#include <iostream>
using namespace std;

int fmin(int r[],int N)
{
    int min=10000000;
    for (int i = 0; i < N; i++)
    {
        if(r[i]<min)
        min=r[i];
    }
    return (min);
}

int fmax(int r[],int N)
{
    int max=0;
    for (int i = 0; i < N; i++)
    {
        if(r[i]>max)
        max=r[i];
    }
    return(max);
}

int main(){
    int N,min1,min2,min3,m;
    cin>>N;
    int r[N],r_min[N-1],r_max[N-1];
    for (int i = 0; i < N; i++)
    {
        cin>>r[i];
    }
    if(N==1)
    {
        m=0;
        cout<<m;
    }else
    {
    for(int i=0;i<N-1;i++)
    {
        for(int j=N-1;j>i;j--)
        {
            if(r[j]<r[j-1])
                swap(r[j],r[j-1]);
        }
    }    

    for (int i = 1; i < N; i++)
    {
        r_min[i-1]=r[i];
    }

    for (int i = 0; i < N-1; i++)
    {
        r_max[i]=r[i];
    }

    min1=fmax(r, N)-fmin(r, N);
    min2=fmax(r_max, N-1)-fmin(r_max, N-1);
    min3=fmax(r_min, N-1)-fmin(r_min, N-1);

    if(min1<=min2 && min1<=min3)
    m=min1;
    else if(min2<=min3)
    m=min2;
    else
    m=min3;
    
    cout<<m;
    }
}
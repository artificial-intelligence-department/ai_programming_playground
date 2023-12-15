#include<iostream>
using namespace std;
int main()
{
    int N=0;
    cin>>N;
    if (N<1)
    {
        N=1;
    }
    int r[N];
    for (int i=0; i<N;i++)
    {
        int ri=0;
        cin>> ri;
        if (ri<0)
            ri=0;
        r[i]=ri;
    }
    int a,b,c;
    cin>>a>>b>>c;
    if(a<0)
        a=0;
    if(b<0)
        b=0;
    if(c<0)
        c=0;
    int N_new[N];
    int m=0;
    for (int i=0;i<N;i++)
    {
        if (r[i]!=a && r[i]!=b && r[i]!=c)
        {
            N_new[m]=r[i];
            m++;
        }
    }
    if (m<=1)
        cout<<0;
    else{
        cout<<m-1<<endl;
        int M[m-1];
        for (int i=0;i<m-1;i++)
        {
            M[i]=N_new[i]+N_new[i+1];
            cout<<M[i]<<endl;
        }
    }

    return 0;
}
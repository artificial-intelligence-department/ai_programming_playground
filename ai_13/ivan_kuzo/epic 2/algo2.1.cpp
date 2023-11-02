#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int d=0;
    int rn=0;
    int N=0;
    cout<<"Enter number of numbers: ";
    cin>>N;
    int r1[N];
    int r[N];
    if(N==0)
        N=1;
    for(int i=0;i<N;i++)
    {
        cout<<"Enter a number: ";
        cin>>rn;
        r[i]=rn;
    }
    sort(r,r+N);
    if(N==1)
        cout<<0;
    else if(N==2)
        cout<<r[1]-r[0];
    else if(r[N-1]-r[1]>r[N-2]-r[0])
        cout<<r[N-2]-r[0];
    else
        cout<<r[N-1]-r[1];









    return 0;
}
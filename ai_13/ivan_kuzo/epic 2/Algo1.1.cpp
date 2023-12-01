#include<iostream>
using namespace std;
int main()
{
    string condition;
    condition="YES";
    long long int H,M,hi,mi;
    cin>>H>>M;
    if(H<1)
        H=1;
    if(M<1)
        M=1;
    for (int i=0;i<3;i++)
    {
        cin>>hi>>mi;
        if(hi<0)
            hi=0;
        if(mi<0)
            mi=0;
        if(hi>0 && mi>0){
            condition="NO";
        }
        H-=hi;
        M-=mi;
        if (H<=0 || M<=0){
            condition="NO";
        }
    }
    cout<<condition;

    return 0;
}
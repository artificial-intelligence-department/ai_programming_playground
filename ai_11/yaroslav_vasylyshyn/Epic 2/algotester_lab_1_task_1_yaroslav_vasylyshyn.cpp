#include <iostream>
using namespace std;

int main(){
    long long H,M,h[3],m[3];
    bool tf=true;
    cin>>H>>M;
    for(int i=0;i<3;i++)
    {
        cin>>h[i]>>m[i];
        if((h[i]>0) && (m[i]>0))
        {
            tf=false;
        }
        H-=h[i];
        M-=m[i];
    }
    if((H>0) && (M>0) && (tf==true))
    {
        cout<<"YES";
    }else
    {
        cout<<"NO";
    }
    return 0;
}
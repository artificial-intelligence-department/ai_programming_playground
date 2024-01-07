#include<iostream>
#include <cstdlib>
using namespace std;

int main()
{
    long long a,b;
    cin>>a>>b;
    
    if (a-b==1 || b-a==1)
    {
        cout<<-1;
        return 0;
    }
    if(a>b)
    {
        cout<<a-1;
    }
    else if(a<b)
    {
        cout<<b-1;
    }

}
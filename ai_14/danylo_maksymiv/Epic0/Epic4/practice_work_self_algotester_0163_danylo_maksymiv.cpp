#include <iostream>
using namespace std;


int main()
{
    long l,w,u,d;

    cin>>l;
    cin>>w; 
    cin>>u;
    cin>>d;

    bool cond1 = false , cond2 = false;
    if(l <= (u+d))
    {
        cond1=true;
    }
    if(l <= w)
    {
        cond2=true;
    }


    if (cond1==true && cond2==true)
    {
        cout<<"Three times Sex on the Beach, please!";
        
    }
    else 
    {
        cout<<"Forget about the cocktails, man!";
    }

}
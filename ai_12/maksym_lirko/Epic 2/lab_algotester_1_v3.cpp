#include<iostream>
#include<math.h>
using namespace std;

int main()
{    
    long long cube[5];

    for( short i=0; i<5; i++)  
    {
        cin>>cube[i];

       if (cube[i]<=0 || cube[i] <= -pow(10, 12) || cube[i] >= pow(10, 12) )
        {
            cout<<"ERROR"<<endl;
            return 0;
        }
        if( i>0 && cube[i-1]<cube[i])
        {
            cout<<"LOSS"<<endl;
            return 0;
        }
    }
    cout<<"WIN"<<endl;
    return 0;
}


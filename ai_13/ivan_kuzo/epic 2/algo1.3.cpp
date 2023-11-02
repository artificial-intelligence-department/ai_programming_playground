#include<iostream>
#include<vector>
using namespace std;
int main()
{
    string condition="WIN";
    long long ai=0;
    vector<long long>side;
    for(int i=0;i<5;i++)
    {   
        cout<<"Enter side of the cube: ";
        cin>>ai;
        side.push_back(ai);
        if(ai<=0)
            {
                condition="ERROR";
            }
    }
    if(condition!="ERROR")
        for(int i=0;i<4;i++)
        {
            if(side[i+1]>side[i])
            {
                condition="LOSS";
            }

        }
    cout<<condition;
    return 0;
}
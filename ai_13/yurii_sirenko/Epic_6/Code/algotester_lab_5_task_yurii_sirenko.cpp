#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    char cave[n][m]; 
    for(int t = 0;t<n;t++)
    {
        for(int i = 0;i<m;i++)
        {
            cin>>cave[t][i];
        }
    }
    cout<<"\n";

    for(int i = 0;i<m;i++)
    {   
        for(int t=n-1;t!=-1;t--)
        {
            if(cave[t][i]=='S')
            {
                if(cave[t+1][i]=='O')
                {
                    cave[t+1][i]='S';
                    cave[t][i]='O';
                    t=n-1;
                }
            }
        }
    }
    for(int t = 0;t<n;t++)
    {
        for(int i = 0;i<m;i++)
        {
            cout<<cave[t][i];
        }
        cout<<"\n";
    }
}

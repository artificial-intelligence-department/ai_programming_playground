#include <iostream>
#include <cmath>
using namespace std;

int main()
{
long long H, M, hi, mi;

    cin>>H;
    cin>>M;
    if (H>pow(10, 12)||H<1||M>pow(10, 12)||M<1)
    {
        return 0;
    }
    for (int i=0; i<3; i++) 
    {
        cin>>hi;
        cin>>mi;
        if(hi>pow(10, 12)||hi<0||mi>pow(10, 12)||mi<0)
        {
        return 0;
        }
        else if (hi>0 && mi>0)
        {
            break;
        }
        else
        {
            H-=hi;
            M-=mi;
        }
    }

    if (hi>0 && mi>0)
    {
        cout<<"NO";
    }
    else if (H>0 && M>0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    
return 0;
}
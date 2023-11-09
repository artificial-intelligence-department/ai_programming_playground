#include <iostream>

using namespace std;

int main()
{
long long H, M, h, m;
bool c=true;
cin >> H >> M;
for (int i=0; i<3; i++)
    {
        cin >> h >> m;
        if (h !=0 && m !=0)
        {
            c=false;
        }
        else 
        {
            H-=h;
            M-=m;
        }
    }
if ( c==true && H>0 && M>0)
{
    cout << "YES";
}
    else
    {
       cout <<  "NO";
    }
return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long int m, h;
    long long int total[6];
    bool condition = 0;


    cin >> m >> h;

    cin >> total[0] >> total[1];
 
    cin >> total[2] >> total[3];
 
    cin >> total[4] >> total[5];

    for(int n = 0; n<3 && condition == 0; n++)
    {
        if(total[0+2*n] == 0 || total[1+2*n] == 0)
        {   
            m = m-total[0+2*n];
            h = h-total[1+2*n];
        }
        else
        {
            condition = 1;
        }
    }
    if(condition==1)
    {
        cout << "NO";
    }
    else if(m>0 && h>0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    
    return 0;
}
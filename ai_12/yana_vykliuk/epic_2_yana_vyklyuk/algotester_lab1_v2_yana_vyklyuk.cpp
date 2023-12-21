#include <iostream>

using namespace std;

long long Height1, Height2, Height3, Height4;
long long Cut1, Cut2, Cut3, Cut4; 

int main ()
{
    cin >> Height1 >> Height2 >> Height3 >> Height4;
    cin >> Cut1 >> Cut2 >> Cut3 >> Cut4;

    if (Cut1>Height1 || Cut2>Height2 || Cut3>Height3 || Cut4>Height4)
    {
        cout << "ERROR" << endl;
        return 0;
    }

    Height1 -= Cut1;
    long long max1= max(max(Height2,Height3),Height4);
    if(2*Height1>max1)
    {
        Height2 -= Cut2;
        long long max2= max(Height3,Height3);
        long long min2= min(Height1, Height2);
        if(2*min2>max2)
        {
            Height3 -= Cut3;
            long long min3= min(min(Height1,Height2),Height3);
            if(2*min3>Height4)
            {
                Height4 -= Cut4;
                if(Height1==Height2 && Height1==Height3 && Height1==Height4)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }


    return 0;
}

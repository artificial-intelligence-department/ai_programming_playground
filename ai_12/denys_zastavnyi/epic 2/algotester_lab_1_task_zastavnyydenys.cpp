#include <iostream>
#include <algorithm>
using namespace std;

long long h1, h2, h3, h4, d1, d2, d3, d4;
int main (){
    cin>>h1>>h2>>h3>>h4;
    cin>>d1>>d2>>d3>>d4;

    if (d1>h1|| d2>h2 || d3>h3 || d4>h4)
    {
        cout << "ERROR" << endl;
        return 0;
    }
    h1 -= d1;
    long long max1= max(max(h2,h3),h4);
    if(2*h1>max1)
    {
        h2 -= d2;
        long long max2= max(h3,h4);
        long long min2= min(h1,h2);
        if(2*min2>max2)
        {
            h3 -= d3;
            long long min3= min(min(h1,h2),h3);
            if(2*min3>h4)
            {
                h4 -= d4;
                if(h1==h2 && h1==h3 && h1==h4)
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
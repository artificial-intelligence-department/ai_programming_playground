#include <iostream>
#include <stdio.h>

using namespace std;

long long int H;
long long int M;

long long int h1;
long long int m1;
long long int h2;
long long int m2;
long long int h3;
long long int m3;

int main()
{
    cin >> H >> M;
    cin >> h1 >> m1 >> h2 >> m2 >> h3 >> m3;

    if ((h1 > 0 && m1 > 0) || (h2 > 0 && m2 > 0) || (h3 > 0 && m3 > 0))
    {
        cout << "NO" << endl;
    }
    else
    {
        long long int dH = H - h1 - h2 - h3;
        long long int dM = M - m1 - m2 - m3;
        if (dH > 0 && dM > 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
 
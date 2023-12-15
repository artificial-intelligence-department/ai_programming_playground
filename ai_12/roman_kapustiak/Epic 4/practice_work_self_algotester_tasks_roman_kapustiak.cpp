// Депутатські краватки
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int  n, m, x = 0;
    double max = 0, result = 0, oldResult = 0;

    cin >> n >> m;
 
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if(a[i] > max)
        {
            max = a[i];
        }
    }

    result = max;

    do
    {   
        oldResult = result;
        max /= 2;

        if(x >= m)
        {
            result += (long double) max;
        }
        else
        {
            result -= (long double) max;
        }

        x = 0;
        for (int i = 0; i < n; i++)
        {
            x += a[i] / result;
        }
    }
    while (abs(oldResult - result) >= 0.00001);

    printf("%.5f", result);

    return 0;
}

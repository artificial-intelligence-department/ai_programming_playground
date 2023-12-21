#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long i, j, vershx, vershy, tempdiff, difference = 0;
    cin >> i >> j;
    cin >> vershx >> vershy;
    long long hora[i][j];

    for (long long a = 0; a < i; a++)
    {
        for (long long b = 0; b < j; b++)
        {
            tempdiff = abs(vershx - a - 1) + abs(vershy - b - 1);
            hora[a][b] = tempdiff;
            if (tempdiff > difference)
            {
                difference = tempdiff;
            }
        }
    }

    for (long long a = 0; a < i; a++)
    {
        for (long long b = 0; b < j; b++)
        {
            cout << difference - hora[a][b] << " ";
        }
        cout << endl;
    }
    return 0;
}
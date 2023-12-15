#include <iostream>
#include <cmath>
using namespace std;

int funkForK(int k);
int funcForP(int p);
int funcForZ(int z);

int main()
{
    int n;
    cin >> n;
    char letters[n];
    int result = 15; // Початкове значення result - 13

    for (int i = 0; i < n; i++)
    {
        cin >> letters[i];

        if (i == 0)
        {
            if (letters[i] == 'k')
            {
                result = funkForK(result);
            }
            else if (letters[i] == 'p')
            {
                result = funcForP(result);
            }
            else if (letters[i] == 'z')
            {
                result = funcForZ(result);
            }
        }
        else
        {
            if (letters[i] == 'k')
            {
                result = funkForK(result);
            }
            else if (letters[i] == 'p')
            {
                result = funcForP(result);
            }
            else if (letters[i] == 'z')
            {
                result = funcForZ(result);
            }
        }
    }

    cout << result;

    return 0;
}

int funkForK(int k)
{
    k = max(k - 1, 0);
    return k;
}

int funcForP(int p)
{
    if (p != 0)
    {
        p = 15;
    }
    else
    {
        p = 0;
    }
    return p;
}

int funcForZ(int z)
{
    if (z != 0)
    {
        z = 0;
    }
    else
    {
        z = 15;
    }
    return z;
}

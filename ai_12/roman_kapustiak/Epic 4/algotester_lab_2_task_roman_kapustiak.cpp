#include <iostream>

using namespace std;

int main()
{
    int N, a, b, c, M, aIndex = -1, bIndex = -1, cIndex = -1;

    if(!(cin >> N && N > 1))
    {
        cout << "Wrong input!\n";
        return 1;
    }

    int r[N];

    for (int i = 0; i < N; i++)
    {
        if(!(cin >> r[i] && r[i] > 0))
        {
            cout << "Wrong input!\n";
            return 1;
        }
    }

    if(!(cin >> a && a > 0 && cin >> b && b > 0 && cin >> c && c > 0))
    {
        cout << "Wrong input!\n";
        return 1;
    }
    
    M = N;

    // Search for elements to delete
    for (int i = 0; i < N; i++)
    {
        if (a == r[i])
        {
            aIndex = i;
            M -= 1;
        }
        else if (b == r[i])
        {
            bIndex = i;
            M -= 1;
        }
        else if (c == r[i])
        {
            cIndex = i;
            M -= 1;
        }
    }

    if (M - 1 < 1)
    {
        cout << 0;
        return 0;
    }
    cout << M-1 << "\n";

    // Creation of a new array without elements a, d, c
    int rNew[M];

    for (int i = 0, j = 0; i < N; i++)
    {   
        if (i != aIndex && i != bIndex && i != cIndex)
        {
            rNew[j] = r[i];
            j++; 
        }        
    }

    for (int i = 0; i < M-1; i++)
    {
        cout << rNew[i] + rNew[i+1] << " ";
    }

    return 0;
}


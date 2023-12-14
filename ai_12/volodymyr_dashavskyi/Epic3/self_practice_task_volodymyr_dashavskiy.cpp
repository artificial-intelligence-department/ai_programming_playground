#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long n;
    int K = 0;
    int V = 0;
    int A = 0;
    int B = 0;

    cin >> n;

    char arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'K')
        {
            ++K;
        }
        else if (arr[i] == 'V')
        {
            ++V;
        }

        if (K >= 11 && (K - V) >= 2)
        {
            A++;
            K = 0;
            V = 0;
        }
        if (V >= 11 && (V - K) >= 2)
        {
            B++;
            K = 0;
            V = 0;
        }
    }

    if (K > 0 || V > 0)
    {
        cout << A << ":" << B << endl;
        cout << K << ":" << V << endl;
    }
    else
    {
        cout << A << ":" << B << endl;
    }

    return 0;
}

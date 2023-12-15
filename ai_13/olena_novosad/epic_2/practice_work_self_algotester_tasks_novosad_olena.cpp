#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int amount1 = 0;
    int amount2 = 0;

    for (int i = 0; i < n; i++)
    {
        int coin;
        cin >> coin;
        if (coin == 2)
        {
            amount2++;
        }
        else if (coin == 1)
        {
            amount1++;
        }
    }
    int sum = amount2 * 2 + amount1;

    if (sum % 2 > 0)
    {
        cout << "NO";
    }
    else if ((amount1 % 2 == 0 && amount2 % 2 == 0) || (amount1 % 2 == 0 && amount2 % 2 > 0))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
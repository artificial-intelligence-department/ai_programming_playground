#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    long double h1, h2, h3, h4, d1, d2, d3, d4, a1, a2, a3, a4, maxi, mini;
    string result;

    cin >> h1 >> h2 >> h3 >> h4;

    cin >> d1;
    cin >> d2;
    cin >> d3;
    cin >> d4;

    for (int i = 0; i < 1; i++)
    {
        h1 = h1 - d1;
        maxi = max({h1, h2, h3, h4});
        mini = min({h1, h2, h3, h4});

         if (mini < 0)
        {
            result = "ERROR";
            break;
        } else if (maxi >= 2 * mini && mini >= 0)
        {
            result = "NO";
        }
        h2 = h2 - d2;
        maxi = max({h1, h2, h3, h4});
        mini = min({h1, h2, h3, h4});
        if (mini < 0)
        {
            result = "ERROR";
            break;
        }
        else if (maxi >= 2 * mini && mini >= 0)
        {
            result = "NO";
        }
        h3 = h3 - d3;
        maxi = max({h1, h2, h3, h4});
        mini = min({h1, h2, h3, h4});
        if (mini < 0)
        {
            result = "ERROR";
            break;
        }
        else if (maxi >= 2 * mini && mini >= 0)
        {
            result = "NO";
        }
        h4 = h4 - d4;
        maxi = max({h1, h2, h3, h4});
        mini = min({h1, h2, h3, h4});

        if (mini < 0)
        {
            result = "ERROR";
            break;
        }
        else if (maxi >= 2 * mini && mini >= 0)
        {
            result = "NO";
        }
        if (mini > 0 && h1 == h2 && h1 == h3 && h1 == h4 && result.empty())
        {
            result = "YES";
        }
        else
        {
            result = "NO";
        }
    }
    cout << result;

    return 0;
}
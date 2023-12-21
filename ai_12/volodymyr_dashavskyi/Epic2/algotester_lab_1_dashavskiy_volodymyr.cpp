#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<long long> cubes;
    bool mistake = false;
    bool win = true;
    for (int i = 0; i < 5; i++)
    {
        long long temp;
        cin >> temp;
        cubes.push_back(temp);
        long long lastcube = cubes[i - 1];
        if (cubes[i] <= 0)
        {
            cout << "ERROR" << endl;
            mistake = true;
            break;
        }
        if (i == 0)
        {
            lastcube = cubes[i];
        }
        if (cubes[i] <= lastcube)
        {
            lastcube = cubes[i];
        }
        else
        {
            cout << "LOSS" << endl;
            win = false;
            break;
        }
    }

    if (!mistake && win)
    {
        cout << "WIN" << endl;
    }

    return 0;
}

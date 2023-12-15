#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<long long> tableLegs = {};

    for (int i = 0; i < 4; i++)
    {
        long long tableLeg;
        cin >> tableLeg;
        tableLegs.push_back(tableLeg);
    }

    vector<long long> tableCuts = {};

    for (int i = 0; i < 4; i++)
    {
        long long tableCut;
        cin >> tableCut;
        tableCuts.push_back(tableCut);
    }

    for (int i = 0; i < 4; i++)
    {
        if (tableCuts[i] > tableLegs[i])
        {
            cout << "ERROR";
            return 0;
        }
    }

    long long minLeg = 0;
    long long maxLeg = 0;

    minLeg = tableLegs[0];

    for (int i = 0; i < 4; i++)
    {

        tableLegs[i] = tableLegs[i] - tableCuts[i];

        if (minLeg > tableLegs[i])
        {
            minLeg = tableLegs[i];
        }

        maxLeg = tableLegs[0];

        for (int j = 0; j < 4; j++)
        {
            if (maxLeg < tableLegs[j])
            {
                maxLeg = tableLegs[j];
            }
        }

        if (minLeg <= maxLeg / 2)
        {
            cout << "NO";
            return 0;
        }
    }

    if (tableLegs[0] == tableLegs[1] && tableLegs[1] == tableLegs[2] && tableLegs[2] == tableLegs[3] && tableLegs[0] != 0 && minLeg > maxLeg / 2)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}

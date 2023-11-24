#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> tableLegs = {};
    for (int i = 0; i < 4; i++)
    {
        int tableLeg;
        cin >> tableLeg;
        tableLegs.push_back(tableLeg);
    }

    vector<int> tableCuts = {};

    for (int i = 0; i < 4; i++)
    {
        int tableCut;
        cin >> tableCut;
        tableCuts.push_back(tableCut);
    }

    int maxLeg = tableLegs[0];
    int minLeg = tableLegs[0];

    for (int i = 0; i < tableLegs.size(); i++)
    {
        int currentLeg = tableLegs[i] - tableCuts[i];
        if (currentLeg <= 0)
        {
            cout << "ERROR";
            return 0;
        }
        if (maxLeg < currentLeg)
        {
            maxLeg = currentLeg;
        }
        if (minLeg > currentLeg)
        {
            minLeg = currentLeg;
        }
    }

    if (maxLeg > 2 * minLeg)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }

    return 0;
}

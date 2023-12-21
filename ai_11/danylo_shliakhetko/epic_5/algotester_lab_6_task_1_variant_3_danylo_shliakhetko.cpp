#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> getPossibleValues(vector<vector<int>> fields, int first, int second)
{
    int size = fields.size();

    vector<int> result;

    for (int i = 1; i <= size; i++)
    {
        result.push_back(i);
    }

    for (int i = 0; i < size; i++)
    {
        auto answer = find(result.begin(), result.end(), fields[i][second]);
        if (answer != result.end())
        {
            result.erase(answer);
        }
    }

    for (int i = 0; i < size; i++)
    {
        auto answer = find(result.begin(), result.end(), fields[first][i]);
        if (answer != result.end())
        {
            result.erase(answer);
        }
    }

    return result;
}

int main()
{
    int size;
    cin >> size;
    vector<vector<int>> fields;

    for (int i = 0; i < size; i++)
    {
        vector<int> currentArr;
        string line;
        cin >> line;

        for (int j = 0; j < line.size(); j++)
        {
            int currentNumber = int(line[j]) - 48;
            currentArr.push_back(currentNumber);
        }

        fields.push_back(currentArr);
    }

    int coordinatesSize;
    cin >> coordinatesSize;
    vector<pair<int, int>> coordinates;

    for (int i = 0; i < coordinatesSize; i++)
    {
        int x, y;

        cin >> x >> y;

        pair<int, int> currentPair = make_pair(x - 1, y - 1);

        coordinates.push_back(currentPair);
    }

    for (int i = 0; i < coordinatesSize; i++)
    {
        if (fields[coordinates[i].first][coordinates[i].second] != 0)
        {
            cout << 1 << "\n"
                 << fields[coordinates[i].first][coordinates[i].second] << "\n\n";
        }
        else
        {
            vector<int> possibleValues = getPossibleValues(fields, coordinates[i].first, coordinates[i].second);

            cout << possibleValues.size() << "\n";

            for (int j = 0; j < possibleValues.size(); j++)
            {
                cout << possibleValues[j] << " ";
            }
            cout << "\n\n";
        }
    }

    return 0;
}
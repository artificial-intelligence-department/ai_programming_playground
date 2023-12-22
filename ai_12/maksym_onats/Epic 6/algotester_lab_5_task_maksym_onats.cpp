#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int sizeN, sizeM, x, y;
    cin >> sizeN >> sizeM;
    cin >> x >> y;

    x -= 1;
    y -= 1;

    int basev = abs(x) + abs(y);
    int mini = basev;

    vector<vector<int>> map(sizeN, vector<int>(sizeM, 0));

    for (int i = 0; i < sizeN; ++i)
    {
        for (int j = 0; j < sizeM; ++j)
        {
            int distance = abs(i - x) + abs(j - y);
            map[i][j] = basev - distance;

            if (mini > map[i][j])
            {
                mini = map[i][j];
            }
        }
    }

    for (int i = 0; i < sizeN; ++i)
    {
        for (int j = 0; j < sizeM; ++j)
        {
            cout << map[i][j] - mini << " ";
        }
        cout << endl;
    }

    return 0;
}

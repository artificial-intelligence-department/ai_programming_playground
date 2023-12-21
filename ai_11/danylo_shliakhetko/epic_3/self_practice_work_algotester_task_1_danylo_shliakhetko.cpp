#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long previousCube;
    vector<long long> cubes;

    for (int i = 0; i < 5; i++)
    {
        long long input;
        cin >> input;
        cubes.push_back(input);
    }

    for (int i = 0; i < 5; i++)
    {
        long long cube = cubes[i];
        if (cube <= 0)
        {
            cout << "ERROR";
            return 0;
        }
        if (i > 0)
        {
            if (previousCube < cube)
            {
                cout << "LOSS";
                return 0;
            }
        }
        previousCube = cube;
    }
    cout << "WIN";
    return 0;
}
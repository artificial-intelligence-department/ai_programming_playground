#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int speed;
        cin >> speed;
        arr.push_back(speed);
    }

    int droneL = 0;
    int droneR = n - 1;

    int speedL;
    int speedR;

    while (true)
    {
        speedL = arr[droneL];
        speedR = arr[droneR];

        if (droneL > droneR)
        {
            cout << droneL + 1 << " " << droneR + 1 << "\n"
                 << "Miss";
            return 0;
        }
        if (droneL == droneR)
        {
            cout << droneL + 1 << " " << droneR + 1 << "\n"
                 << "Collision";
            return 0;
        }
        if (droneL + 1 == droneR)
        {
            cout << droneL + 1 << " " << droneR + 1 << "\n"
                 << "Stopped";
            return 0;
        }
        // cout << droneL << " - " << droneR << "\n";
        droneL += speedL;
        droneR -= speedR;
    }

    return 0;
}
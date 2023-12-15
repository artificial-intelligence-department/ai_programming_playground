#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int leftDrone = 0, rightDrone = n - 1;
    while(true) {
        if (leftDrone == rightDrone)
        {
            cout << leftDrone + 1 << " " << rightDrone + 1 << endl;
            cout << "Collision"; 
            return 0;
        }
        else if (rightDrone - leftDrone == 1)
        {
            cout << leftDrone + 1 << " " << rightDrone + 1 << endl;
            cout << "Stopped"; 
            return 0;
        }
        else if (rightDrone - leftDrone <= -1)
        {
            cout << leftDrone + 1 << " " << rightDrone + 1 << endl;
            cout << "Miss"; 
            return 0;
        }

        leftDrone += nums[leftDrone];
        rightDrone -= nums[rightDrone];
    }
    return 0;
}
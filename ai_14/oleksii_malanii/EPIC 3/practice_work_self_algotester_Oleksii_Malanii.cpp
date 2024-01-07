#include <iostream>
using namespace std;
int main () {
    long long cubes[5];
    for (int i = 0; i < 5; i++)
        cin >> cubes[i];
    if (cubes[0] <= 0) {
        cout << "ERROR";
        exit(0);
    }
    for (int i = 1; i < 5; i++)
    {
        if (cubes[i] <= 0)
        {
            cout << "ERROR";
            exit(0);
        }
        if (cubes[i] > cubes[i-1])
        {
            cout << "LOSS";
            exit(0);
        }
    }
    cout << "WIN";
    return 0;
}

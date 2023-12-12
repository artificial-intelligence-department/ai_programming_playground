#include <iostream>
using namespace std;

int main()
{

    long long arr[5];
    for (int k = 0; k < 5; k++)
    {

        cin >> arr[k];
        if (arr[k] <= 0)
        {

            cout << "ERROR" << endl;

            return 0;
        }
    }

    long long previous = arr[0];

    for (int i = 1; i < 5; i++)
    {

        if (arr[i] > previous)
        {
            cout << "LOSS" << endl;
            return 0;
        }
        previous = arr[i];
    }
    cout << "WIN" << endl;

    return 0;
}
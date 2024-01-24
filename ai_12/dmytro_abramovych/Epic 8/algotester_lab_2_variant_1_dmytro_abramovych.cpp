#include <iostream>
#include <algorithm>
using namespace std;

// Algotester Lab 2 Variant 1

int main()
{
    unsigned int cnt;
    cin >> cnt;
    int *arr = new int[cnt];
    for (unsigned int i = 0; i < cnt; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + cnt);

    switch (cnt)
    {
    case 1:
        cout << 0;
        break;
    case 2:
        cout << arr[0];
        break;
    default:
        if (arr[cnt - 1] - arr[1] > arr[cnt - 2] - arr[0])
            cout << arr[cnt - 2] - arr[0];
        else
            cout << arr[cnt - 1] - arr[1];
    }
    return 0;
}
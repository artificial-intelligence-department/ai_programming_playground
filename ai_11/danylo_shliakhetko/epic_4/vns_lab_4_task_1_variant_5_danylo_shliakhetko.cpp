#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n = 20;
    int arr[n];

    int filteredN = 0;

        cout << "----Random Arr----"
         << "\n";

    for (int i = 0; i < n; i++)
    {
        int x = rand();
        arr[i] = x;
        if (arr[i] % 7 != 0)
        {
            filteredN++;
        }
        cout << i + 1 << " - " << arr[i] << "\n";
    }

    cout << "----Filtered Arr----"
         << "\n";

    int filteredArr[filteredN];
    int k = 0;
    int add = *arr;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 7 != 0)
        {
            filteredArr[k] = arr[i];

            // if (arr[k] % 2 == 1)
            // {
            //     int a = *(arr + k);
            //     cout << filteredArr[k] << " --- " << filteredArr[k] << " + " << add << "\n";
            // }

            k++;
        }
    }

    for (int i = 0; i < filteredN; i++)
    {
            if (arr[i] % 2 == 1)
            {
                int a = *(arr + i);
                filteredArr[i] += add;
            }

            cout << i + 1 << " - " << filteredArr[i] << "\n";
    }

    return 0;
}
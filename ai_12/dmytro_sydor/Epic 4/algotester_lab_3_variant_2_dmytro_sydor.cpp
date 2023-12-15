#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    int countUniversal = 0;
    int size1, size2;

    cin >> size1;
    int arr1[size1];
    for (int i = 0; i < size1; i++)
    {
        cin >> arr1[i];
    }

    cin >> size2;
    int arr2[size2];
    for (int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                count++;
                break;
            }
        }
    }

    for (int i = 0; i < size1; i++)
    {
        bool found = false;
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            countUniversal++;
        }
    }
    int size = size1 + size2;
    int totalUnique = size - count;

    cout << count << endl;
    cout << totalUnique << endl;

    return 0;
}

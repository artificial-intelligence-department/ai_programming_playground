


#include <iostream>
using namespace std;

int main()
{
    int size;

    cin >> size;

    int arr[size];
    int i = 0;

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int left = 0;
    int right = size - 1;

    while (true)
    {

        if (left == right)
        {
            cout << left + 1 << " " << right + 1 << endl;
            cout << "Collision" << endl;
            break;
        }
        else if (left > right)
        {
            cout << left + 1 << " " << right + 1 << endl;
            cout << "Miss" << endl;

            break;
        }
        else if (left == right - 1)
        {
            cout << left + 1 << " " << right + 1 << endl;
            cout << "Stopped" << endl;
            break;
        }

        right -= arr[right];
        left += arr[left];
    }

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

const int arrsize = 100;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, k;

    cout << "type array size: ";
    cin >> n;

    cout << "type K: ";
    cin >> k;

    if (k < 1 || k > n)
    {
        cerr << "incorrect K." << endl;
        return 1;
    }

    int arr[arrsize];

    cout << "type array elements:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    rotate(arr, arr + n - k, arr + n);

    cout << "array after left rotate:" << endl;
    printArray(arr, n);

    int maxElement = *max_element(arr, arr + n);
    arr[remove(arr, arr + n, maxElement) - arr] = 0;
    n--;

    cout << "array after deleting max element and right rotate:" << endl;
    printArray(arr, n);

    return 0;
}

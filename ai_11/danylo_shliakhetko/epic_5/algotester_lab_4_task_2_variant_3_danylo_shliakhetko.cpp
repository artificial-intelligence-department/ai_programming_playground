#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int currentElement = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= currentElement)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int currentElementIndex = partition(arr, start, end);

        quickSort(arr, start, currentElementIndex - 1);
        quickSort(arr, currentElementIndex + 1, end);
    }
}

void quickSort(vector<int> &arr)
{
    quickSort(arr, 0, arr.size() - 1);
}

void reverse(vector<int> &arr, int start, int end)
{
    if (start > end)
        return;

    swap(arr[start], arr[end]);
    reverse(arr, start + 1, end - 1);
}

void reverse(vector<int> &arr)
{
    reverse(arr, 0, arr.size() - 1);
}

void removeRepeatableElements(vector<int> &arr)
{
    vector<int> newArr;
    for (int i = 0; i < arr.size(); i++)
    {
    Repeat:
        if (arr[i] == arr[i + 1] && i < arr.size()-1)
        {
            i++;
            goto Repeat;
        }
        newArr.push_back(arr[i]);
    }
    arr = newArr;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr0;
    vector<int> arr1;
    vector<int> arr2;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        if (input % 3 == 0)
        {
            arr0.push_back(input);
        }
        else if (input % 3 == 1)
        {
            arr1.push_back(input);
        }
        else
        {
            arr2.push_back(input);
        }
    }

    quickSort(arr0, 0, arr0.size() - 1);
    quickSort(arr1, 0, arr1.size() - 1);
    reverse(arr1);
    quickSort(arr2, 0, arr2.size() - 1);

    removeRepeatableElements(arr0);
    removeRepeatableElements(arr1);
    removeRepeatableElements(arr2);

    cout << arr0.size() + arr1.size() + arr2.size() << "\n";

    for (int i = 0; i < arr0.size(); i++)
    {
        cout << arr0[i] << " ";
    }
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}
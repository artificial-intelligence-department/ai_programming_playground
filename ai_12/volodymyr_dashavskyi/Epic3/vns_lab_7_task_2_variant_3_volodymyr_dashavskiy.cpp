#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void cyclicShiftLeft(vector<int> &arr)
{
    if (arr.empty() || arr[0] % 2 != 0)
    {
        return;
    }

    int shiftCount = arr[0] % arr.size();
    rotate(arr.begin(), arr.begin() + shiftCount, arr.end());
}

void cyclicShiftRight(vector<int> &arr)
{
    if (arr.empty() || arr.back() % 2 == 0)
    {
        return;
    }

    int shiftCount = arr.back() % arr.size();
    rotate(arr.rbegin(), arr.rbegin() + shiftCount, arr.rend());
}

int main()
{
    vector<int> arr1 = {4, 1, 2, 3, 5};
    cyclicShiftLeft(arr1);

    cout << "The result of cycle shift left: ";
    for (int num1 : arr1)
    {
        cout << num1 << " ";
    }
    cout << endl;

    vector<int> arr2 = {3, 6, 8, 2, 7};
    cyclicShiftRight(arr2);

    cout << "The result of cycle shift right: ";
    for (int num2 : arr2)
    {
        cout << num2 << " ";
    }
    cout << endl;

    return 0;
}
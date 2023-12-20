#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

    sort(arr0.begin(), arr0.end());
    sort(arr1.begin(), arr1.end(), greater<int>());
    sort(arr2.begin(), arr2.end());

    arr0.erase(unique(arr0.begin(), arr0.end()), arr0.end());
    arr1.erase(unique(arr1.begin(), arr1.end()), arr1.end());
    arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

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
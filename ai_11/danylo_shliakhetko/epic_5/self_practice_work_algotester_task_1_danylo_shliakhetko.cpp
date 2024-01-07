#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    auto lastElement = unique(arr.begin(), arr.end());
    arr.erase(lastElement, arr.end());

    k %= arr.size();
    rotate(arr.begin(), arr.begin() + k, arr.end());

    int newN = arr.size();
    cout << newN << "\n";
    for (int i = 0; i < newN; i++)
        cout << arr[i] << " ";

    return 0;
}
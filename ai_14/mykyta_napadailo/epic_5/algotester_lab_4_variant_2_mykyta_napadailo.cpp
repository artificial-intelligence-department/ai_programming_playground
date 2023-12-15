#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) 
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pivotIndex = i + 1;
        QuickSort(arr, low, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, high);
    }
}

void SortDown(vector<int>& arr) 
{
    int n = arr.size() - 1;
    QuickSort(arr, 0, n);
    for (int i = 0; i < n; i++, n--)
    {
        int temp = arr[i];
        arr[i] = arr[n];
        arr[n] = temp;
    }
}

void removeDuplicates(vector<int>& arr) 
{
    int n = arr.size();
    if (n <= 1)
        return;

    int j = 0;
    for (int i = 0; i < n - 1; i++) 
    {
        if (arr[i] != arr[i + 1])
            arr[j++] = arr[i];
    }
    arr[j++] = arr[n - 1];

    arr.erase(arr.begin() + j, arr.end());
}

int main() 
{
    vector<int> v1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        int el;
        cin >> el;
        v1.push_back(el);
    }

    vector<int> remainderZero, remainderOne, remainderTwo;

    for (int i = 0; i < n; i++) 
    {
        if (v1[i] % 3 == 0)
            remainderZero.push_back(v1[i]);
        else if (v1[i] % 3 == 1)
            remainderOne.push_back(v1[i]);
        else
            remainderTwo.push_back(v1[i]);
    }

    QuickSort(remainderZero, 0, remainderZero.size() - 1);
    SortDown(remainderOne);
    QuickSort(remainderTwo, 0, remainderTwo.size() - 1);
    
    removeDuplicates(remainderZero);
    removeDuplicates(remainderTwo);
    removeDuplicates(remainderOne);

    cout << remainderZero.size() + remainderOne.size() + remainderTwo.size() << endl;
    for (auto value : remainderZero)
        cout << value << " ";
    for (auto value : remainderOne)
        cout << value << " ";
    for (auto value : remainderTwo)
        cout << value << " ";

    return 0;
}

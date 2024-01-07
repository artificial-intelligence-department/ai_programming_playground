#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& arr)
{
    for (int num : arr) 
    {
        cout << num << " ";
    }
}

void random(vector<int>& arr, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        arr.push_back(rand() % 100);
    }
}

void del(vector<int>& arr, int k) 
{
    arr.erase(arr.begin() + k - 1);
}

void pluszero(vector<int>& arr) 
{
    int originalSize = arr.size();
    for (int i = 0; i < originalSize; ++i) 
    {
        if (arr[i] % 2 == 0) 
        {
            arr.insert(arr.begin() + i + 1, 0);
        }
    }
}

int main() 
{
    int size;
    cout << "Enter size:" << endl;
    cin >> size;

    vector<int> arr;
    
    cout << "Here is random array:" << endl;
    random(arr, size);
    print(arr);

    int k;
    cout << endl << "Enter K:" << endl;
    cin >> k;

    del(arr, k - 1);
    cout << "Here is array without k-element:" << endl;
    print(arr);

    cout << endl << "Array when added zeros after each even element:" << endl;
    pluszero(arr);
    print(arr);

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void my_sort(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int my_unique(vector<int>& arr) 
{
    int n = arr.size();
    if (n == 0) 
    {
        return 0;
    }

    int index = 0;
    for (int i = 1; i < n; ++i) 
    {
        if (arr[i] != arr[index]) 
        {
            ++index;
            arr[index] = arr[i];
        }
    }

    return index + 1;
}

void my_rotate(vector<int>& arr, int k) 
{
    int n = arr.size();
    k = k % n;
    
    for (int i = 0; i < k / 2; ++i) 
    {
        int temp = arr[i];
        arr[i] = arr[k - i - 1];
        arr[k - i - 1] = temp;
    }

    for (int i = k; i < (k + n) / 2; ++i)
    {
        int temp = arr[i];
        arr[i] = arr[n - i + k - 1];
        arr[n - i + k - 1] = temp;
    }

    for (int i = 0; i < n / 2; ++i) 
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    my_sort(a);

    int uniqueSize = my_unique(a);
    a.resize(uniqueSize);

    my_rotate(a, k);

    cout << a.size() << endl;
    for (int i = 0; i < a.size(); ++i) 
    {
        cout << a[i] << " ";
    }

    return 0;
}

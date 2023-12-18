#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void deleteFirstZero(int*& arr, int& n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == 0) {
            n--;
            int *arr2 = new int[n];
            for (int j = 0; j < n; ++j)
                (j < i) ? arr2[j] = arr[j] : arr2[j] = arr[j + 1];
            delete[] arr;
            arr = arr2;
            break;
        }
}

void insertEven(int*& arr, int &n)
{
    vector<int> inserted;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            inserted.push_back(arr[i]);
            inserted.push_back(arr[i]+2);
        }
        else inserted.push_back(arr[i]);
    }
    int j = inserted.size();
    int* arr2 = new int[j];
    n = j;
    for (int i = 0; i < j; i++)
        arr2[i] = inserted[i];
    delete[] arr;
    arr = arr2;
}

int main() {
    srand(time(nullptr));
    int n, min, max;
    cout << "Enter array size:";
    cin >> n;
    cout << "Enter min rand:";
    cin >> min;
    cout << "Enter max rand:";
    cin >> max;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        a[i] = min + rand() % (max - min + 1);
    }
    cout << "Original array:\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\nModified array:\n";
    deleteFirstZero(a, n);
    insertEven(a,n);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    delete[] a;
    return 0;
}

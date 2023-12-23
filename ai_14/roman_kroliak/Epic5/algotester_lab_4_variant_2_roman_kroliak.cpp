#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& arr, int low, int high, bool ascending = true) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot && ascending) {
            ++i;
            swap(arr[i], arr[j]);
        }
        else if(arr[j] >= pivot && !ascending){
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, bool ascending = true) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, ascending);
        quickSort(arr, low, pivotIndex - 1, ascending);
        quickSort(arr, pivotIndex + 1, high, ascending);
    }
}

void divideArray(int originalArray[], int arraySize, vector<int>& subarray1, vector<int>& subarray2, vector<int>& subarray3) {
    for (int i = 0; i < arraySize; ++i) {
        if (originalArray[i] % 3 == 0) {
            subarray1.push_back(originalArray[i]);
        } else if (originalArray[i] % 3 == 1) {
            subarray2.push_back(originalArray[i]);
        } else {
            subarray3.push_back(originalArray[i]);
        }
    }
}

void removeDuplicates(int arr[], int& size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size;) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < size - 1; ++k) {
                    arr[k] = arr[k + 1];
                }
                --size;
            } else {
                ++j;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> sub1;
    vector<int> sub2;
    vector<int> sub3;
    divideArray(a, n, sub1, sub2, sub3);
    quickSort(sub1, 0, sub1.size()-1);
    quickSort(sub2, 0, sub2.size()-1, false);
    quickSort(sub3, 0, sub3.size()-1);
    vector<int> res;
    res.insert(res.end(), sub1.begin(), sub1.end());
    res.insert(res.end(), sub2.begin(), sub2.end());
    res.insert(res.end(), sub3.begin(), sub3.end());
    for (int i = 0; i < n; i++)
        a[i] = res[i];
    removeDuplicates(a, n);
    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

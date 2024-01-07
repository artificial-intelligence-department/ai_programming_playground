#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void customMerge(vector<int>& arr, int left, int mid, int right, bool reverse) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArray, rightArray;
    for (int i = 0; i < n1; i++)
        leftArray.push_back(arr[left + i]);
    for (int j = 0; j < n2; j++)
        rightArray.push_back(arr[mid + 1 + j]);
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if ((!reverse && leftArray[i] <= rightArray[j]) || (reverse && leftArray[i] >= rightArray[j])) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}
void customMergeSort(vector<int>& arr, int left, int right, bool reverse) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        customMergeSort(arr, left, mid, reverse);
        customMergeSort(arr, mid + 1, right, reverse);
        customMerge(arr, left, mid, right, reverse);
    }
}
vector<int> customMergeArrays(const vector<int>& arr1, const vector<int>& arr2, const vector<int>& arr3) {
    vector<int> result;
    for (int num : arr1) {
        result.push_back(num);
    }
    for (int num : arr2) {
        result.push_back(num);
    }
    for (int num : arr3) {
        result.push_back(num);
    }
    return result;
}
int removeDuplicatesAndGetSize(vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ) {
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
    arr.resize(size);
    return size;
}
int customSorting(vector<int>& arr){
    vector<int> arr0, arr1, arr2;
    for (int num : arr) {
        int remainder = num % 3;
        switch (remainder)
        {
        case 0:
            arr0.push_back(num);
            break;
        case 1:
            arr1.push_back(num);
            break;
        case 2:
            arr2.push_back(num);
            break;
        default:
            break;
        }
    }
    customMergeSort(arr0, 0, arr0.size() - 1, false);
    customMergeSort(arr1, 0, arr1.size() - 1, true);
    customMergeSort(arr2, 0, arr2.size() - 1, false);
    arr = customMergeArrays(arr0, arr1, arr2);
    int size = removeDuplicatesAndGetSize(arr);
    return size;
}
int main(){
    int totalElements;
    vector<int> input;
    cin >> totalElements;
    for(int i = 0; i < totalElements; i++){
        int element; 
        cin >> element;
        input.push_back(element);
    }
    int uniqueSortedSize = customSorting(input);
    cout << uniqueSortedSize << endl;
    for(int i = 0; i < uniqueSortedSize; i++){
        cout << input[i] << " ";
    }
    return 0;
}

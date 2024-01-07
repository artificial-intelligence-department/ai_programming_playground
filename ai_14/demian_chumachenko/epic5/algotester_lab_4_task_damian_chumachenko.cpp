#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, bool reverse) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> Left_arr(n1), Right_arr(n2);

    for (int i = 0; i < n1; i++)
        Left_arr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        Right_arr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if ((!reverse && Left_arr[i] <= Right_arr[j]) || (reverse && Left_arr[i] >= Right_arr[j])) {
            arr[k] = Left_arr[i];
            i++;
        } else {
            arr[k] = Right_arr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = Left_arr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = Right_arr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right, bool reverse) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, reverse);
        mergeSort(arr, mid + 1, right, reverse);

        merge(arr, left, mid, right, reverse);
    }
}

vector<int> mergeArrays(vector<int> arr1, vector<int> arr2, vector<int>& arr3){
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

int removeDuplicates(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; ++k) {
                    arr[k] = arr[k + 1];
                }
                --n;  
            } else {
                ++j; 
            }
        }
    }

    arr.resize(n);

    return n;
}

int sorting(vector<int>& arr){
    std::vector<int> arr0, arr1, arr2;

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

    mergeSort(arr0, 0, arr0.size() - 1, false);
    mergeSort(arr1, 0, arr1.size() - 1, true);
    mergeSort(arr2, 0, arr2.size() - 1, false);
    arr = mergeArrays(arr0, arr1, arr2);
    int n = removeDuplicates(arr);

    return n;
}

int main(){
    int N;
    vector<int> input;

    cin >> N;

    for(int i = 0; i < N; i++){
        int a; 
        cin >> a;
        input.push_back(a);
    }

    int n = sorting(input);

    cout << n << endl;

    for(int i = 0; i < n; i++){
        cout << input[i] << " ";
    }
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& arr);
void mergeSort(vector<int>& arr, int left, int right);
void merge(vector<int>& arr, int left, int mid, int right);

vector<int> unique(const vector<int>& arr);

vector<int> rotate(const vector<int>& arr, int k);

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int &el: arr) cin >> el;

    mergeSort(arr);
    arr = unique(arr);
    arr = rotate(arr, k);

    cout << arr.size() << endl;
    for (int el: arr) cout << el << " ";

    return 0;
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void mergeSort(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

vector<int> unique(const vector<int>& arr) {
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            result.push_back(arr[i]);
        }
    }
    return result;
}

vector<int> rotate(const vector<int>& arr, int k) {
    k %= arr.size();
    if (k == 0) return { arr };

    vector<int> result(arr.size());
    for (int i = k; i < arr.size(); i++) {
        result[i - k] = arr[i];
    }
    for (int i = 0; i < k; i++) {
        result[arr.size() - k + i] = arr[i];
    }

    return result;
}

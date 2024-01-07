#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, bool reverse) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if ((!reverse && L[i] <= R[j]) || (reverse && L[i] >= R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
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

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    auto partition1 = partition(arr.begin(), arr.end(), [](int a) { return a % 3 == 0; });
    auto partition2 = partition(partition1, arr.end(), [](int a) { return a % 3 == 1; });

    mergeSort(arr, 0, distance(arr.begin(), partition1) - 1, false);
    mergeSort(arr, distance(arr.begin(), partition1), distance(arr.begin(), partition2) - 1, true);
    mergeSort(arr, distance(arr.begin(), partition2), n - 1, false);

    int m = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr[m] = arr[i];
            ++m;
        }
    }

    cout << m << endl;
    for (int i = 0; i < m; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Algotester Lab 4 Variant 3

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

void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void reverse(vector<int>::iterator start, vector<int>::iterator end) {
    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }
}

void mergeSort(vector<int>& arr) {
    merge_sort(arr, 0, arr.size() - 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i) cin >> vec[i];

    auto part1 = partition(vec.begin(), vec.end(), [](int a) { return a % 3 == 0; });
    auto part2 = partition(part1, vec.end(), [](int a) { return a % 3 == 1; });

    merge_sort(vec, 0, distance(vec.begin(), part1) - 1);
    merge_sort(vec, distance(vec.begin(), part1), distance(vec.begin(), part2) - 1);
    reverse(part1, part2 - 1);
    merge_sort(vec, distance(vec.begin(), part2), n - 1);

    int m = 0;
    for (int i = 0; i < n; i++)
        if (i == 0 || vec[i] != vec[i - 1]) {
            vec[m] = vec[i];
            m++;
        }

    cout << m << endl;
    for (int i = 0; i < m; ++i)
        cout << vec[i] << " ";

    return 0;
}

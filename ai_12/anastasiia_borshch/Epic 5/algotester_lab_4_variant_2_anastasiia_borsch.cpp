#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> mergeSort(const vector<int>& arr);
vector<int> merge(const vector<int>& left, const vector<int>& right);
vector<int> unique(const vector<int>& arr);
vector<int> rotate(const vector<int>& arr, int k);

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int &el: arr) cin >> el;

    arr = mergeSort(arr);
    arr = unique(arr);
    arr = rotate(arr, k);

    cout << arr.size() << endl;
    for (int el: arr) cout << el << " ";

    return 0;
}

vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

vector<int> mergeSort(const vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
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
    if (k == 0) return arr;

    vector<int> result(arr.size());

    for (int i = k; i < arr.size(); i++) {
        result[i - k] = arr[i];
    }
    for (int i = 0; i < k; i++) {
        result[arr.size() - k + i] = arr[i];
    }

    return result;
}

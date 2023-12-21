#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void removeDuplicates(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
}

void rotateArray(vector<int>& arr, int k) {
    rotate(arr.begin(), arr.begin() + k, arr.end());
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (size_t i = 0; i < N; i++)
        cin >> arr[i];
    removeDuplicates(arr);
    K %= arr.size();
    rotateArray(arr, K);

    cout << arr.size() << endl;
    for (int i : arr)
        cout << i << " ";

    return 0;
}

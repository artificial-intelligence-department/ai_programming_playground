#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> transformArray(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    sort(arr.begin(), arr.end());

    if (k > arr.size()) {
        k = k % arr.size();
    }
    rotate(arr.begin(), arr.begin() + k, arr.end());

    return arr;
}

int main() {
    int n, k;
  
    cin >> n >> k;

    vector<int> arr(n);
   
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> result = transformArray(arr, k);
    cout << result.size() << endl;

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


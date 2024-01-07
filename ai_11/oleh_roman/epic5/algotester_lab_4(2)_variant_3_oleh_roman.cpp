#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    vector<int> arr0, arr1, arr2;
    for (int num : arr) {
        if (num % 3 == 0) {
            arr0.push_back(num);
        } else if (num % 3 == 1) {
            arr1.push_back(num);
        } else {
            arr2.push_back(num);
        }
    }

    sort(arr0.begin(), arr0.end());
    sort(arr1.begin(), arr1.end(), greater<int>());
    sort(arr2.begin(), arr2.end());

    vector<int> result;
    result.insert(result.end(), arr0.begin(), arr0.end());
    result.insert(result.end(), arr1.begin(), arr1.end());
    result.insert(result.end(), arr2.begin(), arr2.end());

    auto anotherArr = unique(result.begin(), result.end());
    result.erase(anotherArr, result.end());

    cout << result.size() << endl;
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

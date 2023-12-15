#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int b) {
    if (a % 3 == b % 3) {
        if (a % 3 == 1) {
            return a > b;
        } else {
            return a < b;
        }
    } else {
        return a % 3 < b % 3;
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), compare);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    cout << arr.size() << endl;
    for (const auto& num : arr) {
        cout << num << ' ' << endl;
    }

    return 0;
}
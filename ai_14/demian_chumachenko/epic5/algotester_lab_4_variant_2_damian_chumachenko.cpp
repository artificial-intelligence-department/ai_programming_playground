#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int>::iterator partition1 = partition(arr.begin(), arr.end(), [](int a) { return a % 3 == 0; });
    vector<int>::iterator partition2 = partition(partition1, arr.end(), [](int a) { return a % 3 == 1; });

    sort(arr.begin(), partition1);
    sort(partition1, partition2, greater<int>());
    sort(partition2, arr.end());

    arr.resize(distance(arr.begin(), unique(arr.begin(), arr.end())));

    cout << arr.size() << endl;
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
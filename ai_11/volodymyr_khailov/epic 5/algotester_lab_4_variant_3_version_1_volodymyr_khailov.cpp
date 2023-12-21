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

    // Розділити масив на три частини за остачею від ділення на 3
    auto partition1 = partition(arr.begin(), arr.end(), [](int a) { return a % 3 == 0; });
    auto partition2 = partition(partition1, arr.end(), [](int a) { return a % 3 == 1; });

    // Сортувати кожну частину окремо
    sort(arr.begin(), partition1);
    sort(partition1, partition2, greater<int>());
    sort(partition2, arr.end());

    // Видалити дублікати
    auto last = unique(arr.begin(), arr.end());
    int m = distance(arr.begin(), last);

    cout << m << endl;
    for (int i = 0; i < m; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}

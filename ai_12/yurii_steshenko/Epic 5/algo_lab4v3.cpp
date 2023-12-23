#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool compare(int a, int b) {
    if (a % 3 == 1 && b % 3 == 1) {
        return a > b; // Спадання для остачі 1
    } else {
        return a < b; // Зростання для остач 0 та 2
    }
}

int main() {
    // Введення кількості чисел
    int N;
    cin >> N;

    // Введення масиву чисел
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Розділення масиву на три частини за остачою від ділення на 3
    auto partitionIt = partition(arr.begin(), arr.end(), [](int x) { return x % 3 == 0; });
    auto partitionIt2 = partition(partitionIt, arr.end(), [](int x) { return x % 3 == 1; });
    partition(partitionIt2, arr.end(), [](int x) { return x % 3 == 2; });

    // Сортування за допомогою компаратора
    sort(arr.begin(), partitionIt);
    sort(partitionIt, partitionIt2, compare);
    sort(partitionIt2, arr.end());

    // Видалення дублікатів
    unordered_set<int> uniqueSet(arr.begin(), arr.end());
    arr.assign(uniqueSet.begin(), uniqueSet.end());

    // Виведення результату
    cout << arr.size() << endl;
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
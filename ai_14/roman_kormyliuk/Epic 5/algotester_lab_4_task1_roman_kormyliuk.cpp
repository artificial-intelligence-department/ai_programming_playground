#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
// Input
    int N, M;
    cin >> N;
    vector<int> array1(N);
    for (int i = 0; i < N; ++i) {
        cin >> array1[i];
    }
    cin >> M;
    vector<int> array2(M);
    for (int i = 0; i < M; ++i) {
        cin >> array2[i];
    }
// Sorting arrays
    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());
// Set operations
    vector<int> result;
// 1. Різниця N-M
    set_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(result));
    cout << result.size() << endl;
    for (const auto& elem : result) {
        cout << elem << " ";
    }
    cout << endl;
    result.clear();
// 2. Різниця M-N
    set_difference(array2.begin(), array2.end(), array1.begin(), array1.end(), back_inserter(result));
    cout << result.size() << endl;
    for (const auto& elem : result) {
        cout << elem << " ";
    }
    cout << endl;
    result.clear();
// 3. Перетин
    set_intersection(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(result));
    cout << result.size() << endl;
    for (const auto& elem : result) {
        cout << elem << " ";
    }
    cout << endl;
    result.clear();
// 4. Об'єднання
    set_union(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(result));
    cout << result.size() << endl;
    for (const auto& elem : result) {
        cout << elem << " ";
    }
    cout << endl;
    result.clear();
// 5. Симетрична різниця
    set_symmetric_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(result));
    cout << result.size() << endl;
    for (const auto& elem : result) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
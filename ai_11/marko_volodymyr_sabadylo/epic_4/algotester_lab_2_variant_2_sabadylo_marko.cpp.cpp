#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    // Введення розмірів масивів
    int N, M;
    cin >> N;

    // Введення  масиву
    vector<int> arr1(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr1[i];
    }

    cin >> M;

    // Введення  масиву
    vector<int> arr2(M);
    for (int i = 0; i < M; ++i) {
        cin >> arr2[i];
    }

    // кількість елементів, які наявні в обох масивах одночасно
    unordered_set<int> set1(arr1.begin(), arr1.end());
    unordered_set<int> set2(arr2.begin(), arr2.end());

    int common_elements = 0;
    for (int element : set1) {
        if (set2.find(element) != set2.end()) {
            common_elements++;
        }
    }

    //  кількість унікальних елементів в масивах
    unordered_set<int> union_set(arr1.begin(), arr1.end());
    union_set.insert(arr2.begin(), arr2.end());

    int unique_elements = union_set.size();


    cout << common_elements << endl;
    cout << unique_elements << endl;

    return 0;
}
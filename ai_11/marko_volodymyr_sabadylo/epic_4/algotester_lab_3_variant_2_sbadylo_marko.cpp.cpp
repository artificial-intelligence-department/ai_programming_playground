#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Введення розмірів та елементів першого масиву
    int N;
    cin >> N;
    vector<int> arrayA(N);
    for (int i = 0; i < N; ++i) {
        cin >> arrayA[i];
    }

    // Введення розмірів та елементів другого масиву
    int M;
    cin >> M;
    vector<int> arrayB(M);
    for (int i = 0; i < M; ++i) {
        cin >> arrayB[i];
    }

    // кількість спільних елементів
    int commonElementsCount = 0;
    for (int i : arrayA) {
        if (find(arrayB.begin(), arrayB.end(), i) != arrayB.end()) {
            commonElementsCount++;
        }
    }

    //  кількість унікальних елементів в обох масивах
    vector<int> combinedArray;
    combinedArray.reserve(arrayA.size() + arrayB.size());
    combinedArray.insert(combinedArray.end(), arrayA.begin(), arrayA.end());
    combinedArray.insert(combinedArray.end(), arrayB.begin(), arrayB.end());

    // Сортування і видалення
    sort(combinedArray.begin(), combinedArray.end());
    combinedArray.erase(unique(combinedArray.begin(), combinedArray.end()), combinedArray.end());


    cout << commonElementsCount << endl;
    cout << combinedArray.size() << endl;

    return 0;
}
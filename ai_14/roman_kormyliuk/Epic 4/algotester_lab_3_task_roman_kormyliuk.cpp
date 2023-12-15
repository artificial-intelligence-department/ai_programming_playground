#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
    // Введення розмірів масивів
    int N, M;
    cout << " ";
    cin >> N;

    // Введення елементів першого масиву
    cout << " ";
    unordered_set<int> setA;
    for (int i = 0; i < N; ++i) {
        int element;
        cin >> element;
        setA.insert(element);
    }

    cout << " ";
    cin >> M;

    // Введення елементів другого масиву
    cout << " ";
    unordered_set<int> setB;
    for (int i = 0; i < M; ++i) {
        int element;
        cin >> element;
        setB.insert(element);
    }

    // Знаходження кількості елементів, які наявні в обох масивах одночасно
    int commonElements = 0;
    for (const auto& element : setA) {
        if (setB.count(element) > 0) {
            commonElements++;
        }
    }

    // Знаходження кількості унікальних елементів в обох масивах
    unordered_set<int> combinedSet = setA;
    combinedSet.insert(setB.begin(), setB.end());

    // Виведення результатів
    cout  << commonElements << endl;
    cout  << combinedSet.size() << endl;

    return 0;
}

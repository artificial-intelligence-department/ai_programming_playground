#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    // Оголошуємо змінні для розмірів двох масивів
    int N, M;

    // Вводимо розмір першого масиву
    cin >> N;

    // Оголошуємо та вводимо елементи першого масиву
    vector<int> firstArray(N);
    for (int i = 0; i < N; ++i) {
        cin >> firstArray[i];
    }

    // Вводимо розмір другого масиву
    cin >> M;

    // Оголошуємо та вводимо елементи другого масиву
    vector<int> secondArray(M);
    for (int i = 0; i < M; ++i) {
        cin >> secondArray[i];
    }

    // Сортуємо елементи обох масивів
    sort(firstArray.begin(), firstArray.end());
    sort(secondArray.begin(), secondArray.end());

    // Оголошуємо вектори для результатів операцій з масивами
    vector<int> difference_N_M, difference_M_N, intersection, union_set, symmetric_difference;

    // Знаходимо різницю між масивами firstArray і secondArray та зберігаємо результат в difference_N_M
    set_difference(firstArray.begin(), firstArray.end(), secondArray.begin(), secondArray.end(), back_inserter(difference_N_M));

    // Знаходимо різницю між масивами secondArray і firstArray та зберігаємо результат в difference_M_N
    set_difference(secondArray.begin(), secondArray.end(), firstArray.begin(), firstArray.end(), back_inserter(difference_M_N));

    // Знаходимо перетин масивів firstArray і secondArray та зберігаємо результат в intersection
    set_intersection(firstArray.begin(), firstArray.end(), secondArray.begin(), secondArray.end(), back_inserter(intersection));

    // Знаходимо об'єднання масивів firstArray і secondArray та зберігаємо результат в union_set
    set_union(firstArray.begin(), firstArray.end(), secondArray.begin(), secondArray.end(), back_inserter(union_set));

    // Знаходимо симетричну різницю масивів firstArray і secondArray та зберігаємо результат в symmetric_difference
    set_symmetric_difference(firstArray.begin(), firstArray.end(), secondArray.begin(), secondArray.end(), back_inserter(symmetric_difference));

    // Виводимо розмір масиву difference_N_M та його елементи
    cout << difference_N_M.size() << "\n";
    for (size_t i = 0; i < difference_N_M.size(); ++i) {
        int num = difference_N_M[i];
        cout << num << " ";
    }
    cout << "\n";

    // Виводимо розмір масиву difference_M_N та його елементи
    cout << difference_M_N.size() << "\n";
    for (size_t i = 0; i < difference_M_N.size(); ++i) {
        int num = difference_M_N[i];
        cout << num << " ";
    }
    cout << "\n";

    // Виводимо розмір масиву intersection та його елементи
    cout << intersection.size() << "\n";
    for (size_t i = 0; i < intersection.size(); ++i) {
        int num = intersection[i];
        cout << num << " ";
    }
    cout << "\n";

    // Виводимо розмір масиву union_set та його елементи
    cout << union_set.size() << "\n";
    for (size_t i = 0; i < union_set.size(); ++i) {
        int num = union_set[i];
        cout << num << " ";
    }
    cout << "\n";

    // Виводимо розмір масиву symmetric_difference та його елементи
    cout << symmetric_difference.size() << "\n";
    for (size_t i = 0; i < symmetric_difference.size(); ++i) {
        int num = symmetric_difference[i];
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Зчитування розмірів та елементів першого вектора
    int N;
    cin >> N;
    vector<int> vec1(N);
    for (int i = 0; i < N; ++i) {
        cin >> vec1[i];
    }

    // Зчитування розмірів та елементів другого вектора
    int M;
    cin >> M;
    vector<int> vec2(M);
    for (int i = 0; i < M; ++i) {
        cin >> vec2[i];
    }

    // Сортування векторів для операцій, які вимагають відсортованих даних
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    // Виконання операцій над векторами
    vector<int> diff1, diff2, intersection, unionVec, symmetricDifference;
    set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(diff1));
    set_difference(vec2.begin(), vec2.end(), vec1.begin(), vec1.end(), back_inserter(diff2));
    set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(intersection));
    set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(unionVec));
    set_symmetric_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(symmetricDifference));

    // Вивід результатів
    cout << diff1.size() << endl;
    for (int num : diff1) {
        cout << num << " ";
    }
    cout << endl;

    cout << diff2.size() << endl;
    for (int num : diff2) {
        cout << num << " ";
    }
    cout << endl;

    cout << intersection.size() << endl;
    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    cout << unionVec.size() << endl;
    for (int num : unionVec) {
        cout << num << " ";
    }
    cout << endl;

    cout << symmetricDifference.size() << endl;
    for (int num : symmetricDifference) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Зчитуємо вхідні дані
    int N;
    cin >> N;

    vector<int> m(N);
    for (int i = 0; i < N; ++i) {
        cin >> m[i];
    }

    int a, b, c;
   cin >> a >> b >> c;

    // Видаляємо числа a, b, c з масиву
    for (int i = 0; i < N; ++i) {
        if (m[i] == a || m[i] == b || m[i] == c) {
            m.erase(m.begin() + i);
            --N;
            --i; // Не забуваємо зменшити індекс, оскільки елемент видаляється
        }
    }

    // Створюємо новий масив сум сусідніх елементів
    vector<int> sums;
    for (int i = 0; i < N - 1; ++i) {
        sums.push_back(m[i] + m[i + 1]);//Отримана сума додається до вектора sums ззаду.
    }

    if (N > 1) {
        std::cout << N - 1 << std::endl;
        for (int sum : sums) {
            std::cout << sum << std::endl;
        }
    } else {
        std::cout << "0\n";
    }

    return 0;
}
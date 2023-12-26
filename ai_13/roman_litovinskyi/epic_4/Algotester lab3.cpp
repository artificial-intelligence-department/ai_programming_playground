#include <iostream>
#include <unordered_set>

int main() {
    int N, M;
    std::cin >> N >> M; // Введення кількості елементів для двох масивів

    std::unordered_set<int> setN, setM; // Створення невпорядкованої множини для кожного з масивів

    // Зчитування елементів першого масиву та занесення їх у множину setN
    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        setN.insert(num);
    }

    // Зчитування елементів другого масиву та занесення їх у множину setM
    for (int i = 0; i < M; ++i) {
        int num;
        std::cin >> num;
        setM.insert(num);
    }

    int commonElements = 0;
    // Підрахунок кількості елементів, які присутні в обох масивах одночасно
    for (int num : setN) {
        if (setM.find(num) != setM.end()) {
            commonElements++;
        }
    }

    // Кількість унікальних елементів у обох масивах разом
    int uniqueElements = setN.size() + setM.size() - commonElements;

    // Виведення результату
    std::cout << commonElements << std::endl; // Виведення кількості спільних елементів
    std::cout << uniqueElements << std::endl; // Виведення кількості унікальних елементів

    return 0;
}

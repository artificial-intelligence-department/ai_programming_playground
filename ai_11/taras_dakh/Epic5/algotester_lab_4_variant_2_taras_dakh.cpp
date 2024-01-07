#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Введення розміру масиву та параметра K
    int size, k;
    std::cin >> size >> k;

    // Введення елементів масиву
    std::vector<int> N(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> N[i];
    }

    // Сортування та видалення дублікатів
    std::sort(N.begin(), N.end());
    auto it = std::unique(N.begin(), N.end());
    N.erase(it, N.end());

    // Обертання масиву на K
    k = (k > N.size()) ? k % N.size() : k;
    std::rotate(N.begin(), N.begin() + k, N.end());

    // Виведення результату
    std::cout << N.size() << std::endl;
    for (const auto &element : N) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}

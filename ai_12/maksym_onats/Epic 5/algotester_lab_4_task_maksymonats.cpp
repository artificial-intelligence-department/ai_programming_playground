#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    // Видалення повторюючихся елементів
    std::sort(a.begin(), a.end());
    auto last = std::unique(a.begin(), a.end());
    a.erase(last, a.end());

    // Обертання масиву на K
    K %= a.size();
    std::rotate(a.begin(), a.begin() + K, a.end());

    // Виведення результату
    std::cout << a.size() << std::endl;
    for (int i : a) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

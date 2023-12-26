#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int sum = 0;
    int coin;

    // Обчислюємо суму і перевіряємо парність
    for (int i = 0; i < n; ++i) {
        std::cin >> coin;
        sum += coin;
    }

    if (sum % 2 == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
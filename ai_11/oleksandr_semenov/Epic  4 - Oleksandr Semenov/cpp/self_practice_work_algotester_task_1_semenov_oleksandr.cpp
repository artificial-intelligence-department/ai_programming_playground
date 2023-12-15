#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    // Перевірка на парність обидвох розмірностей
    if ((n % 2 == 0) || (m % 2 == 0)) {
        std::cout << "Dragon" << std::endl;
    } else {
        std::cout << "Imp" << std::endl;
    }

    return 0;
}

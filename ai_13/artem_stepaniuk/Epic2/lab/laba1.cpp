#include <iostream>

int main() {
    std::cout << "Введіть ваше значення n: ";
    int n;
    std::cin >> n;

    std::cout << "Введіть ваше значення n: ";
    int m;
    std::cin >> m;

    int result1 = n++ * m;

    std::cout << "Результат для n++ * m: " << result1 << std::endl;

    bool result2 = n++ < m;

    std::cout << "Результат для n++ < m: " << (result2 ? "true" : "false") << std::endl;

    bool result3 = m-- > m;

    std::cout << "Результат для m-- > m: " << (result3 ? "true" : "false") << std::endl;

    return 0;
}

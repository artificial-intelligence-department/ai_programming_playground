#include <iostream>
#include <cmath>

int main() {
    
    std::cout << "Введіть значення m: ";
    float m;
    std::cin >> m;

    std::cout << "Введіть значення n: ";
    float n;
    std::cin >> n;

    ++n;

    bool result = m * n < n;

    
    std::cout << "Результат: " << result << std::endl;

    return 0;
}

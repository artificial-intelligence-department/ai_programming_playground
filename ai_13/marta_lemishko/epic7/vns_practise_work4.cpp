#include <iostream>

int main() {
    std::cout << "Число\tКвадрат" << std::endl;

    for (int i = 1; i <= 10; i += 2) {
        std::cout << i << "\t" << i * i << std::endl;
    }

    return 0;
}
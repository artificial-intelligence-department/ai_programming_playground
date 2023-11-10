#include <iostream>

int main() {
    int sides[5];

    for (int i = 0; i < 5; ++i) {
        std::cin >> sides[i];

        if (sides[i] <= 0) {
            std::cout << "ERROR" << std::endl;
            return 0;
        }
    }


    for (int i = 0; i < 4; ++i) {
        if (sides[i] < sides[i + 1]) {
            std::cout << "LOSS";
            return 0;
        }

    }

    std::cout << "WIN" << std::endl;

    return 0;
}


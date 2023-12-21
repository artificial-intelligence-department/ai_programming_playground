#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int sum(const std::vector<int>& values) {
    int result = 0;

    for (size_t i = 0; i < values.size(); i += 2) {
        result += values[i] * values[i + 1];
    }

    return result;
}

int main() {
    srand(time(0));

    std::vector<int> numbers1, numbers2, numbers3;

    std::cout << "generated rows: ";
    for (int i = 0; i < 8; ++i) {
        numbers1.push_back(rand() % 10 + 1);
        std::cout << numbers1.back() << " ";
    }

    int res1 = sum(numbers1);

    std::cout << std::endl << "result: " << res1 << std::endl;

    std::cout << "generated rows: ";
    for (int i = 0; i < 10; ++i) {
        numbers2.push_back(rand() % 10 + 1);
        std::cout << numbers2.back() << " ";
    }

    int res2 = sum(numbers2);

    std::cout << std::endl << "result: " << res2 << std::endl;

    std::cout << "generated rows: ";
    for (int i = 0; i < 12; ++i) {
        numbers3.push_back(rand() % 10 + 1);
        std::cout << numbers3.back() << " ";
    }

    int res3 = sum(numbers3);

    std::cout << std::endl << "result: " << res3 << std::endl;

    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string inputString;
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString); // Зчитування рядка з консолі

    // Фільтруємо цифри з рядка і зберігаємо їх у окремій стрічці
    std::string digits;
    for (char ch : inputString) {
        if (std::isdigit(ch)) {
            digits += ch; // Додаємо цифру до стрічки digits
        }
    }

    // Сортуємо цифри за спаданням
    std::sort(digits.rbegin(), digits.rend()); // Сортування у зворотньому порядку (спадаючому)

    // Замінюємо цифри у вихідному рядку відсортованими за спаданням
    size_t digitIndex = 0;
    for (char &ch : inputString) {
        if (std::isdigit(ch)) {
            ch = digits[digitIndex++]; // Заміна цифри на відсортовану за спаданням
        }
    }

    std::cout << "result: " << inputString << std::endl; // Виведення результату

    return 0;
}


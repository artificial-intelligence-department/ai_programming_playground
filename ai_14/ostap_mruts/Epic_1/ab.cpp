#include <iostream>

int main() {
    int first_number, second_number, sum;
    std::cout << "Enter the first number: ";
    std::cin >> first_number;
    std::cout << "Enter the second number: ";
    std::cin >> second_number;
    sum = first_number + second_number;
    std::cout << "Sum of the two numbers: " << sum << std::endl;
    return 0;
}
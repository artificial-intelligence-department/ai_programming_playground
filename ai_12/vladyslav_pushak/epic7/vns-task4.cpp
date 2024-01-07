#include <iostream>

int main() {
    std::cout << "Enter the number of the first positive even integers to be summed: ";
    int n;
    std::cin >> n;

    int sum = 0;
    for (int i = 2; i <= 2*n; i += 2) {
        sum += i;
    }

    std::cout << "The sum of the first " << n << " positive even integers: " << sum << std::endl;

    return 0;
}

#include <iostream>

int main() {
    int n;
    int sum = 0;

    std::cout << "Enter the number of members of the series: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        int member = 2 * i - 1;
        sum += member;
    }

    std::cout << "The sum of the first " << n << " series members: " << sum << std::endl;

    return 0;
}

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int totalSum = 0;
    for (int i : arr) {
        totalSum += i;
    }

    int currentSum = 0;
    for (int k = 1; k < n; ++k) {
        currentSum += arr[k - 1];
        if (currentSum == totalSum - currentSum) {
            std::cout << "TAK\n";
            return 0;
        }
    }

    std::cout << "NI\n";

    return 0;
}

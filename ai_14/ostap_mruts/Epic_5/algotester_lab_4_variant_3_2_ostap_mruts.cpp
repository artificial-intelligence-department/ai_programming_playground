#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    int totalNumbers;
    scanf("%d", &totalNumbers);

    std::vector<int> inputNumbers(totalNumbers);
    for (int i = 0; i < totalNumbers; ++i) {
        scanf("%d", &inputNumbers[i]);
    }

    std::vector<int> sortedNumbers;
    int countDivisible = 0;

    for (int i = 0; i < totalNumbers; ++i) {
        sortedNumbers.push_back(inputNumbers[i]);

        if (inputNumbers[i] % 3 == 0) {
            countDivisible++;
        }
    }

    std::sort(sortedNumbers.begin(), sortedNumbers.end(), [countDivisible](int a, int b) {
        if (a % 3 == 1 && b % 3 == 1) {
            return a > b;
        }
        return std::make_pair(a % 3, a) < std::make_pair(b % 3, b);
    });

    sortedNumbers.erase(std::unique(sortedNumbers.begin(), sortedNumbers.end()), sortedNumbers.end());

    printf("%zu\n", sortedNumbers.size());
    for (int num : sortedNumbers) {
        printf("%d ", num);
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    // Розділити масив на три частини
    std::vector<int> remainder0, remainder1, remainder2;

    for (int i = 0; i < N; ++i) {
        if (arr[i] % 3 == 0) {
            remainder0.push_back(arr[i]);
        } else if (arr[i] % 3 == 1) {
            remainder1.push_back(arr[i]);
        } else {
            remainder2.push_back(arr[i]);
        }
    }

    // Сортувати за умовою
    std::sort(remainder0.begin(), remainder0.end());
    std::sort(remainder1.begin(), remainder1.end(), std::greater<int>());
    std::sort(remainder2.begin(), remainder2.end());

    // Об'єднати частини
    remainder0.insert(remainder0.end(), remainder1.begin(), remainder1.end());
    remainder0.insert(remainder0.end(), remainder2.begin(), remainder2.end());

    // Видалити дублікати
    remainder0.erase(std::unique(remainder0.begin(), remainder0.end()), remainder0.end());

    // Вивести результат
    int M = remainder0.size();
    std::cout << M << std::endl;

    for (int i = 0; i < M; ++i) {
        std::cout << remainder0[i] << " ";
    }

    return 0;
}


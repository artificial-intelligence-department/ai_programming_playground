#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Зчитуємо кількість чисел у масиві
    int N;
    std::cin >> N;

    // Зчитуємо елементи масиву
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    // Розділяємо масив на три частини за остачею від ділення на 3
     std::vector<int> remainder0, remainder1, remainder2;
    for (int i = 0; i < N; ++i) {
        int remainder = arr[i] % 3;
        if (remainder == 0) {
            remainder0.push_back(arr[i]);
        } else if (remainder == 1) {
            remainder1.push_back(arr[i]);
        } else {
            remainder2.push_back(arr[i]);
        }
    }

    // Сортуємо частини за умовою
    std::sort(remainder0.begin(), remainder0.end());
    std::sort(remainder1.begin(), remainder1.end(), std::greater<int>());
    std::sort(remainder2.begin(), remainder2.end());

    // З'єднуємо частини в один масив
    std::vector<int> result;
    result.insert(result.end(), remainder0.begin(), remainder0.end());
    result.insert(result.end(), remainder1.begin(), remainder1.end());
    result.insert(result.end(), remainder2.begin(), remainder2.end());

    // Видаляємо дублікати
    result.erase(std::unique(result.begin(), result.end()), result.end());

    // Виводимо результат, тільки якщо є зміни
    if (result != arr) {
        int M = result.size();
        std::cout << M << "\n";
        for (int i = 0; i < M; ++i) {
            std::cout << result[i] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

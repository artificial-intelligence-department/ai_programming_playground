#include <iostream>
#include <string>
#include <vector>

int Min(const std::vector<int>& arr) {
    int min = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

size_t Min(const std::string& str) {
    size_t shortest = str.length();
    size_t currentLength = 0;

    for (char c : str) {
        if (c != ' ') {
            ++currentLength;
        } else {
            shortest = std::min(shortest, currentLength);
            currentLength = 0;
        }
    }
    shortest = std::min(shortest, currentLength);
    return shortest;
}

int main() {
    std::vector<int> numbers = {5, 3, 9, 1, 7};
    std::cout << "Мінімальний елемент у масиві: " << Min(numbers) << std::endl;

    std::string text = "The shortest word is";
    std::cout << "Довжина найкоротшого слова: " << Min(text) << std::endl;

    return 0;
}

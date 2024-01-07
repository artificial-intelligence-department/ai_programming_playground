#include <iostream>
#include <vector>
#include <random>

// Функція для створення одновимірного масиву цілих чисел за допомогою генератора випадкових чисел
std::vector<int> generateArray(int size) {
    std::vector<int> arr;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-50, 49);

    for (int i = 0; i < size; ++i) {
        arr.push_back(dis(gen)); // Генеруємо випадкові числа в діапазоні [-50, 49]
    }

    return arr;
}

// Функція для друку масиву
void printArray(const std::vector<int>& arr) {
    std::cout << "Масив:";
    for (int num : arr) {
        std::cout << " " << num;
    }
    std::cout << std::endl;
}
void removeElements(std::vector<int>& arr) {
    std::vector<int> newArr;
    for (int i = 0; i < arr.size(); ++i) {
        if ((i + 1) % 3 != 0) { // Видаляємо елементи, індекси яких кратні 3
            newArr.push_back(arr[i]);
        }
    }
    arr = newArr;
}
// Функція для додавання після кожного від’ємного елемента масиву елементу зі значенням | M[i-1] + 1 |
void addAfterNegative(std::vector<int>& arr) {
    std::vector<int> newArr;
    for (int num : arr) {
        newArr.push_back(num);
        if (num < 0) {
            newArr.push_back(abs(newArr.back() + 1));
        }
    }
    arr = newArr;
}

int main() {
    // Генеруємо масив
    int arraySize = 10; // Вкажіть бажаний розмір масиву
    std::vector<int> myArray = generateArray(arraySize);

    // Виводимо початковий масив
    printArray(myArray);

    // Знищуємо елементи, індекси яких кратні 3
    removeElements(myArray);

    // Виводимо масив після знищення елементів
    printArray(myArray);

    // Додаємо після кожного від’ємного елемента масиву елемент зі значенням | M[i-1] + 1 |
    addAfterNegative(myArray);

    // Виводимо кінцевий масив
    printArray(myArray);

    return 0;
}

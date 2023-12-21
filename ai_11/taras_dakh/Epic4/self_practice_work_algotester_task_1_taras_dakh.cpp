#include <iostream>

// Функція для обчислення суми елементів масиву
int calculateSum(const int* arr, int size, int currentIndex) {
    if (currentIndex < size) {
        // Рекурсивно додаємо поточний елемент та переходимо до наступного
        return arr[currentIndex] + calculateSum(arr, size, currentIndex + 1);
    } else {
        return 0; // Базовий випадок: сума для порожнього масиву - 0
    }
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int* myArray = new int[n]; // Виділяється динамічна пам'ять для масиву цілих чисел розміром n

    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> myArray[i];
    }

    // Викликаємо функцію для обчислення суми елементів масиву
    int sum = calculateSum(myArray, n, 0);

    // Виводимо отриману суму
    std::cout << "Sum of array elements: " << sum << std::endl;

    // Звільнюємо виділену пам'ять
    delete[] myArray;

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Розмір масиву
    const int arraySize = 10;

    // Генератор випадкових чисел
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Випадкові числа
    int myArray[arraySize];
    for (int i = 0; i < arraySize; ++i) {
        myArray[i] = std::rand() % 101;  // Рандомне число від 0 до 100
    }

    // Друк отриманого масив
    std::cout << "Initial array: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    // Знищення останнього елемента, який дорівнює 0
    for (int i = arraySize - 1; i >= 0; --i) {
        if (myArray[i] == 0) {
            myArray[i] = 0; // Знищення елемента, який дорівнює 0
            break;
        }
    }

    // Індекс останнього елемента
    int lastElementIndex = arraySize - 1;

    // Остаточний елемент + елемент зі значенням 100
    myArray[lastElementIndex] = 100;

    // Друк отриманого масиву після внесених змін
    std::cout << "Array after changes: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

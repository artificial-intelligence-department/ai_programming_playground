#include <iostream>
#include <cstdlib> // для використання srand() та rand()
#include <ctime> // для використання time() для ініціалізації генератора випадкових чисел

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int arraySize = 10; // Розмір масиву
    int myArray[arraySize];

    // Ініціалізація генератора випадкових чисел
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Заповнення масиву випадковими числами
    for (int i = 0; i < arraySize; ++i) {
        myArray[i] = std::rand() % 101; // Генеруємо випадкові числа в діапазоні від 0 до 100
    }

    std::cout << "initial array: ";
    printArray(myArray, arraySize);

    // Знищення останнього елемента, який дорівнює 0
    for (int i = arraySize - 1; i >= 0; --i) {
        if (myArray[i] == 0) {
            myArray[i] = 0;
            break;
        }
    }

    // Додавання після елемента масиву з заданим індексом елементу зі значенням 100
    int insertIndex = 3; // Заданий індекс для вставки
    if (insertIndex >= 0 && insertIndex < arraySize) {
        for (int i = arraySize - 1; i > insertIndex; --i) {
            myArray[i] = myArray[i - 1];
        }
        myArray[insertIndex + 1] = 100;
    }

    std::cout << "Array after changes: ";
    printArray(myArray, arraySize);

    return 0;
}

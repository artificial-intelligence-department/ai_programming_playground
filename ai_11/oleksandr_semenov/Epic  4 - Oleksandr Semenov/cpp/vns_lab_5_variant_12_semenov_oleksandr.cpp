#include <iostream>

const int SIZE = 3;  // Розмірність масиву (3x3)

// Функція для пошуку максимального елемента в рядку та циклічного зсуву рядків
void cyclicShift(int arr[][SIZE], int dimension) {
    for (int i = 0; i < dimension; ++i) {
        // Знаходимо максимальний елемент у рядку
        int maxElement = arr[i][0];
        for (int j = 1; j < dimension; ++j) {
            if (arr[i][j] > maxElement) {
                maxElement = arr[i][j];
            }
        }

        // Виконуємо циклічний зсув рядків вправо на кількість позицій, яка дорівнює максимальному елементу у рядку
        int shiftAmount = maxElement % dimension;
        for (int k = 0; k < shiftAmount; ++k) {
            int temp = arr[i][dimension - 1];
            for (int j = dimension - 1; j > 0; --j) {
                arr[i][j] = arr[i][j - 1];
            }
            arr[i][0] = temp;
        }
    }
}

int main() {
    int myArray[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Роздруковуємо початковий двовимірний масив
    std::cout << "Початковий масив:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << myArray[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Викликаємо функцію для циклічного зсуву рядків
    cyclicShift(myArray, SIZE);

    // Роздруковуємо оновлений двовимірний масив
    std::cout << "Оновлений масив після циклічного зсуву:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << myArray[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

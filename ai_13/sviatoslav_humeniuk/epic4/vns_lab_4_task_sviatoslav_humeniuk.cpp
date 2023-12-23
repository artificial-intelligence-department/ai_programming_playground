#include <iostream>
#include <cstdlib> // Для генерації випадкових чисел
#include <ctime> // Для отримання випадкових значень при новому запуску програми
#include <cmath>   

using namespace std;

void randomarray(int arr[], int size) { // Функція для створення ряду випадкових чисел
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 101 - 50; // Задаємо діапазон випадкових чисел від -50 до 50
    }
}

void printarray(int arr[], int size) { // Функція виводу згенерованого ряду
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void condition2(int arr[], int &size) { // Функція видалення кожного елемента, індекс якого кратний 3
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if ((i + 1) % 3 != 0) {
            arr[newSize++] = arr[i];
        }
    }
    size = newSize;
}

void condition1(int arr[], int &size) { // Виконання умови | M[I-1 ]+1|
    int newSize = size;
    for (int i = 0; i < newSize; ++i) {
        if (arr[i] < 0 && i > 0) { 
            int valueToAdd = abs(arr[i - 1]) + 1;
            ++newSize; 
            for (int j = newSize - 1; j > i + 1; --j) {
                arr[j] = arr[j - 1];
            }
            arr[i + 1] = valueToAdd; 
            ++i;
        }
    }
    size = newSize;
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Використовується для ініціалізації генератора випадкових чисел на основі поточного часу

    int size = 25; 
    int array[size];

    randomarray(array, size);

    cout << "orig array: ";
    printarray(array, size);

    condition2(array, size);

    condition1(array, size);

    cout << "new array: ";
    printarray(array, size);

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMinIndex(int arr[], int size) {
    int minIdx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIdx]) {
            minIdx = i;
        }
    }
    return minIdx;
}

int findMaxIndex(int arr[], int size) {
    int maxIdx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

void swapElements(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

float calculateAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static_cast<float>(sum) / size;
}

void removeElementsAboveAverage(int arr[], int& size, float average) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] <= average * 1.1) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    size = newSize;
}

int main() {
    int SIZE = 10;
    int arr[SIZE];
    srand(time(NULL));
    // Заповнення масиву випадковими числами
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }
    // Виведення початкового масиву
    cout << "Initial array:";
    printArray(arr, SIZE);

    // Знаходження індексів мінімального та максимального елементів
    int minIdx = findMinIndex(arr, SIZE);
    int maxIdx = findMaxIndex(arr, SIZE);

    // Поміна місцями мінімального та максимального елементів
    swapElements(arr, minIdx, maxIdx);

    // Виведення масиву після обміну елементів
    cout << "Array after exchange: ";
    printArray(arr, SIZE);

    // Розрахунок середнього значення та видалення елементів, що перевищують його
    float average = calculateAverage(arr, SIZE);
    removeElementsAboveAverage(arr, SIZE, average);

    // Виведення масиву після видалення
    cout << "Array after removing elements: ";
    printArray(arr, SIZE);

    return 0;
}

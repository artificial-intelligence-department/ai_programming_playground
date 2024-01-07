#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void printArray(int arr[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int findMaxElementInRow(int arr[], int size) {
    int maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

void shiftRowsCyclically(int arr[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        int maxElement = findMaxElementInRow(arr[i], COLS);
        int temp[COLS];

        // Зберігаємо останні maxElement елементів рядка в тимчасовий масив
        for (int j = 0; j < maxElement; j++) {
            temp[j] = arr[i][COLS - maxElement + j];
        }

        // Зсуваємо елементи вліво
        for (int j = COLS - 1; j >= maxElement; j--) {
            arr[i][j] = arr[i][j - maxElement];
        }

        // Копіюємо тимчасовий масив на місце зсунутих елементів
        for (int j = 0; j < maxElement; j++) {
            arr[i][j] = temp[j];
        }
    }
}

int main() {
    int arr[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Initial array:" << endl;
    printArray(arr, ROWS);

    shiftRowsCyclically(arr, ROWS);

    cout << "Array after cyclic shift of rows:" << endl;
    printArray(arr, ROWS);

    return 0;
}

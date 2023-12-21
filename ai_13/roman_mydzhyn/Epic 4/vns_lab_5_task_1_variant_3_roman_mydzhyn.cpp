#include <iostream>
using namespace std;

// Функція для обміну рядків масиву
void swapRows(int arr[][3], int row1, int row2, int col) {
    for (int i = 0; i < col; i++) {
        int temp = arr[row1][i];
        arr[row1][i] = arr[row2][i];
        arr[row2][i] = temp;
    }
}

// Функція для сортування масиву за елементами третього стовпця
void sortByColumn(int arr[][3], int rows) {
    for (int i = 1; i < rows; i++) {
        int key = arr[i][2];
        int j = i - 1;


        while (j >= 0 && arr[j][2] > key) {
            swapRows(arr, j, j + 1, 3);
            j = j - 1;
        }
        arr[j + 1][2] = key;
    }
}

int main() {
    int arr[3][3] = { {5, 2, 3}, {1, 6, 4}, {7, 8, 9} };
    int rows = sizeof arr / sizeof arr[0];

    
    sortByColumn(arr, rows);

    // Вивід відсортованого масиву
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

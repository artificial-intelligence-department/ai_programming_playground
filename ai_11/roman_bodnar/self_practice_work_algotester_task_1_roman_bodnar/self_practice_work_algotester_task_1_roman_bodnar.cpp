#include <iostream>
using namespace std;

void sort_columns(int** matrix, int rows, int columns) {
    for (int i = 0; i < columns; i++) {

        int min_index = i;
        for (int j = i + 1; j < rows; j++) {
            if (matrix[j][i] < matrix[min_index][i]) {
                min_index = j;
            }
        }

        if (i != min_index) {
            int temp = matrix[i][i];
            matrix[i][i] = matrix[min_index][i];
            matrix[min_index][i] = temp;
        }
    }
}

int main() {

    int** array = new int*[3];
    for (int i = 0; i < 3; i++) {
        array[i] = new int[5];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            array[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    sort_columns(array, 3, 5);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}

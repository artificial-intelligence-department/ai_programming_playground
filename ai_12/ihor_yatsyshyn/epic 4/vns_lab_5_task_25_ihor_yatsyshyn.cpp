#include <iostream>

void restore(int *array, int rows, int columns);

int main() {
    int rows, columns;

    std::cout << "Enter number of rows: " << std::endl;
    std::cin >> rows;
    std::cout << "Enter number of columns: " << std::endl;
    std::cin >> columns;

    int array[rows * columns];

    for (int i = 0; i < rows * columns; i++) {
        std::cout << "Enter element number " << i + 1 << ": ";
        std::cin >> array[i];
    }

    restore(array, rows, columns);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            std::cout << array[i * columns + j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

void restore(int *array, int rows, int columns) {
    int row, column;
    row = column = 0;

    for(int i = 0; i < rows * columns; i++){
        if(row == 0 || array[i] != array[i - column]) {
            row++;
        }

        array[row * columns + column];

        if(column == columns - 1 || array[i+1] != array[i]) {
            column++;
        }
    }
}
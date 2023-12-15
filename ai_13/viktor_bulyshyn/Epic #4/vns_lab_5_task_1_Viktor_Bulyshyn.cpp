#include <iostream>

using namespace std;

const int S = 3; // S = Розмір

// Функція для обчислення добутку стовпців
int productOfColumns(int matrix[S][S]) {
    int product = 1;

    for (int j = 0; j < 3; j++) {
        // Перевірка умови: перший елемент більший від елементів на діагоналях
        if (matrix[0][j] > matrix[j][j] && matrix[0][j] > matrix[S - 1 - j][j]) {
            // Обчислення добутку елементів стовпця
            for (int k = 0; k < S; k++) {
                product *= matrix[k][j];
            }
        }
    }

    return product;
}

int main() {
    int matrix[S][S] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Виклик функції та виведення результату
    int result = productOfColumns(matrix);
    cout << "result: " << result << endl;

    return 0;
}

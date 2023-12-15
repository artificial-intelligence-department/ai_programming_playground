//Перевіряємо матрицю на ортогональність
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

bool isOrthonormal(const vector<vector<int>>& matrix) { //Створюємо функцію, яка перевірить матрицю на ортогональність
    int size = matrix.size();

    for (int i = 0; i < size; ++i) { //Добуток рядка на самого себе дорівнює 1
        int cond1 = 0;
        for (int j = 0; j < size; ++j) {
            cond1 += matrix[i][j] * matrix[i][j];
        }
        if (cond1 != 1) {
            return false;
        }
    }

    for (int i = 0; i < size; ++i) { //Добуток будь-якої пари рядків дорівнюватиме 0
        for (int j = i + 1; j < size; ++j) {
            int cond2 = 0;
            for (int k = 0; k < size; ++k) {
                cond2 += matrix[i][k] * matrix[j][k];
            }
            if (cond2 != 0) {
                return false;
            }
        }
    }

    return true;
}

int main() { //Створюємо функцію, для вводу розміру та значень матриці
    int size;
    cout << "size ";
    cin >> size;

    vector<vector<int>> matrix(size, vector<int>(size)); //Додаємо двовимірний масив для зберігання елементів матриці
    cout << "values:" <<endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << (isOrthonormal(matrix) ? "matrix is orthonormal" : "matrix is not orthonormal") << endl;

    return 0;
}

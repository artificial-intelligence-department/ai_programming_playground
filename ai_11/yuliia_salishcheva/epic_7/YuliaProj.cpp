#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

double** matrix_values(const int row, const int columns)
{
    double** matrix = new double* [row];

    for (int i = 0; i < row; ++i) {
        matrix[i] = new double[columns];
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = pow(i, j);
        }
    }

    return matrix;
}

void processSortMatrix(double** matrix, const int& row, const int& columns) {
    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < row - 1; ++i) {
            for (int k = 0; k < row - i - 1; ++k) {
                if (matrix[k][j] > matrix[k + 1][j]) {
                    double temp = matrix[k][j];
                    matrix[k][j] = matrix[k + 1][j];
                    matrix[k + 1][j] = temp;
                }
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

double* calculateSums(double** matrix, const int row, const int columns) {
    double* myarray = new double[10];

    for (int i = 0; i < 10; ++i) {
        int column = rand() % columns;
        int sum = 0;
        for (int j = 0; j < 4; ++j) {
            int randomRow = rand() % row;
            sum += matrix[randomRow][column];
        }
        myarray[i] = sum;
    }

    return myarray;
}
bool writetoFile(const string& file1, double* myarray, const int& count)
{
    ofstream file(file1);
    if (file.is_open()) {
        for (int i = 0; i < count; ++i) {
            file << myarray[i] << " ";
        }

        file.close();
        return true;
    }

    return false;
}


double readtoFile(const string& file1)
{
    double product = 1;

    ifstream file(file1);

    if (file.is_open()) {
        double value;
        while (file >> value) {
            product *= value;
        }

        file.close();
    }
    else {
        cout << "Not open!" << endl;
    }

    return product;
}

int main() {
    const int row = 5, columns = 5;
    double** matrix = matrix_values(row, columns);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    double* sums = calculateSums(matrix, row, columns);

    processSortMatrix(matrix, row, columns);
    bool writeResult = writetoFile("output.txt", sums, 10);
    cout << bool(writeResult) << endl;
    for (int i = 0; i < row; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    delete[] sums;

    return 0;
}


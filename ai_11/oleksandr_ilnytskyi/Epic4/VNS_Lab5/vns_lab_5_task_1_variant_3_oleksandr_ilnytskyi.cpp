#include <iostream>
#include <vector>

using namespace std;

struct matrix {
    int rows = 1;
    int columns = 1;
    vector<vector<int>> values;
};

matrix createMatrix () {
    matrix result;
    cout << "Enter number of rows:";
    cin >> result.rows;
    cout << "Enter number of columns:";
    cin >> result.columns;

    result.values.resize(result.rows, vector<int>(result.columns));

    for (int x = 0; x < result.rows; x++) {
        cout << "Enter " << result.columns << " elements for row " << x+1 << ":";
        for (int y = 0; y < result.columns; y++) {
            cin >> result.values[x][y];
        }
    }

    return result;
}

void printMatrix(matrix &Matrix) {
    cout << "-----------" << endl;
    for (int x = 0; x < Matrix.rows; x++) {
        for (int y = 0; y < Matrix.columns; y++) {
            if (y+1 != Matrix.columns) { cout << Matrix.values[x][y] << " "; }
            else { cout << Matrix.values[x][y] << endl; }
        }
    }
    cout << "-----------" << endl;
}

matrix addMatrix(matrix Matrix1, matrix Matrix2) {
    matrix result;

    if (Matrix1.rows == Matrix2.rows && Matrix1.columns == Matrix2.columns) {
        result.rows = Matrix1.rows;
        result.columns = Matrix1.columns;
        result.values.resize(result.rows, vector<int>(result.columns));

        for (int x = 0; x < result.rows; x++) {
            for (int y = 0; y < result.columns; y++) {
                result.values[x][y] = Matrix1.values[x][y] + Matrix2.values[x][y];
            }
        }
    }
    else { cout << "You can't add these Matrices" << endl; }

    return result;
}

void transposeMatrix(matrix &Matrix) {
    matrix result;
    result.rows = Matrix.columns;
    result.columns = Matrix.rows;
    result.values.resize(result.rows, vector<int>(result.columns));

    for (int x = 0; x < Matrix.rows; x++) {
        for (int y = 0; y < Matrix.columns; y++) {
            result.values[y][x] = Matrix.values[x][y];
        }
    }

    Matrix = result;
}

int main() {
    matrix m1 = createMatrix();
    matrix m2 = createMatrix();

    printMatrix(m1);
    printMatrix(m2);
    matrix m3 = addMatrix(m1, m2);
    printMatrix(m3);

    transposeMatrix(m3);
    printMatrix(m3);

    return 0;
}

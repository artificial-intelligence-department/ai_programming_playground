#include <iostream>
#include <vector>
using namespace std;
void matrixs(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2, vector<vector<int>>& resultMatrix){
    int rows = matrix1.size();
    int cols = matrix1[0].size();
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}
void trans(const vector<vector<int>>& originalMatrix, vector<vector<int>>& transposedMatrix){
    int rows = originalMatrix.size();
    int cols = originalMatrix[0].size();
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j){
            transposedMatrix[i][j] = originalMatrix[j][i];
        }
    }
}

int main(){
    vector<vector<int>> matrix1 = {{1, 2, 3}, {6, 5, 4}, {9, 7, 8}};
    vector<vector<int>> matrix2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int rows = matrix1.size();
    int cols = matrix1[0].size();
    vector<vector<int>> resultMatrix(rows, vector<int>(cols, 0));
    vector<vector<int>> transposedMatrix(cols, vector<int>(rows, 0));
    matrixs(matrix1, matrix2, resultMatrix);
    trans(resultMatrix, transposedMatrix);
    cout << "Вихідна матриця:" << endl;
    for (const auto& row : resultMatrix){
        for (int value : row){
            cout << value << " ";
        }
        cout << endl;
    }
    cout << "\nТранспонована матриця:" << endl;
    for (const auto& row : transposedMatrix){
        for (int value : row){
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <ctime>

using namespace std;

void multiply(int matrix[][4], int rows, int cols){
    for (int col = 0; col < cols; col++) {
        bool cond1 = true;
        for(int i = 0, j = 0; i < rows && j < cols; i++, j++){
            if(matrix[0][col]<matrix[i][j]){
                cond1 = false;
            }
        }
        bool cond2 = true;
        for(int i = rows-1, j = 0; i > 0 && j < cols; i--, j++){
            if(matrix[0][col]<matrix[i][j]){
                cond2 = false;
            }
        }
        if (cond1 == true && cond2 == true){
            int multiply = 1;
            for(int row = 0; row < rows; row++){
                multiply *= matrix[row][col];
            }
            cout << multiply << " ";
        } else{
            cout << "nan ";
        }
    }
}

int main(){
    const int rows = 4, cols = 4;
    int matrix[rows][cols];
    srand(time(NULL));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrix[i][j] = rand() % 10;
        }
    }
    cout << "matrix:" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    multiply(matrix, rows, cols);
    return 0;
}
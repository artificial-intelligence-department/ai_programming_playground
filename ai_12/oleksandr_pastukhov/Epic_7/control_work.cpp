#include<iostream>
#include<cmath>


double** Matrix_sort(double** matrix){
        for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 10 - 1; ++i) {
            for (int k = 0; k < 10 - i - 1; ++k) {
                if (matrix[k][j] > matrix[k + 1][j]) {
                    std::swap(matrix[k][j], matrix[k + 1][j]);
                }
            }
        }
    }
    return matrix;
}

void printMatrix(double** matrix) {
    const int rows = 10;
    const int cols = 10;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int** Matrix_sort(int** matrix){
        for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 10 - 1; ++i) {
            for (int k = 0; k < 10 - i - 1; ++k) {
                if (matrix[k][j] < matrix[k + 1][j]) {
                    std::swap(matrix[k][j], matrix[k + 1][j]);
                }
            }
        }
    }
    return matrix;

}

double ElemSum(){

}


double** Matrix(double num_for_matrx){
    double** created_matrix = new double*[10];
    for(int i = 0;i < 10;i++){
        created_matrix[i] = new double[10];
    }

    for(int i = 0;i < 10;i++){
        for(int g = 0;g < 10;g++){
            created_matrix[i][g] = num_for_matrx;
        }
    }
    return created_matrix;
}

int main(){
    using namespace std;

    int m = 2;
    int c =1;
    float x = 1.2;

    double q = sqrt(m* tan(x)+abs(c*sin(x)));
    double** arr_for_doubles = Matrix(q);
//    int** arr_for_int = Matrix(q);

    printMatrix(Matrix_sort(arr_for_doubles));
//    Matrix_sort(arr_for_int);

    return 0;

}
#include <iostream>
#include <math.h>
using namespace std;


const int PR_NUM = 970;

double** create_matrix (int rows, int cols) {
    double** matrix = new double* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double [cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand()/ float RAND_MAX;
        }
    }
    return matrix;
}

double** create_matrix_from_function(int rows, int cols, double (*func)(double)){
    double** matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[cols];
        for (int j = 0; j < cols; j++){
            matrix[i][j] = func(j);
        }
    }
    return matrix;


}
int main (){
const int PR_NUMBER = 970;

    return 0;
}
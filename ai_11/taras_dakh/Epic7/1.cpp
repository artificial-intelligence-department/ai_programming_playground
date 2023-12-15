#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
// Ваш номер пулл реквесту (змініть на свій)
const int pullRequestNumber = 1021;
 double createAndFillDoubleMatrix(){
    double** matrix = new double*[10];
    for(int i=0; i<10; ++i){
           matrix[i] = new double [10];
           for (int j = 0; j<10; ++j){
            matrix[i][j] = sqrt(i+j);
           }
    }
    return matrix;
 }

 int** CreateAndFillIntMatrix(){ //Функція для створення та заповнення матриці з цілими числами
    int** matrix = new int*[10];
        for(int i=0; i<10; ++i){
           matrix[i] = new int [10];
           for (int j = 0; j<10; ++j){
           matrix[i][j] = (i+j)*(i+j)
           }
 }
    return matrix;
 }
  // Перевантажена функція для сортування стовпців матриці з числами з плаваючою крапкою
double** sortColumns(double** matrix, int pullRequestValue) {
    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 9; ++i) {
            for (int k = 0; k < 10 - i - 1; ++k) {
                if (matrix[k][j] > matrix[k + 1][j]) {
                    std::swap(matrix[k][j], matrix[k + 1][j]);
                }
            }
        }
    }
    return matrix;
}

// Перевантажена функція для сортування рядків матриці з цілими числами
int** sortRows(int** matrix, int pullRequestValue) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 10 - j - 1; ++k) {
                if (matrix[i][k] < matrix[i][k + 1]) {
                    std::swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
    return matrix;
}
// Функція для обчислення сум та створення масиву
int* calculateSumsAndCreateArray(double** matrix) {
    static int sums[10];

    for (int j = 0; j < 10; ++j) {
        double sum = 0.0;
        for (int count = 0; count < 4; ++count) {
            int randomIndex = rand() % 10;
            sum += matrix[randomIndex][j];
        }

        // Якщо сума має дробову частину, вона відкидається
        sums[j] = static_cast<int>(sum);
    }

    return sums;
}
int* calculateSumsAndCreateArray(double** matrix){
    static_list sums[10];
    for (int j = 0; j<10; ++j){
        double sum = 0.0;
        for (int count = 0; count <4; ++count){
            int randomIndex = rand()%10;
            sum+=mtrix
            
        }
    }
}

 int main(){
    if (pullRequestNumber %2 ==0){ // Якщо номер парний, створити та вивести матрицю з плавачую крапкою
        double** doubleMatrix = createAndFillDoubleMatrix();
        for(int i=0; i<10; ++i){
           for(int j = 0; j<10; ++j){
                std::cout<< doubleMatrix[i][j]<<std::endl;
           }
    }
    // звільняємо місце
    for (int i = 0; i < 10; ++i) {
            delete[] doubleMatrix[i];
        }
        delete[] floatingPointMatrix;
    } else {
        // Якщо pullRequestNumber не парний
        int** matrix = createAndFillDoubleMatrix();
        // Вивести матрицю з цілими числами
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                std::cout << integerMatrix[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        // Звільнити пам'ять
        for (int i = 0; i < 10; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }


    return 0;
}
 
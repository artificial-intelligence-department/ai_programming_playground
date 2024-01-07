#include <iostream>
#include <fstream>
#include <ctime>
#include<cmath>

using namespace std;

const int PRnumber = 953;

// Функція, яка створює та повертає матрицю розміром 10x10 з числами з плаваючою крапкою
float** generate_float_Matrix() {
    float** matrix = new float*[10];
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new float[10];
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] =(PRnumber/i)*j;  
        }
    }
    return matrix;
}


int** generate_int_Matrix() {
    int** matrix = new int*[10];
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new int[10];
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = sqrt(PRnumber * i * j);
        }
    }
    return matrix;
}
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortMatrix(float** matrix) {
   
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (matrix[j][i] > matrix[j + 1][i]) {
                swap(matrix[j][i], matrix[j + 1][i]);
            }
        }
    }
}
void sortMatrix(int** matrix) {
   
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (matrix[j][i] > matrix[j + 1][i]) {
                swap(matrix[j][i], matrix[j + 1][i]);
            }
        }
    }
}

int main() {
    if (PRnumber % 2 == 0) {
        
        float** floatMatrix = generate_float_Matrix(); //Виклик матриць 10х10
        cout<<**floatMatrix;
        sortMatrix(**floatMatrix);
        cout<<**floatMatrix;
    }
    else
    {
        int** intMatrix = generate_int_Matrix();
        cout<<*intMatrix;
        sortMatrix(**intMatrix);
        cout<<**intMatrix;
        
    }

    return 0;
}

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

double mathFunction(float a, float b, int x) {
    double S = 0.0; //змінна з подвійною точністю
    S = sqrt(x * b / a) + abs(pow(cos(x + b), 3)); //математична операція з використанням бібліотеки cmath
    return S;
}

void createMatrix(int matrix[10][10]){ //оголошено двовимірний масив
    float a = 0.1, b = 0.4;
    for (int i = 0; i < 10; i++){ //використано цикл for
        for (int j = 0; j < 10; j++){
            matrix[i][j] = mathFunction(a, b, i+j);
        }
    }
}

void printMatrix(const int matrix[10][10]) { //створено параметри функції
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void sortMatrixColumns(float matrix[10][10], int a) { //задано кілька параметрів функції
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 10 - j - 1; k++) {
                if (matrix[k][i] > matrix[k + 1][i]) { //використано умовний оператор
                    swap(matrix[k][i], matrix[k + 1][i]);
                }
            }
        }
    }
}

void sortMatrixRows(int matrix[10][10], int pullRequestValue) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 10 - j - 1; k++) {
                if (matrix[i][k] < matrix[i][k + 1]) {
                    swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

void randomSum(int matrix[10][10]) {
    int sum = 0, d;
    for (int i = 0; i < 10; i++) {
        d = rand() % 10;
        sum += matrix[d][i];
    }
    cout << "Random Sum: " << sum << endl;
}

int main(){
    int arr[8]; //одновимірний масив
    int mat[10][10]; //двовимірний масив
    const int a = 1009; //константа під пул реквест

    if(a % 2 != 0){
        createMatrix(mat);
        printMatrix(mat);
        cout << endl;
        randomSum(mat);
    }
}

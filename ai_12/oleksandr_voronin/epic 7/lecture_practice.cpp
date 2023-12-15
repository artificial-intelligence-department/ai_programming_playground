#include <iostream>
#include <cmath>
using namespace std;
//965
//Використано функцію
void MatrixFunc(){
int matrix[10][10];
for (int i=0;i<10;i++){
    for(int j=0;j<10;j++){
       matrix[i][j] = cbrt(i * tan(i)+fabs(i * sin(i)));
       
    }
}
for(int i = 0;i <10;i++){
    for(int j =0;j<10;j++){
        cout << matrix[i][j]<<" ";
    }
    cout << endl;
}
}

void MatrixFunc(int matrix[10][10]){
for (int i= 0;i<10;i++){
    for(int j=0;j<10 -1 -i;j++){
        if (matrix[j][0]< matrix[j+1][0]){
            for(int n;n <j;n++){
                swap (matrix[j][n],matrix[j+1][n]);
            }
        }
    }
}
}

void MatrixFunc(int matrix[10][10], double secondParam) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = cbrt(i * tan(i) + fabs(i * sin(i)));
        }
    }
}


int* CalculateColumnSums(int matrix[10][10]) {
    
    static int columnSums[10];

    for (int col = 0; col < 10; col++) {
        int sum = 0;
        int elementsToTake = min(4, 10);
        for (int i = 0; i < elementsToTake; i++) {
            int randomRow = rand() % 10;
            sum += matrix[randomRow][col];
        }

        if (sum % 1 == 0) {
            columnSums[col] = sum;
        } else {
            columnSums[col] = 0;
        }
    }

    return columnSums;
}



int main (){
    // Мінімум одна цілочисельна змінна
const int X = 965;
int matrix[10][10];
// Мінімум одна дійсна змінна
double secondx=965;
// Мінімум одна дійсний з подвійною точністю змінна
    // Функція MatrixFunc(int matrix[10][10], double secondParam)
    // використовує cbrt, яка повертає значення типу double.
MatrixFunc();
MatrixFunc(matrix);
MatrixFunc(matrix,secondx);


        int* columnSums = CalculateColumnSums(matrix);
     //цикли for
    for (int i = 0; i < 10; i++) {
        cout << columnSums[i] << " ";
    }

    
        

    return 0;
    

}
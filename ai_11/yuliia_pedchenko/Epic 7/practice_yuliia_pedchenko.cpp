// 1. створити констатнту яка дорівнює номеру вашого пулл реквесту в 7-му епіку і якщо вона парна то:
// 	а. написати та викликати функцію, яка створить та поверне матрицю розміром 10*10 і буде заповнена значеннями з певної математичної функції і повертає числа з 
//     плаваючою крапкою
// якщо вона не парна то:
// 	b. викликати функцію яка створить та поверне матрицю розміром 10*10 і буде заповнена значеннями з певної математичної функції і повертає цілі числа
// (Для матриць забороняється використання векторів. Математичну функцію виберіть з одного з завдань з вашої розрахункової. 
// Код напишіть так, що він працюватиме навіть якщо коснтанту змінити на парну чи не парну, тобто якщо ви писали код під цифру 70, а я перепишу під цифру 
// 71, програма мала б запускатись в обох випадках.)

#include <iostream>
#include <cmath>

using namespace std;

int** unpaired(int x) {
    x = 5;
    int a = 1;
    int b = 2;
    int y = 3;
    int** matrix = new int*[10];
    for (int i = 0; i < 10; i++) {
        matrix[i] = new int[10];
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = pow(a, x) + pow(b, sin (y+j*i));
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    return matrix;
}

float** paired(float x) {
    x = 4.99;
    float a = 0.99;
    float b = 2.01;
    float y = 3.5;
    float** matrix = new float*[10];
    for (int i = 0; i < 10; i++) {
        matrix[i] = new float[10];
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = pow(a, x) + pow(b, sin (y+j*i));
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
    return matrix;
}


int** BubbleSort (int** matrix) { 
    
    for (int k = 0; k < 10; k++){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matrix[i][j] > matrix[i][j+1]) {
            swap(matrix[i][j],  matrix[i][j+1]);
            }
        }
    }}
    return matrix;
}

float** BubbleSort (float** matrix) {

    for (int k = 0; k < 10; k++){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matrix[i][j] > matrix[i][j+1]) {
            swap(matrix[i][j],  matrix[i][j+1]);
            }
        }
    }}
    return matrix;
}


int main() {

    int x;
    const int pr = 931;
    if (pr % 2==0) {

        float** matrix = paired(x);
        cout << endl;
        BubbleSort(matrix);
    }

    else {
        int** matrix = unpaired(x);
        cout << endl;
        BubbleSort(unpaired(x));
    }







    return 0;

}
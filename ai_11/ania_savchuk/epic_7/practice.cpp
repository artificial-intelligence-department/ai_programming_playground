#include <iostream>
#include <fstream>
using namespace std;


int** matrix() {
    int** matrix = new int*[10];
    for (int i = 0; i < 10; i++) {
        matrix[i] = new int[10];
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}

// Функція, яка сортує рядки матриці з цілими числами по спаданню методом бульбашки
void sort_rows(int** matrix) {
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

// Функція, яка рахує 10 сум для 3-х або 4-х рандомно взятих елементів у кожному з стовпці
int* sums(int** matrix) {
    int* sums = new int[10];
    for (int i = 0; i < 10; i++) {
        int sum = 0;
        for (int j = 0; j < 3 + rand() % 2; j++) {
            sum += matrix[rand() % 10][i];
        }
        sums[i] = (int)sum;
    }
    return sums;
}

bool create_file(int*sum_arr) {
    ofstream file("practice.txt");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return false;
    }
    for (int i = 0; i < 10; i++) {
        file << sum_arr[i] << " ";
    }
    file.close();
    return true;
}

int main(){
    const int number = 791;
    int** arr = matrix();
    sort_rows(arr);
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cout << arr[i][j] << " ";
        } cout << endl;
    }

    cout << "--------------------------------------------------------" << endl;

    int *sum_arr = sums(arr);
    for (int i = 0; i < 10; i++){
        cout << sum_arr[i] << " ";
    } cout << endl;

    bool result = create_file(sum_arr);
    if (result) {
        cout << "Запис в файл успішно виконано!" << endl;
    } else {
        cout << "Помилка запису в файл!" << endl;
    }
    return 0;
}
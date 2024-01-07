#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int pull_request = 978;
const char name_file[] = "file1.txt";

// Функція для створення та ініціалізації матриці
float** matrix() {
    float** matrix_k = new float*[10];
    for (int i = 0; i < 10; i++) {
        matrix_k[i] = new float[10];
        for (int j = 0; j < 10; ++j) {
            matrix_k[i][j] = pull_request * pull_request;
        }
    }
    return matrix_k;
}

// Функція для обчислення сум стовпців матриці
int* calcSums(float** matrix_k) {
    int* sums = new int[10];
    srand(time(nullptr));

    for (int i = 0; i < 10; i++) {
        int sum = 0;
        for (int j = 0; j < 4; ++j) {
            int randRow = rand() % 10;
            sum += matrix_k[randRow][i];
        }
        sums[i] = sum;
    }
    return sums;
}

// Функція для запису масиву у файл
bool arrayToFile(const int* array) {
    ofstream outfile(name_file);

    if (outfile.is_open()) {
        for (int i = 0; i < 10; ++i) {
            outfile << array[i] << " ";
        }
        outfile.close();
        return true;
    } else {
        return false;
    }
}

// Функція для обчислення добутку чисел з файлу
int calcProductFromFile() {
    ifstream inputFile(name_file);
    int product = 1;

    if (inputFile.is_open()) {
        int value;
        while (inputFile >> value) {
            product *= value;
        }
        inputFile.close();
    }
    cout << "Значення в файлі: " << product << endl;
    return product;
}

// Функція для видалення файлу
void delFile() {
    if (remove(name_file) == 0) {
        cout << "Файл видалений успішно" << endl;
    } else {
        cout << "Помилка під час видалення файлу" << endl;
    }
}

int main() {
    // Створення матриці та обчислення сум стовпців
    float** matrix_k = matrix();
    int* sums = calcSums(matrix_k);

    // Виведення сум у консоль
    cout << "Суми стовпців: ";
    for (int i = 0; i < 10; ++i) {
        cout << sums[i]
return 0;
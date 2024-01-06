#include <iostream>
#include <cmath>
#include <fstream>
#include <random>
#include <ctime> 
using namespace std;

float** Omatrix() {
    float** mas = new float*[10];
    for (int i = 0; i < 10; i++) {
        mas[i] = new float[10];
        for (int j = 0; j < 10; j++) {
            mas[i][j] = pow(1.1, (i + 1) * (j + 1));
        }
    }
    return mas;
}

int** Imatrix() {
    int** mas = new int*[10];
    for (int i = 0; i < 10; i++) {
        mas[i] = new int[10];
        for (int j = 0; j < 10; j++) {
            mas[i][j] = pow(2, i + j); // в коді використано математичні операції та математичні функції
        }
    }
    return mas;
}

void Osort(float**& mas, float num) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9 - j; k++) {
                if (mas[i][k] > mas[i][k + 1]) {
                    float temp = mas[i][k];  // в коді використана як мінімум одна дійсна змінна
                    mas[i][k] = mas[i][k + 1];
                    mas[i][k + 1] = temp;
                }
            }
        }
    }
}

void Isort(int**& mas, int num) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9 - j; k++) {
                if (mas[i][k] < mas[i][k + 1]) {
                    int temp = mas[i][k];
                    mas[i][k] = mas[i][k + 1];
                    mas[i][k + 1] = temp;
                }
            }
        }
    }
}

void createmas(int** matrix, int mas[10]) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 9);

    for (int i = 0; i < 10; i++) {
        int randomRow = dis(gen); // в коді використана як мінімум одна цілочисельна змінна
        mas[i] = matrix[randomRow][i];
    }
}

void fill(int mas[10]) {
    ofstream file;
    file.open("C:/Users/Marko/Desktop/Study/Programming/Epic7/test.txt", ios_base::app);

    for (int i = 0; i < 10; i++) {
        file << mas[i] << " "; // в коді використано функції роботи з файлами, для того, щоб записати у файл
    }
    file << endl;

    file.close();
}

void cinfile(int mas[10]) { // в коді використано параметри та аргументи функції
    ifstream file;
    file.open("C:/Users/Marko/Desktop/Study/Programming/Epic7/test.txt", ios::in);

    if (!file.is_open()) { 
        cout << "Error opening the file!" << endl; 
        return;
    }

    double d = 1; // в коді використана як мінімум одна дійсний з подвійною точністю змінна
    for (int i = 0; i < 10; i++) {
        double temp;
        if (file >> temp) { // в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
            d *= temp;
        } else {
            cout << "Error reading from the file!" << endl;
            break;
        }
    }

    cout << endl << "Product of values: " << d;

    file.close();
}

void deletefile(){
    if (remove("C:/Users/Marko/Desktop/Study/Programming/Epic7/test.txt") != 0) {
        cout << endl << "Error deleting the file!" << endl;
    } else {
        cout << endl << "File deleted successfully." << endl;
    }
}

int main() {
    const int pr = 857;  // в коді використана як мінімум одна цілочисельна константа
    float** Oarray; // в коді використаний двовимірний масив 
    int** Iarray; 
    int mas[10];  // в коді використаний одновимірний масив 

    if (pr % 2 == 0) {  // в коді використані умовні оператори та розгалуження
        Oarray = Omatrix();
        Osort(Oarray, float(pr) * 1.1);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf("%7.2f   ", Oarray[i][j]);
            }
            cout << endl; // в коді використано оператори виведення та введення даних
        }
    } else {
        Iarray = Imatrix();
        Isort(Iarray, pr);
        for (int i = 0; i < 10; i++) { // в коді використаний for цикл
            for (int j = 0; j < 10; j++) {
                printf("%7.2d   ", Iarray[i][j]);
            }
            cout << endl;
        }
        createmas(Iarray, mas);
        cout << endl << endl;
        for (int i = 0; i < 10; i++) {
            printf("%7.2d   ", mas[i]);
        }
        fill(mas);
        cinfile(mas);
        deletefile();
    }

    // Cleanup
    for (int i = 0; i < 10; i++) {
        delete[] Oarray[i];
    }
    delete[] Oarray;

    for (int i = 0; i < 10; i++) {
        delete[] Iarray[i];
    }
    delete[] Iarray;

    return 0;
}

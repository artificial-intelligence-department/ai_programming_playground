#include<bits/stdc++.h> 
using namespace std;

int func(int l, int x) {
    return l = sqrt(pow(8, 2) + pow((2 * x - x), 2)); // Математичні 
}

void bubbleSortRow(double row[], int size) { // Задаємо параметри функції; Перевантаження
    for (int i = 0; i < size - 1; ++i) { // Цикл for
        for (int j = 0; j < size - i - 1; ++j) {
            if (row[j] < row[j + 1]) { // Умова
                swap(row[j], row[j + 1]);
            }
        }
    }
}

void sortRowsDescending(double array[10][10]) {
    for (int i = 0; i < 10; ++i) {        
        bubbleSortRow(array[i], 10);
    }
}

void fillarr(double array[10][10], int start, int end) {
    int step = (end - start) / (10 * 10);
    int x = start;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            array[i][j] = func(8, x);
            x += step;
        }
    }
}

void calculateSums(double matrix[10][10]) {
    double sums[10] = {0}; // Одновимірний масив

    for (int j = 0; j < 10; ++j) {
        for (int k = 0; k < 3; ++k) {
            int i = rand() % 10;
            sums[j] += matrix[i][j];
        }
    }

    cout << "Sums of 3 random elements in each column:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << sums[i] << " ";
    }
    cout << endl;
}

bool writeToFile(const double matrix[10][10], const string& filename) { // Використано константи; Функція роботи з файлми
    ofstream outputFile(filename); 

    if (!outputFile.is_open()) {
        cout << "Error" << filename << endl;
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            outputFile << matrix[i][j] << " ";
        }
        outputFile << endl;
    }

    outputFile.close();
    return true;
}

double calculateProductFromFile(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Error" << filename << endl;
        return 0.0;
    }

    double product = 1.0;
    double element;

    while (inputFile >> element) {
        product *= element;
    }

    inputFile.close();
    return product;
}

bool deleteFile(const string& filename) {
    if (remove(filename.c_str()) != 0) {
        cout << "Error" << filename << endl;
        return false;
    } else {
        cout << filename << " deleted successfully." << endl;
        return true;
    }
}

int main() {
    double arr[10][10]; //Задаємо двовимірний масив

    fillarr(arr, 0, 100);

    sortRowsDescending(arr);

    cout << "Sorted Matrix:" << endl; // Оператор виведення
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    calculateSums(arr);

    bool writeSuccess = writeToFile(arr, "F1.txt");

    cout << "Writing to file successful: " << (writeSuccess ? "true" : "false") << endl;

    double product = calculateProductFromFile("F1.txt");

    cout << "Product of elements in the file: " << product << endl;

    bool deleteSuccess = deleteFile("F1.txt");

    cout << "Deleting file successful: " << (deleteSuccess ? "true" : "false") << endl;

    return 0;
}
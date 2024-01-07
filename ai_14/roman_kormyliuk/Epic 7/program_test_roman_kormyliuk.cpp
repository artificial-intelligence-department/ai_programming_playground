#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
const int CONSTANT = 864;  // цілочисельна константа

float mathematicalFunction() { // дійсна змінна
    return 0.0;
}
float** createAndFillMatrix() { // двовимірний масив
    int rows = 10, cols = 10;
    float** matrix = new float*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new float[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = mathematicalFunction();
        }
    }
    return matrix;
}


void sortMatrixColumns(float** matrix) {
    for (int j = 0; j < 10; ++j) { // for цикл
        for (int i = 0; i < 9; ++i) {
            for (int k = 0; k < 9 - i; ++k) {
                if (matrix[k][j] > matrix[k + 1][j]) {  // умовний оператор
                    float temp = matrix[k][j];
                    matrix[k][j] = matrix[k + 1][j];
                    matrix[k + 1][j] = temp;
                }
            }
        }
    }
}
int* calculateSums(float** matrix) {
    srand(static_cast<unsigned>(time(0))); 
    int* sums = new int[10];  // цілочисельний масив
    for (int j = 0; j < 10; ++j) {
        float sum = 0.0;
        for (int i = 0; i < 4; ++i) {
            int randomRow = rand() % 10; // рандомне обрання елементів масиву
            sum += matrix[randomRow][j];
        }
        sums[j] = static_cast<int>(sum);  // використання математичних операцій
    }
    return sums;
}
bool writeArrayToFile(int* array) { 
    ofstream outputFile("FILE"); // функції роботи з файлами, для запису у файл
    if (outputFile.is_open()) {
        for (int i = 0; i < 10; ++i) {
            outputFile << array[i] << " ";
        }
        outputFile.close();
        return true;
    }
    return false;
}
int calculateProductFromFile() {
    int product = 1;
    ifstream inputFile("FILE");  // функції роботи з файлами, для зчитування з файлу
    if (inputFile.is_open()) {
        int value;
        while (inputFile >> value) {
            product *= value;
        }
        inputFile.close();
    }
    cout << "Product from file: " << product << endl;  // оператор виведення даних
    return product;
}
void deleteFile() { // видалення файлу
    if (remove("FILE") == 0) {
        cout << "File deleted successfully." << endl;
    } else {
        cout << "Error deleting file." << endl;
} 







return 0
}
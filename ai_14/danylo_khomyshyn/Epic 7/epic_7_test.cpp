#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

const int pr_number = 987;
const int matrixSize = 10;
const int a = 70; //Вимога: в коді використана як мінімум одна цілочисельна константа
float b = 1.4; //Вимога: в коді використана як мінімум одна дійсна змінна 
float x = 8.2; //Вимога: в коді використана як мінімум одна дійсний з подвійною точністю змінна
const string outputFile = "output.txt";

int mathFunction(int i, int j) {
    return i * j + pow(sin(pow(a, 2)), 3) - cbrt(x / b);
}

float mathFunction(float i, float j) { //Вимога: в коді використано перевантаження функції
    return i * j + pow(sin(pow(a, 2)), 3) - cbrt(x / b);;
}

void sortColumns(float matrix[matrixSize][matrixSize], float value) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize - 1; ++j) {
            if (matrix[0][j] > matrix[0][j + 1]) {
                for (int k = 0; k < matrixSize; ++k) {
                    swap(matrix[k][j], matrix[k][j + 1]);
                }
            }
        }
    }

    cout << "Sorted Columns Matrix:" << endl;
    int zminna_while = 0;
    while (zminna_while < matrixSize) { //Вимога: в коді використаний while цикл
        for (int j = 0; j < matrixSize; ++j) {
            cout << matrix[zminna_while][j] << " "; //Вимога: в коді використаний двовимірний масив
        }
        cout << endl;
        zminna_while++;
    }
}

void sortRows(int matrix[matrixSize][matrixSize], int value) {
    for (int i = 0; i < matrixSize; ++i) { //Вимога:  в коді використаний for цикл
        for (int j = 0; j < matrixSize - 1; ++j) {
            if (matrix[i][0] < matrix[i + 1][0]) {
                for (int k = 0; k < matrixSize; ++k) {
                    swap(matrix[i][k], matrix[i + 1][k]);
                }
            }
        }
    }

    cout << "Sorted Rows Matrix:" << endl;
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int* calculateSums(float matrix[matrixSize][matrixSize]) {
    static int sums[10];

    srand(time(0));

    for (int i = 0; i < matrixSize; ++i) {
        int sum = 0;
        for (int j = 0; j < 3; ++j) {
            int randomRow = rand() % matrixSize;
            sum += static_cast<int>(matrix[randomRow][i]);
        }
        sums[i] = sum;
    }

    return sums;
}

bool writeToFile(const int* array, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {  //Вимога: в коді використані умовні оператори та розгалуження
        cerr << "Unable to open file: " << filename << endl;
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        file << array[i] << " ";
    }

    file.close();
    return true;
}

int calculateProductFromFile() {
    ifstream file(outputFile);

    if (!file.is_open()) {
        cerr << "Unable to open file: " << outputFile << endl;
        return 0;
    }

    int product = 1;
    int value; //Вимога: в коді використана як мінімум одна цілочисельна змінна

    while (file >> value) {
        product *= value;
    }

    file.close();
    return product;
}

bool deleteFile(const string& filename) {
    if (remove(filename.c_str()) != 0) {
        cerr << "Error deleting file: " << filename << endl;
        return false;
    } else {
        cout << "File deleted successfully: " << filename << endl;
        return true;
    }
}

void mainFunction() {
    float value;

    float floatMatrix[matrixSize][matrixSize];
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            floatMatrix[i][j] = mathFunction(i, j);
            cout << floatMatrix[i][j] << " ";
        }
        cout << endl;
    }

    sortColumns(floatMatrix, value);

    int* sums = calculateSums(floatMatrix);

    cout << "Calculated Sums:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << sums[i] << " ";
    }
    cout << endl;

    int intMatrix[matrixSize][matrixSize];
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            intMatrix[i][j] = mathFunction(i, j);
            cout << intMatrix[i][j] << " ";
        }
        cout << endl;
    }

    sortRows(intMatrix, value);

    if (writeToFile(sums, outputFile)) {
        cout << "Values successfully written to file." << endl; //Вимога: в коді використано функції роботи з файлами, для того, щоб записати у файл, в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
    } else {
        cerr << "Failed to write values to file." << endl;
    }

    int product = calculateProductFromFile();

    cout << "Product of values in the file: " << product << endl;

    deleteFile(outputFile);

    
}

int main() {
    mainFunction();


    return 0;
}

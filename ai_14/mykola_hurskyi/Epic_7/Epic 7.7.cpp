#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>

const int CONSTANT_VALUE = 1030;
const char FILE_NAME[] = "output_file.txt";

void generateMatrix(float**& matrix, bool floatingPoint) {
    matrix = new float*[10];

    for (int i = 0; i < 10; ++i) {
        matrix[i] = new float[10];
        for (int j = 0; j < 10; ++j) {
            float value = static_cast<float>(std::sin(i + j + CONSTANT_VALUE));
            matrix[i][j] = floatingPoint ? value : static_cast<int>(value);
        }
    }
}

void sortColumns(float** matrix) {
    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 9; ++i) {
            for (int k = 0; k < 10 - i - 1; ++k) {
                if (matrix[k][j] > matrix[k + 1][j]) {
                    std::swap(matrix[k][j], matrix[k + 1][j]);
                }
            }
        }
    }
}

void sortRows(float** matrix) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 10 - j - 1; ++k) {
                if (matrix[i][k] < matrix[i][k + 1]) {
                    std::swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

int* calculateSums(float** matrix) {
    int* sums = new int[10];
    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int j = 0; j < 10; ++j) {
        int sum = 0;
        for (int i = 0; i < 3; ++i) {
            int randomIndex = std::rand() % 10;
            sum += static_cast<int>(matrix[randomIndex][j]);
        }
        sums[j] = sum;
    }

    return sums;
}

bool writeToFile(int* array) {
    std::ofstream outFile(FILE_NAME);

    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        outFile << array[i] << "\n";
    }

    outFile.close();
    return true;
}

int calculateProductFromFile() {
    std::ifstream inFile(FILE_NAME);
    int product = 1;

    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading." << std::endl;
        return 0;
    }

    int value;
    while (inFile >> value) {
        product *= value;
    }

    inFile.close();
    return product;
}

void deleteFile() {
    if (std::remove(FILE_NAME) != 0) {
        std::cerr << "Error deleting file." << std::endl;
    } else {
        std::cout << "File deleted successfully." << std::endl;
    }
}

int main() {
    float** matrix;
    bool isFloatingPoint = CONSTANT_VALUE % 2 != 0;

    generateMatrix(matrix, isFloatingPoint);

    if (isFloatingPoint) {
        sortColumns(matrix);
    } else {
        sortRows(matrix);
    }

    int* sums = calculateSums(matrix);

    bool writeSuccess = writeToFile(sums);

    if (writeSuccess) {
        int product = calculateProductFromFile();
        std::cout << "Product of values in the file: " << product << std::endl;

        deleteFile();
    }
    for (int i = 0; i < 10; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    delete[] sums;

    return 0;
}
